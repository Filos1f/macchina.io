<<<<<<< HEAD
#ifndef UltraSonicDeviceServerHelper_H
#define UltraSonicDeviceServerHelper_H


#include "IoT/Devices/IUltraSonicDevice.h"
#include "IoT/Devices/UltraSonicDevice.h"
#include "IoT/Devices/UltraSonicDeviceRemoteObject.h"
=======
#ifndef UltraSonicDeviceServerHelper
#define UltraSonicDeviceServerHelper


#include "IoT/Devices/ISensor.h"
#include "IoT/Devices/UltraSonicDevice.h"
#include "IoT/Devices/SensorRemoteObject.h"
>>>>>>> SA_Brunch
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/RemotingNG/ServerHelper.h"


namespace IoT {
namespace Devices {

<<<<<<< HEAD
=======

>>>>>>> SA_Brunch
class UltraSonicDeviceServerHelper
{
public:
	typedef IoT::Devices::UltraSonicDevice Service;

	UltraSonicDeviceServerHelper();
<<<<<<< HEAD
	~UltraSonicDeviceServerHelper();



	static Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
=======

	~UltraSonicDeviceServerHelper();

	static Poco::AutoPtr<IoT::Devices::SensorRemoteObject> createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
>>>>>>> SA_Brunch
		
	static void enableEvents(const std::string& uri, const std::string& protocol);

	static std::string registerObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId);

<<<<<<< HEAD
	static std::string registerRemoteObject(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId);
=======
	static std::string registerRemoteObject(Poco::AutoPtr<IoT::Devices::SensorRemoteObject> pRemoteObject, const std::string& listenerId);
>>>>>>> SA_Brunch

	static void shutdown();

	static void unregisterObject(const std::string& uri);

private:
<<<<<<< HEAD
	static Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
=======
	static Poco::AutoPtr<IoT::Devices::SensorRemoteObject> createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
>>>>>>> SA_Brunch

	void enableEventsImpl(const std::string& uri, const std::string& protocol);

	static UltraSonicDeviceServerHelper& instance();

<<<<<<< HEAD
	std::string registerObjectImpl(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId);
=======
	std::string registerObjectImpl(Poco::AutoPtr<IoT::Devices::SensorRemoteObject> pRemoteObject, const std::string& listenerId);
>>>>>>> SA_Brunch

	void registerSkeleton();

	void unregisterObjectImpl(const std::string& uri);

	void unregisterSkeleton();

	Poco::RemotingNG::ORB* _pORB;
<<<<<<< HEAD
	};


inline Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> UltraSonicDeviceServerHelper::createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
=======
};


inline Poco::AutoPtr<IoT::Devices::SensorRemoteObject> UltraSonicDeviceServerHelper::createRemoteObject(Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
>>>>>>> SA_Brunch
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


<<<<<<< HEAD
inline std::string UltraSonicDeviceServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::UltraSonicDeviceRemoteObject> pRemoteObject, const std::string& listenerId)
=======
inline std::string UltraSonicDeviceServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::SensorRemoteObject> pRemoteObject, const std::string& listenerId)
>>>>>>> SA_Brunch
{
	return UltraSonicDeviceServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}

<<<<<<< HEAD
=======

>>>>>>> SA_Brunch
inline void UltraSonicDeviceServerHelper::unregisterObject(const std::string& uri)
{
	UltraSonicDeviceServerHelper::instance().unregisterObjectImpl(uri);
}


} // namespace Devices
} // namespace IoT


REMOTING_SPECIALIZE_SERVER_HELPER(IoT::Devices, UltraSonicDevice)


#endif // UltraSonicDeviceServerHelper

