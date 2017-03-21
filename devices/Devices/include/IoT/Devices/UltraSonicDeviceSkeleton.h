#ifndef UltraSonicDeviceSkeleton_H
#define UltraSonicDeviceSkeleton_H


#include "IoT/Devices/UltraSonicDeviceRemoteObject.h"
#include "Poco/RemotingNG/Skeleton.h"


namespace IoT {
namespace Devices {


class UltraSonicDeviceSkeleton: public Poco::RemotingNG::Skeleton
{
public:
	UltraSonicDeviceSkeleton();
		/// Creates a SensorSkeleton.

	virtual ~UltraSonicDeviceSkeleton();
		/// Destroys a SensorSkeleton.

	virtual const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId() const;

	static const std::string DEFAULT_NS;
};


inline const Poco::RemotingNG::Identifiable::TypeId& UltraSonicDeviceSkeleton::remoting__typeId() const
{
	return IUltraSonicDevice::remoting__typeId();
}


} // namespace Devices
} // namespace IoT


#endif // IoT_Devices_SensorSkeleton_INCLUDED

