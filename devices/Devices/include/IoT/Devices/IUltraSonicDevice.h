
#ifndef IUltraSonicDevice_H
#define IUltraSonicDevice_H


#include "IoT/Devices/IDevice.h"
#include "IoT/Devices/UltraSonicDevice.h"
#include "Poco/RemotingNG/Listener.h"


namespace IoT {
namespace Devices {


class IUltraSonicDevice: public IoT::Devices::IDevice
{
public:
	typedef Poco::AutoPtr<IUltraSonicDevice> Ptr;

	IUltraSonicDevice();

	virtual ~IUltraSonicDevice();

	virtual void clearValueChangedFilter(const std::string& subscriberURI) = 0;

	bool isA(const std::type_info& otherType) const;

	virtual bool ready() const = 0;
		/// Returns true if a valid value is available.

	virtual std::string remoting__enableEvents(Poco::RemotingNG::Listener::Ptr pListener, bool enable = bool(true)) = 0;
		/// Enable or disable delivery of remote events.
		///
		/// The given Listener instance must implement the Poco::RemotingNG::EventListener
		/// interface, otherwise this method will fail with a RemotingException.
		///
		/// This method is only used with Proxy objects; calling this method on a
		/// RemoteObject will do nothing.

	static const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId();
		/// Returns the TypeId of the class.

	virtual void setValueChangedHysteresisFilter(const std::string& subscriberURI, double lowerThreshold, double upperThreshold) = 0;
		/// Sets a Poco::RemotingNG::HysteresisFilter for the valueChanged event.

	virtual void setValueChangedIsGreaterThanFilter(const std::string& subscriberURI, double limit) = 0;
		/// Sets a Poco::RemotingNG::GreaterThanFilter for the valueChanged event.

	virtual void setValueChangedIsGreaterThanOrEqualToFilter(const std::string& subscriberURI, double limit) = 0;
		/// Sets a Poco::RemotingNG::GreaterThanFilter for the valueChanged event.

	virtual void setValueChangedIsLessThanOrEqualToFilter(const std::string& subscriberURI, double limit) = 0;
		/// Sets a Poco::RemotingNG::LessThanOrEqualToFilter for the valueChanged event.

	virtual void setValueChangedIsLessThanThanFilter(const std::string& subscriberURI, double limit) = 0;
		/// Sets a Poco::RemotingNG::LessThanFilter for the valueChanged event.

	virtual void setValueChangedMinimumDeltaFilter(const std::string& subscriberURI, double delta) = 0;
		/// Sets a Poco::RemotingNG::MinimumDeltaFilter for the valueChanged event.

	virtual void setValueChangedMinimumIntervalFilter(const std::string& subscriberURI, long milliseconds) = 0;
		/// Sets a Poco::RemotingNG::MinimumIntervalFilter for the valueChanged event.

	virtual void setValueChangedMinimumIntervalOrDeltaFilter(const std::string& subscriberURI, long milliseconds, double delta) = 0;
		/// Sets a Poco::RemotingNG::MinimumIntervalOrDeltaFilter for the valueChanged event.

	const std::type_info& type() const;

	virtual double value() const = 0;

	Poco::BasicEvent < const double > valueChanged;
};


} // namespace Devices
} // namespace IoT


#endif 

