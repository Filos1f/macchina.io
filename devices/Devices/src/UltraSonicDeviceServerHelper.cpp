
#include "IoT/Devices/UltraSonicDeviceServerHelper.h"
#include "IoT/Devices/UltraSonicDeviceEventDispatcher.h"
#include "IoT/Devices/UltraSonicDeviceSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace Devices {


namespace
{
	static Poco::SingletonHolder<UltraSonicDeviceServerHelper> shSensorServerHelper;
}

UltraSonicDeviceServerHelper::UltraSonicDeviceServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	registerSkeleton();
}


UltraSonicDeviceServerHelper::~UltraSonicDeviceServerHelper()
{
}



void UltraSonicDeviceServerHelper::shutdown()
{
	UltraSonicDeviceServerHelper::instance().unregisterSkeleton();
	shSensorServerHelper.reset();
}


Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> UltraSonicDeviceServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new UltraSonicDeviceRemoteObject(oid, pServiceObject);
}


void UltraSonicDeviceServerHelper::enableEventsImpl(const std::string& uri, const std::string& protocol)
{
	Poco::RemotingNG::Identifiable::Ptr pIdentifiable = _pORB->findObject(uri);
	Poco::AutoPtr<UltraSonicDeviceRemoteObject> pRemoteObject = pIdentifiable.cast<UltraSonicDeviceRemoteObject>();
	if (pRemoteObject)
	{
		pRemoteObject->remoting__enableRemoteEvents(protocol);
	}
	else throw Poco::NotFoundException("remote object", uri);
}


UltraSonicDeviceServerHelper& UltraSonicDeviceServerHelper::instance()
{
	return *shSensorServerHelper.get();
}


std::string UltraSonicDeviceServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void UltraSonicDeviceServerHelper::registerSkeleton()
{
	_pORB->registerSkeleton("IoT.Devices.UltraSonicDevice", new UltraSonicDeviceSkeleton);
}


void UltraSonicDeviceServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


void UltraSonicDeviceServerHelper::unregisterSkeleton()
{
	_pORB->unregisterSkeleton("IoT.Devices.UltraSonicDevice", true);
}


} // namespace Devices
} // namespace IoT

