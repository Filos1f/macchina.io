//
// ReadHoldingRegistersRequestSerializer.h
//
// Package: Generated
// Module:  TypeSerializer
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#ifndef TypeSerializer_IoT_Modbus_ReadHoldingRegistersRequest_INCLUDED
#define TypeSerializer_IoT_Modbus_ReadHoldingRegistersRequest_INCLUDED


#include "IoT/Modbus/ModbusMaster.h"
#include "Poco/RemotingNG/TypeSerializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeSerializer<IoT::Modbus::ReadHoldingRegistersRequest>
{
public:
	static void serialize(const std::string& name, const IoT::Modbus::ReadHoldingRegistersRequest& value, Serializer& ser)
	{
		ser.serializeStructBegin(name);
		serializeImpl(value, ser);
		ser.serializeStructEnd(name);
	}

	static void serializeImpl(const IoT::Modbus::ReadHoldingRegistersRequest& value, Serializer& ser)
	{
		// IoT::Modbus::ModbusMessage
		{
		remoting__staticInitBegin(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE);
		static const std::string REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[] = {"functionCode","slaveOrUnitAddress",""};
		remoting__staticInitEnd(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE);
		TypeSerializer<Poco::UInt8 >::serialize(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[0], value.functionCode, ser);
		TypeSerializer<Poco::UInt8 >::serialize(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[1], value.slaveOrUnitAddress, ser);
		}
		
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"nOfRegisters","startingAddress",""};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeSerializer<Poco::UInt16 >::serialize(REMOTING__NAMES[0], value.nOfRegisters, ser);
		TypeSerializer<Poco::UInt16 >::serialize(REMOTING__NAMES[1], value.startingAddress, ser);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeSerializer_IoT_Modbus_ReadHoldingRegistersRequest_INCLUDED

