#ifndef UltraSonicDeviceServerHelper_H
#define UltraSonicDeviceServerHelper_H


#include "IoT/Devices/IUltraSonicDevice.h"
#include "IoT/Devices/UltraSonicDevice.h"
#include "IoT/Devices/UltraSonicDeviceRemoteObject.h"
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/RemotingNG/ServerHelper.h"


namespace IoT {
namespace Devices {

class UltraSonicDeviceServerHelper
{
public:
	typedef IoT::Devices::UltraSonicDevice Service;

	UltraSonicDeviceServerHelper();
	~UltraSonicDeviceServerHelper();



	static Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
		
	static void enableEvents(const std::string& uri, const std::string& protocol);

	static std::string registerObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId);

	static std::string registerRemoteObject(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId);

	static void shutdown();

	static void unregisterObject(const std::string& uri);

private:
	static Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);

	void enableEventsImpl(const std::string& uri, const std::string& protocol);

	static UltraSonicDeviceServerHelper& instance();

	std::string registerObjectImpl(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId);

	void registerSkeleton();

	void unregisterObjectImpl(const std::string& uri);

	void unregisterSkeleton();

	Poco::RemotingNG::ORB* _pORB;
	};


inline Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> UltraSonicDeviceServerHelper::createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return UltraSonicDeviceServerHelper::instance().createRemoteObjectImpl(pServiceObject, oid);
}


inline void UltraSonicDeviceServerHelper::enableEvents(const std::string& uri, const std::string& protocol)
{
	UltraSonicDeviceServerHelper::instance().enableEventsImpl(uri, protocol);
}


inline std::string UltraSonicDeviceServerHelper::registerObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId)
{
	return UltraSonicDeviceServerHelper::instance().registerObjectImpl(createRemoteObject(pServiceObject, oid), listenerId);
}


inline std::string UltraSonicDeviceServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return UltraSonicDeviceServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}

inline void UltraSonicDeviceServerHelper::unregisterObject(const std::string& uri)
{
	UltraSonicDeviceServerHelper::instance().unregisterObjectImpl(uri);
}


} // namespace Devices
} // namespace IoT


REMOTING_SPECIALIZE_SERVER_HELPER(IoT::Devices, UltraSonicDevice)


#endif // UltraSonicDeviceServerHelper

