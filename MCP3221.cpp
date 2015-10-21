/*
MCP3221.cpp communication library for MCP3221 12-Bit ADC
Last update 9/2/2015
John Freudenthal and Sean Kirkpatrick
*/

#include "MCP3221.h"
#define combine(high,low) ( ( (uint16_t)(high << 8) ) | (uint16_t)(low) )
// #define lowbyte(value) ( (uint8_t)(value) )
// #define highbyte(value) ( (uint8_t)(value>>8) )
// #define NumberOfChannels 4
// #define InternalReference 2.5f
// #define DefaultAddress 16
// #define MaxVoltageInt = 0x1000
// using namespace std;
// enum class powerMode{Unknown, Normal, GND1kOhm, GND100kOhm, HighImpedance};
// enum class outputMode{Unknown, Immediate, Synchronized};
// enum class MCP3221ReferenceMode{Unknown, Internal, External};
// enum class commanMode{Write2Register, UpdateRegister, WriteWUpdateAll, WriteWUpdate, PowerUpDown, Reset, LDACRegister, IntReference};

MCP3221::MCP3221()
{
	// PowerMode = powerMode::Unknown;
	// OutputMode = outputMode::Unknown;
	// ReferenceMode = MCP3221ReferenceMode::Internal;
	//Address = DefaultAddress;
	Address = B1001101;	//7-bit address
	// for (int Index = 0; Index < NumberOfChannels; Index++)
	// {
	// 	Power[Index] = true;
	// 	Voltage[Index] = 0.0f;
	// }
}
MCP3221::~MCP3221()
{

}
// float MCP3221::getVRef()
// {
// 	switch (ReferenceMode)
// 	{
// 		case MCP3221ReferenceMode::Internal:
// 			return 2.0f*InternalReference;
// 		default:
// 			return VRefExt;
// 	}
// }
uint8_t MCP3221::getAddress()
{
	return Address;
}
void MCP3221::setAddress(uint8_t address)
{
	Address = address;
}
bool MCP3221::isConnected()
{
	int Status = 5;
	Wire.beginTransmission(Address);
    Status = Wire.endTransmission();
    if (Status == 0)
    {
    	return true;
    }
    else
    {
    	return false;
    }
}
// bool MCP3221::setVoltage(uint8_t Channel, float Value)
// {
// 	Channel = constrain(Channel,0,NumberOfChannels);
// 	Value = constrain(Value,0,getVRef());
// 	Voltage[Channel] = Value;
// 	// Serial.println(Value);
// 	Value = Value / getVRef();
// 	// Serial.println(Value);
// 	uint16_t SetValue = (uint16_t)(Value * MaxVoltageInt);
// 	// Serial.println(SetValue);
// 	// Serial.println(SetValue, BIN);
// 	SetValue = SetValue << 4;
// 	// Serial.println(SetValue, BIN);
// 	MSBByte = (uint8_t)(SetValue >> 8);
// 	LSBByte = (uint8_t)(SetValue);
// 	ResetCommandByte();
// 	SetCommandByteAddress(Channel);
// 	SetCommandByteCommand(commandMode::WriteWUpdate);
// 	SendI2C();
// 	return true;
// }
// int MCP3221::getVoltage(uint8_t Channel)
// {
// 	Channel = constrain(Channel,0,NumberOfChannels);
// 	return Voltage[Channel];
// }
// bool MCP3221::setPower(uint8_t Channel, bool Active)
// {
// 	Channel = constrain(Channel,0,NumberOfChannels);
// 	Power[Channel] = Active;
// 	if (PowerMode != powerMode::Unknown)
// 	{
// 	ResetCommandByte();
// 	SetCommandByteCommand(commandMode::PowerUpDown);
// 	MSBByte = 0;
// 	LSBByte = ((((uint8_t)PowerMode) - 1)<<4) | (uint8_t)15;
// 	for (int ChannelIndex = 0; ChannelIndex < NumberOfChannels; ChannelIndex++)
// 	{
// 		bitWrite(LSBByte, ChannelIndex, Power[ChannelIndex]);
// 	}
// 	SendI2C();
// 	}
// 	return true;
// }
// bool MCP3221::getPower(uint8_t Channel)
// {
// 	return Power[Channel];
// }
// bool MCP3221::setPowerMode(powerMode ModeSetting)
// {
// 	PowerMode = ModeSetting;
// 	return true;
// }
// powerMode MCP3221::getPowerMode()
// {
// 	return PowerMode;
// }
// bool MCP3221::setOutputMode(outputMode ModeSetting)
// {
// 	if (ModeSetting != outputMode::Unknown)
// 	{
// 		MSBByte = 0;
// 		ResetCommandByte();
// 		SetCommandByteCommand(commandMode::LDACRegister);
// 		switch (ModeSetting)
// 		{
// 			case outputMode::Immediate:
// 				LSBByte = (uint8_t)15;
// 				break;
// 			case outputMode::Synchronized:
// 			default:
// 				LSBByte = 0;
// 				break;
// 		}
// 		SendI2C();
// 		OutputMode = ModeSetting;
// 		return true;
// 	} else
// 	{
// 		return false;
// 	}
// }
// outputMode MCP3221::getOutputMode()
// {
// 	return OutputMode;
// }
// bool MCP3221::setReference(MCP3221ReferenceMode ModeSetting)
// {
// 	if (ModeSetting != MCP3221ReferenceMode::Unknown)
// 	{
// 		MSBByte = 0;
// 		ResetCommandByte();
// 		SetCommandByteCommand(commandMode::IntReference);
// 		switch (ModeSetting)
// 		{
// 			case MCP3221ReferenceMode::Internal:
// 				LSBByte = (uint8_t)1;
// 				break;
// 			// case outputMode::External:
// 			default:
// 				LSBByte = 0;
// 				break;
// 		}
// 		SendI2C();
// 		ReferenceMode = ModeSetting;
// 		return true;
// 	} else
// 	{
// 		return false;
// 	}
// }
// MCP3221ReferenceMode MCP3221::getReference()
// {
// 	return ReferenceMode;
// }
// void MCP3221::setVRefExt(float VRef)
// {
// 	VRefExt = VRef;
// }
// float MCP3221::getVRefExt()
// {
// 	return VRefExt;
// }
// void MCP3221::ResetCommandByte()
// {
// 	CommandByte = 0;
// }
// void MCP3221::SetCommandByteAddress(uint8_t Channel)
// {
// 	// CommandByte = DACAddress;
// 	CommandByte = CommandByte & B11111000;
// 	switch (Channel)
// 	{
// 		case 0:
// 			break;
// 		case 1:
// 			CommandByte = CommandByte | B00000001;
// 			break;
// 		case 2:
// 			CommandByte = CommandByte | B00000010;
// 			break;
// 		case 3:
// 			CommandByte = CommandByte | B00000011;
// 			break;
// 		default:
// 			break;
// 	}
// }
// void MCP3221::SetCommandByteCommand(commandMode Command)
// {
// 	// CommandByte = ( (uint8_t)Command ) << 3;
// 	switch (Command)
// 	{
// 		case commandMode::WriteWUpdate:
// 			CommandByte = CommandByte | B00011000;
// 			break;
// 		default:
// 			break;
// 	}
// }
// void MCP3221::SendI2C()
// {
//   bool MoveOn = false;
//   const int MaxAttempts = 16;
//   int CurrentAttempt = 0;
//   int SendSuccess = 5;
//   while (!MoveOn)
//   {
// 	Wire.beginTransmission(Address);
// 	Wire.write(CommandByte);
// 	// Serial.print("CommandByte: ");Serial.print(CommandByte, BIN);Serial.print("\n");
// 	// Wire.write(MSBByte);
// 	// Serial.print("MSBByte: ");Serial.print(MSBByte, BIN);Serial.print("\n");
// 	// Wire.write(LSBByte);
// 	// Serial.print("LSBByte: ");Serial.print(LSBByte, BIN);Serial.print("\n");
// 	SendSuccess = Wire.endTransmission(I2C_STOP,I2CTimeout);
//     if(SendSuccess != 0)
//     {
//       Wire.finish();
//       Wire.resetBus();
//       CurrentAttempt++;
//       if (CurrentAttempt > MaxAttempts)
//       {
//         MoveOn = true;
//         Serial.println("Unrecoverable I2C transmission error with MCP3221.");
//       }
//     }
//     else
//     {
//     	// Serial.println("I2C write success!");
//       MoveOn = true;
//     }
//   }
// }
void MCP3221::RecieveI2CFloat(float* Data, size_t NumberOfSamples)
{
  if(NumberOfSamples > 0)
  {
  	Wire.beginTransmission(Address);
  	// Wire.write(Address);
  	// Wire.endTransmission();
  	//
    Wire.requestFrom(Address, 2*NumberOfSamples, I2C_STOP, I2CTimeout*2*NumberOfSamples);
    int CurrentIndex = 0;
    while (Wire.available())
    {
	    MSBByte = Wire.readByte();
	    // Serial.println(MSBByte, BIN);
	    // MSBByte = (MSBByte << 4)>>4;	
	    MSBByte = MSBByte & B00001111;	//delete first four bits
		// Serial.println(MSBByte, BIN);
	    LSBByte = Wire.readByte();
	    // Serial.println(LSBByte, BIN);
	    //uint8_t CurrentChannel = MSBByte >> 4;
	    // uint16_t CurrentValue = combine( ((MSBByte << 4)>>4), LSBByte ) >> LowByteShift;
	    uint16_t CurrentValue = combine(MSBByte, LSBByte );
	    // Serial.println(CurrentValue, BIN);
	    Data[CurrentIndex] = ReferenceVoltage*((float)CurrentValue)/MaxValue;
	    CurrentIndex++;
	}
	// return true;
  }
  // else
  // {
  // 	return false;
  // }
}

void MCP3221::getVoltage(uint16_t* Data, size_t NumberOfSamples)
{
	if(NumberOfSamples > 0)
  {
  	Wire.beginTransmission(Address);
  	// Wire.write(Address);
  	// Wire.endTransmission();
  	//
    Wire.requestFrom(Address, 2*NumberOfSamples, I2C_STOP, I2CTimeout*2*NumberOfSamples);
    int CurrentIndex = 0;
    while (Wire.available())
    {
	    MSBByte = Wire.readByte();
	    MSBByte = MSBByte & B00001111;	//delete first four bits
	    LSBByte = Wire.readByte();
	    uint16_t CurrentValue = combine(MSBByte, LSBByte );
	    Data[CurrentIndex] = CurrentValue;
	    CurrentIndex++;
	}
	// return true;
  }
}