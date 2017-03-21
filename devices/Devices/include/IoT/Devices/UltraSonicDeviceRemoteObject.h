#ifndef UltraSonicDeviceRemoteObject_H
#define UltraSonicDeviceRemoteObject_H


#include "IoT/Devices/IUltraSonicDevice.h"
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/RemoteObject.h"
#include "Poco/SharedPtr.h"


namespace IoT {
namespace Devices {


class UltraSonicDeviceRemoteObject: public IoT::Devices::IUltraSonicDevice, public Poco::RemotingNG::RemoteObject
{
public:
	typedef Poco::AutoPtr<UltraSonicDeviceRemoteObject> Ptr;

	UltraSonicDeviceRemoteObject(const Poco::RemotingNG::Identifiable::ObjectId& oid, Poco::SharedPtr<IoT::Devices::UltraSonicDevice> pServiceObject);
		/// Creates a SensorRemoteObject.

	virtual ~UltraSonicDeviceRemoteObject();
		/// Destroys the SensorRemoteObject.

	void clearValueChangedFilter(const std::string& subscriberURI);
		/// Clears the filter set for the valueChanged event.

	virtual bool getFeature(const std::string& name) const;
		/// Returns true if the feature with the given name
		/// is enabled, or false otherwise.

	virtual bool getPropertyBool(const std::string& name) const;
		/// Returns the value of the device property with
		/// the given name.
		///
		/// Throws a Poco::NotFoundException if the property
		/// with the given name is unknown.

	virtual double getPropertyDouble(const std::string& name) const;
		/// Returns the value of the device property with
		/// the given name.
		///
		/// Throws a Poco::NotFoundException if the property
		/// with the given name is unknown.

	virtual int getPropertyInt(const std::string& name) const;
		/// Returns the value of the device property with
		/// the given name.
		///
		/// Throws a Poco::NotFoundException if the property
		/// with the given name is unknown.

	virtual std::string getPropertyString(const std::string& name) const;
		/// Returns the value of the device property with
		/// the given name.
		///
		/// Throws a Poco::NotFoundException if the property
		/// with the given name is unknown.

	virtual bool hasFeature(const std::string& name) const;
		/// Returns true if the feature with the given name
		/// is known, or false otherwise.

	virtual bool hasProperty(const std::string& name) const;
		/// Returns true if the property with the given name
		/// exists, or false otherwise.

	virtual bool ready() const;
		/// Returns true if a valid value is available.

	virtual std::string remoting__enableEvents(Poco::RemotingNG::Listener::Ptr pListener, bool enable = bool(true));

	virtual void remoting__enableRemoteEvents(const std::string& protocol);

	virtual bool remoting__hasEvents() const;

	virtual const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId() const;

	virtual void setFeature(const std::string& name, bool enable);
		/// Enables or disables the feature with the given name.
		///
		/// Which features are supported is defined by the
		/// actual device implementation.

	virtual void setPropertyBool(const std::string& name, bool value);
		/// Sets a device property.
		///
		/// Which properties are supported is defined by the
		/// actual device implementation.

	virtual void setPropertyDouble(const std::string& name, double value);
		/// Sets a device property.
		///
		/// Which properties are supported is defined by the
		/// actual device implementation.

	virtual void setPropertyInt(const std::string& name, int value);
		/// Sets a device property.
		///
		/// Which properties are supported is defined by the
		/// actual device implementation.

	virtual void setPropertyString(const std::string& name, const std::string& value);
		/// Sets a device property.
		///
		/// Which properties are supported is defined by the
		/// actual device implementation.

	void setValueChangedHysteresisFilter(const std::string& subscriberURI, double lowerThreshold, double upperThreshold);
		/// Sets a Poco::RemotingNG::HysteresisFilter for the valueChanged event.

	void setValueChangedIsGreaterThanFilter(const std::string& subscriberURI, double limit);
		/// Sets a Poco::RemotingNG::GreaterThanFilter for the valueChanged event.

	void setValueChangedIsGreaterThanOrEqualToFilter(const std::string& subscriberURI, double limit);
		/// Sets a Poco::RemotingNG::GreaterThanFilter for the valueChanged event.

	void setValueChangedIsLessThanOrEqualToFilter(const std::string& subscriberURI, double limit);
		/// Sets a Poco::RemotingNG::LessThanOrEqualToFilter for the valueChanged event.

	void setValueChangedIsLessThanThanFilter(const std::string& subscriberURI, double limit);
		/// Sets a Poco::RemotingNG::LessThanFilter for the valueChanged event.

	void setValueChangedMinimumDeltaFilter(const std::string& subscriberURI, double delta);
		/// Sets a Poco::RemotingNG::MinimumDeltaFilter for the valueChanged event.

	void setValueChangedMinimumIntervalFilter(const std::string& subscriberURI, long milliseconds);
		/// Sets a Poco::RemotingNG::MinimumIntervalFilter for the valueChanged event.

	void setValueChangedMinimumIntervalOrDeltaFilter(const std::string& subscriberURI, long milliseconds, double delta);
		/// Sets a Poco::RemotingNG::MinimumIntervalOrDeltaFilter for the valueChanged event.

	virtual double value() const;
		/// Returns the current value measured by the sensor.
		///
		/// Some sensors may not be able to immediately report
		/// a valid value. Therefore, before calling value() the first time, ready() 
		/// should be called to check if a valid value is available.

protected:
	void event__valueChanged(const double& data);

private:
	Poco::SharedPtr<IoT::Devices::UltraSonicDevice> _pServiceObject;
};


inline void UltraSonicDeviceRemoteObject::clearValueChangedFilter(const std::string& subscriberURI)
{
	_pServiceObject->clearValueChangedFilter(subscriberURI);
}


inline bool UltraSonicDeviceRemoteObject::getFeature(const std::string& name) const
{
	return _pServiceObject->getFeature(name);
}


inline bool UltraSonicDeviceRemoteObject::getPropertyBool(const std::string& name) const
{
	return _pServiceObject->getPropertyBool(name);
}


inline double UltraSonicDeviceRemoteObject::getPropertyDouble(const std::string& name) const
{
	return _pServiceObject->getPropertyDouble(name);
}


inline int UltraSonicDeviceRemoteObject::getPropertyInt(const std::string& name) const
{
	return _pServiceObject->getPropertyInt(name);
}


inline std::string UltraSonicDeviceRemoteObject::getPropertyString(const std::string& name) const
{
	return _pServiceObject->getPropertyString(name);
}


inline bool UltraSonicDeviceRemoteObject::hasFeature(const std::string& name) const
{
	return _pServiceObject->hasFeature(name);
}


inline bool UltraSonicDeviceRemoteObject::hasProperty(const std::string& name) const
{
	return _pServiceObject->hasProperty(name);
}


inline bool UltraSonicDeviceRemoteObject::ready() const
{
	return _pServiceObject->ready();
}


inline const Poco::RemotingNG::Identifiable::TypeId& UltraSonicDeviceRemoteObject::remoting__typeId() const
{
	return IUltraSonicDevice::remoting__typeId();
}


inline void UltraSonicDeviceRemoteObject::setFeature(const std::string& name, bool enable)
{
	_pServiceObject->setFeature(name, enable);
}


inline void UltraSonicDeviceRemoteObject::setPropertyBool(const std::string& name, bool value)
{
	_pServiceObject->setPropertyBool(name, value);
}


inline void UltraSonicDeviceRemoteObject::setPropertyDouble(const std::string& name, double value)
{
	_pServiceObject->setPropertyDouble(name, value);
}


inline void UltraSonicDeviceRemoteObject::setPropertyInt(const std::string& name, int value)
{
	_pServiceObject->setPropertyInt(name, value);
}


inline void UltraSonicDeviceRemoteObject::setPropertyString(const std::string& name, const std::string& value)
{
	_pServiceObject->setPropertyString(name, value);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedHysteresisFilter(const std::string& subscriberURI, double lowerThreshold, double upperThreshold)
{
	_pServiceObject->setValueChangedHysteresisFilter(subscriberURI, lowerThreshold, upperThreshold);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedIsGreaterThanFilter(const std::string& subscriberURI, double limit)
{
	_pServiceObject->setValueChangedIsGreaterThanFilter(subscriberURI, limit);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedIsGreaterThanOrEqualToFilter(const std::string& subscriberURI, double limit)
{
	_pServiceObject->setValueChangedIsGreaterThanOrEqualToFilter(subscriberURI, limit);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedIsLessThanOrEqualToFilter(const std::string& subscriberURI, double limit)
{
	_pServiceObject->setValueChangedIsLessThanOrEqualToFilter(subscriberURI, limit);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedIsLessThanThanFilter(const std::string& subscriberURI, double limit)
{
	_pServiceObject->setValueChangedIsLessThanThanFilter(subscriberURI, limit);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedMinimumDeltaFilter(const std::string& subscriberURI, double delta)
{
	_pServiceObject->setValueChangedMinimumDeltaFilter(subscriberURI, delta);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedMinimumIntervalFilter(const std::string& subscriberURI, long milliseconds)
{
	_pServiceObject->setValueChangedMinimumIntervalFilter(subscriberURI, milliseconds);
}


inline void UltraSonicDeviceRemoteObject::setValueChangedMinimumIntervalOrDeltaFilter(const std::string& subscriberURI, long milliseconds, double delta)
{
	_pServiceObject->setValueChangedMinimumIntervalOrDeltaFilter(subscriberURI, milliseconds, delta);
}


inline double UltraSonicDeviceRemoteObject::value() const
{
	return _pServiceObject->distanceValue();
}


} // namespace Devices
} // namespace IoT


#endif // IoT_Devices_SensorRemoteObject_INCLUDED

