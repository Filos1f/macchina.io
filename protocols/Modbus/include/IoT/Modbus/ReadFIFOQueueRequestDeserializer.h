//
// ReadFIFOQueueRequestDeserializer.h
//
// Package: Generated
// Module:  TypeDeserializer
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#ifndef TypeDeserializer_IoT_Modbus_ReadFIFOQueueRequest_INCLUDED
#define TypeDeserializer_IoT_Modbus_ReadFIFOQueueRequest_INCLUDED


#include "IoT/Modbus/ModbusMaster.h"
#include "Poco/RemotingNG/TypeDeserializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeDeserializer<IoT::Modbus::ReadFIFOQueueRequest>
{
public:
	static bool deserialize(const std::string& name, bool isMandatory, Deserializer& deser, IoT::Modbus::ReadFIFOQueueRequest& value)
	{
		bool ret = deser.deserializeStructBegin(name, isMandatory);
		if (ret)
		{
			deserializeImpl(deser, value);
			deser.deserializeStructEnd(name);
		}
		return ret;
	}

	static void deserializeImpl(Deserializer& deser, IoT::Modbus::ReadFIFOQueueRequest& value)
	{
		// IoT::Modbus::ModbusMessage
		{
		remoting__staticInitBegin(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE);
		static const std::string REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[] = {"functionCode","slaveOrUnitAddress"};
		remoting__staticInitEnd(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE);
		TypeDeserializer<Poco::UInt8 >::deserialize(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[0], true, deser, value.functionCode);
		TypeDeserializer<Poco::UInt8 >::deserialize(REMOTING__NAMES__IOT__MODBUS__MODBUSMESSAGE[1], true, deser, value.slaveOrUnitAddress);
		}
		
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"fifoAddress"};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeDeserializer<Poco::UInt16 >::deserialize(REMOTING__NAMES[0], true, deser, value.fifoAddress);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeDeserializer_IoT_Modbus_ReadFIFOQueueRequest_INCLUDED

