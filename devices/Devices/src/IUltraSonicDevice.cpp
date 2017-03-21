//
// ISensor.cpp
//
// Library: IoT/Devices
// Package: Generated
// Module:  ISensor
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Devices/IUltraSonicDevice.h"


namespace IoT {
namespace Devices {


IUltraSonicDevice::IUltraSonicDevice():
	IoT::Devices::IDevice(),
	valueChanged()
{
}

IUltraSonicDevice::~IUltraSonicDevice()
{
}


bool IUltraSonicDevice::isA(const std::type_info& otherType) const
{
	std::string name(type().name());
	return name == otherType.name();
}


const Poco::RemotingNG::Identifiable::TypeId& IUltraSonicDevice::remoting__typeId()
{
	remoting__staticInitBegin(REMOTING__TYPE_ID);
	static const std::string REMOTING__TYPE_ID("IoT.Devices.UltraSonicDevice");
	remoting__staticInitEnd(REMOTING__TYPE_ID);
	return REMOTING__TYPE_ID;
}


const std::type_info& IUltraSonicDevice::type() const
{
	return typeid(IUltraSonicDevice);
}


} // namespace Devices
} // namespace IoT

