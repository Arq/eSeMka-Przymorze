#pragma once

#include "esphome.h"
#include "driver/i2c_slave.h"
#include <stdio.h>
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

/* 
Project: dabus-i2c-slave  -  ESPHome Custom Component
Author: Arkadiusz Hahn (arkadiusz.Hahn@gmail.com)
Created: 2025-10-05
Compiler options: esp-idf,  SLAVE_DRIVER_VERSION_2

Description: 
This component emulates 64-256 bits simple i2c io expander.
The host application can read and write a fixed number of bytes 
corresponding to the states of binary outputs and inputs.
*/


// Use main loop() or separate xTask 
#define USE_I2C_SLAVE_TASK
#define PIN_NUMBER_IN_BYTES 8   //8 bytes x 8 bits = 64 pins




// ! [Updated examples of new I2C master/slave driver for IDF 5.2.x... - ESP32 Forum](https://esp32.com/viewtopic.php?t=38872)
//[ESP32 I2C Master and Slave Communication (Arduino) | Random Nerd Tutorials](https://randomnerdtutorials.com/esp32-i2c-master-slave-arduino/)
//[Arduino I2C Slave [Tutorial & Example Code]](https://deepbluembedded.com/arduino-i2c-slave/)
//[Inter-Integrated Circuit (I2C) - ESP32 - — ESP-IDF Programming Guide v5.5.1 documentation](https://docs.espressif.com/projects/esp-idf/en/v5.5.1/esp32/api-reference/peripherals/i2c.html)

/*
// Example esphome configuration 
```
esp32:
  board: wemos_d1_mini32
framework:
    type: esp-idf
    sdkconfig_options:
      CONFIG_I2C_ENABLE_SLAVE_DRIVER_VERSION_2: y
      CONFIG_I2C_ISR_IRAM_SAFE: n
```	  
*/

class DABusI2CSlave ;
#define RECEIVE_BUF_DEPTH 32   //not less than  PIN_NUMBER_IN_BYTES
#define SEND_BUF_DEPTH 32



typedef struct {
    QueueHandle_t event_queue;
    uint8_t rx_data[RECEIVE_BUF_DEPTH];
	uint16_t rx_data_len;
    i2c_slave_dev_handle_t i2cDev;
	DABusI2CSlave *instance;
	
	uint8_t pin_number_in_bytes;
    uint8_t tx_data[SEND_BUF_DEPTH];
	uint16_t tx_data_len;
	
} i2c_slave_context_t;

typedef enum {
    I2C_SLAVE_EVT_RX,
    I2C_SLAVE_EVT_TX
} i2c_slave_event_t;



class DABusI2CSlave : public Component {
  public:
     static const uint32_t send_buf_depth = SEND_BUF_DEPTH;
	 static const uint32_t receive_buf_depth = RECEIVE_BUF_DEPTH;
  
	DABusI2CSlave(uint8_t address,uint8_t sdaPin,uint8_t sclPin,uint8_t *data_out_buf,uint8_t buflen,sensor::Sensor *request_notifysensor,text_sensor::TextSensor *data_in_text_sensor) {
	  
	  this->_address =  address;
	  this->_sdaPin = (gpio_num_t) sdaPin;
	  this->_sclPin = (gpio_num_t) sclPin;
	  this->_buf= data_out_buf;
	  this->_buflen= buflen;
	  this->_request_notify=request_notifysensor;
	  this->_text_sensor = data_in_text_sensor;
	
	}

    ~DABusI2CSlave() {
		if(context.i2cDev != nullptr) {
			i2c_del_slave_device(context.i2cDev);	
		}
	} 	

/*
	void receiveProcedure(uint8_t * buffer, uint32_t length) {
	  ESP_LOGI("DABusI2CSlave", "received data length: %d",length);
	  
	  int index = 0;
      char message[32];
	  
	  
	  while ((index < length)&& (index<31)) {
	      message[index] = buffer[index];
	     index++;
	  }
	  message[index] = '\0';  // String terminator

	  if (index > 0) {
		for(uint8_t i=0;i<strlen(message) ;i++) {
			message[i] &= 0x7F;
		}	
		ESP_LOGI("DABusI2CSlave", "Received text message: %s", message);
		
		if (this->_text_sensor != nullptr) {
		 // this->_text_sensor->publish_state(message);  // Publishes the data 
		} else {
		  ESP_LOGW("DABusI2CSlave", "No TextSensor defined");
		}
	  }
	}

*/	

	
    // Prepare a callback function
	//static IRAM_ATTR bool
	static IRAM_ATTR bool i2cSlaveReceiveStatic(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_rx_done_event_data_t *evt_data, void *arg)
	{
	   i2c_slave_context_t *context = (i2c_slave_context_t *)arg;
	   uint16_t length = evt_data->length;
	   uint16_t index = context->rx_data_len;
	   
	   if (context->pin_number_in_bytes==0) {
		   context->pin_number_in_bytes = PIN_NUMBER_IN_BYTES;
		   //context->pin_number_in_bytes=length;   // initialize number of pins in bytes of the component 
	   }
	   
	   for (uint16_t i=0;i<length;i++) {
	      context->rx_data[index++] = evt_data->buffer[i];
	   }
	   context->rx_data_len=index;
	   i2c_slave_event_t evt = I2C_SLAVE_EVT_TX;
	   BaseType_t high_task_wakeup = pdFALSE;
	   xQueueSendFromISR(context->event_queue, &evt, &high_task_wakeup);
       return high_task_wakeup == pdTRUE;		
	}
    
    // request Callback
	static IRAM_ATTR bool i2cSlaveRequestStatic(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_request_event_data_t *evt_data, void *arg)
	{
	   i2c_slave_context_t *context = (i2c_slave_context_t *)arg;
	   i2c_slave_event_t evt = I2C_SLAVE_EVT_RX;
	   BaseType_t high_task_wakeup = pdFALSE;
	   xQueueSendFromISR(context->event_queue, &evt, &high_task_wakeup);
       return high_task_wakeup == pdTRUE;
	}


	void setup() override {
	  //ESP_LOGW("DABusI2CSlave", "Setup i2c slave controller");
	  // Initialize I2C in slave mode
	  // SDA  GPIO16  pin 31
	  // SCL  GPIO17  pin 29	
	  
	 
	  // Initialize i2c slave device controller using esp-idf
	  i2c_slave_config_t i2c_slv_config = {
		.i2c_port = -1, // I2C_SLAVE_NUM,			//-1 for auto selecting 
		.sda_io_num = _sdaPin,   			//I2C_SLAVE_SDA_IO,
		.scl_io_num = _sclPin,				// I2C_SLAVE_SCL_IO,
		.clk_source = I2C_CLK_SRC_DEFAULT,
		.send_buf_depth = send_buf_depth,
		.receive_buf_depth = receive_buf_depth,   //tylko version_2
		.slave_addr = _address,    			//ESP_SLAVE_ADDR,
		.addr_bit_len =  I2C_ADDR_BIT_LEN_7,
		.intr_priority = 3,   //1 - dzia³a w ver 1
		.flags = {
			.allow_pd= 0,
		    .enable_internal_pullup = 0,
		    //.broadcast_en = 0,
		}
	  };	  
	  
	  ESP_ERROR_CHECK(i2c_new_slave_device(&i2c_slv_config, &context.i2cDev));
	  
	  
	  // Prepare callback function    
	  //// #if CONFIG_I2C_ENABLE_SLAVE_DRIVER_VERSION_2
	  i2c_slave_event_callbacks_t i2c_slave_callbacks = {
		 .on_request = i2cSlaveRequestStatic, //requestEventStatic,
    	 .on_receive = i2cSlaveReceiveStatic, //receiveEventStatic,
	  };
	  //// #elif !CONFIG_I2C_ENABLE_SLAVE_DRIVER_VERSION_2
	  // 	i2c_slave_event_callbacks_t i2c_slave_callbacks = {
	  // 		.on_recv_done = i2cSlaveReceiveStatic,
	  // 	};
	  
	  context.pin_number_in_bytes=PIN_NUMBER_IN_BYTES;   // initialization
	  context.rx_data_len=0;
      context.event_queue = xQueueCreate(16, sizeof(i2c_slave_event_t));	 
	  context.instance = this;
	  if (!context.event_queue) {
        ESP_LOGE("DABusI2CSlave", "Creating queue failed");
        return;
      }
	 
	  ESP_ERROR_CHECK(i2c_slave_register_event_callbacks(context.i2cDev,&i2c_slave_callbacks,&context.event_queue));
	 
	  /** code examples
	  // SLAVE_DRIVER_VERSION_1
	  //i2c_slave_receive(_i2cDev,_rec_buf,sizeof(_rec_buf));	    
	  uint8_t data[5];
	  
	  // SLAVE_DRIVER_VERSION_2
	  uint32_t bytes_sent;
	  data[0]='A';
	  data[1]=00;
	  // i2c_slave_write(_i2cDev,data,2,&bytes_sent,-1);	  
	  */ 
	 
	  // Initialize output fifo 	
	  //uint8_t data[3];
	  //uint32_t bytes_sent;
	  //data[0]=EXIOPINS; //0xE9;
	  //i2c_slave_write(context.i2cDev,data,3,&bytes_sent,-1);	  
	 
      //I2C_slave can be procesed in main loop or separated task:
#ifdef USE_I2C_SLAVE_TASK	  
	  //xTaskCreate(i2c_slave_task, "i2c_slave_task", 1024 * 4, &context, 10, NULL);
	  //or seperate task on single core:
	  xTaskCreatePinnedToCore(i2c_slave_task, "i2c_slave_task", 4096, &context, 1, NULL, 1);
#endif	  
      _instance = this;  // Assign the current instance
	}

#ifdef USE_I2C_SLAVE_TASK
	static void i2c_slave_task(void *arg)
    {
	 i2c_slave_context_t *context = (i2c_slave_context_t *)arg;
     i2c_slave_dev_handle_t i2cDev = (i2c_slave_dev_handle_t)context->i2cDev;
	 while (true) {
        i2c_slave_event_t evt;
	    if (xQueueReceive(context->event_queue, &evt, 10) == pdTRUE) {
		    if (evt == I2C_SLAVE_EVT_TX) {
				ESP_LOGI("DABusI2CSlave", "i2c slave event TX [%d]",context->rx_data_len); 
				//parse_command(context);
				context->rx_data_len=0;
				
			} else if (evt == I2C_SLAVE_EVT_RX) {
				uint8_t data[32];  //depth
				uint32_t bytes_sent;
				uint8_t data_length = context->pin_number_in_bytes; 
				// copy data to temporary buffer
				if (context->instance->_buf != nullptr) {	
					for (uint8_t i=0; i<data_length;i++) {
						data[i] = context->instance->_buf[i];	
					}
				} else {
					for (uint8_t i=0; i<data_length;i++) {
						data[i] = 0;
					}
				}
				i2c_slave_write(context->i2cDev,data,data_length,&bytes_sent,-1);	 
				//ESP_LOGI("DABusI2CSlave", "i2c slave event RX %d",bytes_sent); 
				//ESP_LOGI("DABusI2CSlave", "i2c slave event RX %d [%02x,%02x,%02x,%02x,..]",bytes_sent,data[0],data[1],data[2],data[3]); 
				if (context->instance->_request_notify != nullptr) {
					  context->instance->_request_notify->publish_state(1.0);  // Publishes the data 
				}
			} else {
				ESP_LOGI("DABusI2CSlave", "default"); 
			}				
		}
	 }
	 vTaskDelete(NULL);
    }
#endif



	void loop() override {
	
#ifndef USE_I2C_SLAVE_TASK	
	   i2c_slave_context_t *context = &_instance->context;
       i2c_slave_event_t evt;
       if (xQueueReceive(context->event_queue, &evt, 10) == pdTRUE) {
		    if (evt == I2C_SLAVE_EVT_TX) {
				ESP_LOGI("DABusI2CSlave", "i2c slave event TX [%d]",context->rx_data_len); 
				//parse_command(context);
				context->rx_data_len=0;
			} else if (evt == I2C_SLAVE_EVT_RX) {
				uint8_t data[32];  //depth
				uint32_t bytes_sent;
				uint8_t data_length = context->pin_number_in_bytes; 
				// copy data to temporary buffer
				if (context->instance->_buf != nullptr) {	
					for (uint8_t i=0; i<data_length;i++) {
						data[i] = context->instance->_buf[i];	
					}
				} else {
					for (uint8_t i=0; i<data_length;i++) {
						data[i] = 0;
					}
				}
				i2c_slave_write(context->i2cDev,data,data_length,&bytes_sent,-1);	 
				//ESP_LOGI("DABusI2CSlave", "i2c slave event RX"); 
				//ESP_LOGI("DABusI2CSlave", "i2c slave event RX %d [%02x,%02x,%02x,%02x,..]",bytes_sent,data[0],data[1],data[2],data[3]); 
				if (context->instance->_request_notify != nullptr) {
				  context->instance->_request_notify->publish_state(0.0);  // Publishes the data 
				}
			} else {
				ESP_LOGI("DABusI2CSlave", "default"); 
			}
	   }
#endif	   
	   
	}


  protected:
    i2c_slave_context_t context  = {0};
	
	uint8_t _address;
	text_sensor::TextSensor *_text_sensor = nullptr;
	sensor::Sensor *_request_notify = nullptr;
	uint8_t *_buf = nullptr; 
	uint8_t _buflen = 0;
	gpio_num_t _sdaPin;
	gpio_num_t _sclPin;
	uint8_t _rec_buf[256];	
	
	static DABusI2CSlave *_instance;  // Static pointer to the class instance
};



// Define the static instance
DABusI2CSlave *DABusI2CSlave::_instance = nullptr;