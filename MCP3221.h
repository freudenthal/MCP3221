/*
MCP3221.h Library for writing configuration data to MCP3221 12-Bit ADC
Last update 9/2/2015
John Freudenthal and Sean Kirkpatrick
*/

#ifndef MCP3221_h	//check for multiple inclusions
#define MCP3221_h

#include "Arduino.h"
#include "i2c_t3.h"

// #define NumberOfChannels 4
// #define InternalReference 2.5f
// // const uint8_t DefaultAddress = 0x1B;
#define I2CTimeout 1000
#define ReferenceVoltage 3.3f

const float MaxValue = (float)(pow(2,12)-1);
// #define MaxVoltageInt 0x1000

// enum class powerMode{Unknown, Normal, GND1kOhm, GND100kOhm, HighImpedance};
// enum class outputMode{Unknown, Immediate, Synchronized};
// enum class MCP3221ReferenceMode{Unknown, Internal, External};
// enum class commandMode{Write2Register, UpdateRegister, WriteWUpdateAll, WriteWUpdate, PowerUpDown, Reset, LDACRegister, IntReference};

class MCP3221
{
	public:
		MCP3221();
		~MCP3221();
		bool isConnected();
		uint8_t getAddress();
		void setAddress(uint8_t address);
		// bool setVoltage(uint8_t Channel, float Value);
		// int getVoltage(uint8_t Channel);
		void RecieveI2CFloat(float* Data, size_t NumberOfSamples);
		void getVoltage(uint16_t* Data, size_t NumberOfSamples);
		// bool setPower(uint8_t Channel, bool Active);
		// bool getPower(uint8_t Channel);
		// bool setPowerMode(powerMode ModeSetting);
		// powerMode getPowerMode();
		// bool setOutputMode(outputMode ModeSetting);
		// outputMode getOutputMode();
		// bool setReference(MCP3221ReferenceMode ModeSetting);
		// MCP3221ReferenceMode getReference();
		// void setVRefExt(float VRef);
		// float getVRefExt();
		// float getVRef();
	private:
		uint8_t Address;
		// bool Power[NumberOfChannels];
		// float Voltage[NumberOfChannels];
		// powerMode PowerMode;
		// outputMode OutputMode;
		// MCP3221ReferenceMode ReferenceMode;
		uint8_t CommandByte;
		uint8_t MSBByte;
		uint8_t LSBByte;
		// const float VRefInt = InternalReference;
		// float VRefExt;
		// void ResetCommandByte();
		// void SetCommandByteAddress(uint8_t DACAddress);
		// void SetCommandByteCommand(commandMode Command);
		// void SendI2C();
};
#endif