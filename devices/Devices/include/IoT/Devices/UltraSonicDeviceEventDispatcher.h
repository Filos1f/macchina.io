#ifndef UltraSonicDeviceEventDispatcher_H
#define UltraSonicDeviceEventDispatcher_H


#include "IoT/Devices/UltraSonicDeviceRemoteObject.h"
#include "Poco/RemotingNG/EventDispatcher.h"


namespace IoT {
namespace Devices {


class UltraSonicDeviceEventDispatcher: public Poco::RemotingNG::EventDispatcher
{
public:
	UltraSonicDeviceEventDispatcher(UltraSonicDeviceRemoteObject* pRemoteObject, const std::string& protocol);

	virtual ~UltraSonicDeviceEventDispatcher();

	void event__valueChanged(const void* pSender, const double& data);

	virtual const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId() const;

private:
	void event__valueChangedImpl(const std::string& subscriberURI, const double& data);

	static const std::string DEFAULT_NS;
	UltraSonicDeviceRemoteObject* _pRemoteObject;
};


inline const Poco::RemotingNG::Identifiable::TypeId& UltraSonicDeviceEventDispatcher::remoting__typeId() const
{
	return IUltraSonicDevice::remoting__typeId();
}


} // namespace Devices
} // namespace IoT


#endif 

