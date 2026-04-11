/*  © 2025, Arkadiusz Hahn, and Discord user @Arq
 *  © 2023, Paul Antoine, and Discord user @ADUBOURG
 *  © 2021, Neil McKechnie. All rights reserved.
 *  
 *  This file is part of DCC++EX API
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CommandStation.  If not, see <https://www.gnu.org/licenses/>.
 */

/* 
 * The DABUS is a binary input with pullup sensor device; it only has one register.  
 * The device can only be read, no configuration required.   
 */

// change line 127:  IO_GPIOBase.h  ->  uint64_t mask = 1 << pin; 

#ifndef IO_DABUS_H
#define IO_DABUS_H

#include "IO_GPIOBase.h"
#include "FSH.h"

class DABUS : public GPIOBase<uint64_t> {
public:
  static void create(VPIN firstVpin, uint8_t nPins, I2CAddress i2cAddress, int interruptPin=-1) {
    if (checkNoOverlap(firstVpin, nPins, i2cAddress)) new DABUS(firstVpin, nPins, i2cAddress, interruptPin);
  }

private:
  DABUS(VPIN firstVpin, uint8_t nPins, I2CAddress i2cAddress, int interruptPin=-1)
    : GPIOBase<uint64_t>((FSH *)F("DABUS"), firstVpin, nPins, i2cAddress, interruptPin)
  {
    requestBlock.setReadParams(_I2CAddress, inputBuffer, sizeof(inputBuffer));
  }
  
  // The DABUS handles inputs by applying a weak pull-up when output is driven to '1'.
  // The pin state is driven '1' if the pin is an input, or if it is an output set to 1.
  // Unused pins are driven '0'.
  void _writeGpioPort() override {
    uint64_t bits = (_portOutputState | ~_portMode) & _portInUse;
    I2CManager.write(_I2CAddress, 8, bits, bits>>8,bits>>16,bits>>24,bits>>32,bits>>40,bits>>48,bits>>56);
  }

  // The DABUS handles inputs by applying a weak pull-up when output is driven to '1'.
  // Therefore, writing '1' in _writePortModes is enough to set the module to input mode 
  // and enable pull-up.
  void _writePullups() override { }

  // The pin state is '1' if the pin is an input or if it is an output set to 1.  Zero otherwise. 
  void _writePortModes() override {
    _writeGpioPort();
  }

  // In immediate mode, _readGpioPort reads the device GPIO port and updates _portInputState accordingly.
  //  When not in immediate mode, it initiates a request using the request block and returns.
  //  When the request completes, _processCompletion finishes the operation.
  void _readGpioPort(bool immediate) override {
    if (immediate) {
      uint8_t buffer[8];
      I2CManager.read(_I2CAddress, buffer, 8);
      _portInputState = (((uint64_t)buffer[7]<<56) 
      | ((uint64_t)buffer[6]<<48) | ((uint64_t)buffer[5]<<40) 
      | ((uint64_t)buffer[4]<<32) | ((uint64_t)buffer[3]<<24) 
      | ((uint64_t)buffer[2]<<16) | ((uint64_t)buffer[1]<<8) 
      | buffer[0]) | _portMode;
    } else {
      requestBlock.wait(); // Wait for preceding operation to complete
      // Issue new request to read GPIO register
      I2CManager.queueRequest(&requestBlock);
    }
  }

  // This function is invoked when an I/O operation on the requestBlock completes.
  void _processCompletion(uint8_t status) override {
    if (status == I2C_STATUS_OK) 
      //_portInputState = (((uint16_t)inputBuffer[1]<<8) | inputBuffer[0]) | _portMode;
      _portInputState = (((uint64_t)inputBuffer[7]<<56) 
        | ((uint64_t)inputBuffer[6]<<48) | ((uint64_t)inputBuffer[5]<<40) 
        | ((uint64_t)inputBuffer[4]<<32) | ((uint64_t)inputBuffer[3]<<24) 
        | ((uint64_t)inputBuffer[2]<<16) | ((uint64_t)inputBuffer[1]<<8) 
        | inputBuffer[0]) | _portMode;
    else  
      _portInputState = 0xffffffffffffffff;
  }

  // Set up device ports
  void _setupDevice() override { 
    _writePortModes();
    _writeGpioPort();
    _writePullups();
  }
 
  uint8_t inputBuffer[8];
};

#endif
