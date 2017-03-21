#include "IoT/Devices/UltraSonicDeviceRemoteObject.h"
#include "IoT/Devices/UltraSonicDeviceEventDispatcher.h"
#include "Poco/Delegate.h"
#include "Poco/RemotingNG/ORB.h"


namespace IoT {
namespace Devices {


UltraSonicDeviceRemoteObject::UltraSonicDeviceRemoteObject(const Poco::RemotingNG::Identifiable::ObjectId& oid, Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject):
	IoT::Devices::IUltraSonicDevice(),
	Poco::RemotingNG::RemoteObject(oid),
	_pServiceObject(pServiceObject)
{
	_pServiceObject->valueChanged += Poco::delegate(this, &UltraSonicDeviceRemoteObject::event__valueChanged);
}


UltraSonicDeviceRemoteObject::~UltraSonicDeviceRemoteObject()
{
	try
	{
		_pServiceObject->valueChanged -= Poco::delegate(this, &UltraSonicDeviceRemoteObject::event__valueChanged);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string UltraSonicDeviceRemoteObject::remoting__enableEvents(Poco::RemotingNG::Listener::Ptr pListener, bool enable)
{
	return std::string();
}


void UltraSonicDeviceRemoteObject::remoting__enableRemoteEvents(const std::string& protocol)
{
	Poco::RemotingNG::EventDispatcher::Ptr pEventDispatcher = new UltraSonicDeviceEventDispatcher(this, protocol);
	Poco::RemotingNG::ORB::instance().registerEventDispatcher(remoting__getURI().toString(), pEventDispatcher);
}


bool UltraSonicDeviceRemoteObject::remoting__hasEvents() const
{
	return true;
}


void UltraSonicDeviceRemoteObject::event__valueChanged(const double& data)
{
	valueChanged(this, data);
}


} // namespace Devices
} // namespace IoT

