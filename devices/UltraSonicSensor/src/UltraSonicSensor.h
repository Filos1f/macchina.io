#ifndef ULTRASONICSENSOR_HPP
#define ULTRASONICSENSOR_HPP

#include "IoT/Devices/UltraSonicDevice.h"
#include "IoT/Devices/DeviceImpl.h"
#include "IoT/Devices/EventModerationPolicy.h"
#include "Poco/Util/Timer.h"

namespace IoT 
{
namespace UltraSonicSensor 
{
class UltraSonicSensor: public IoT::Devices::DeviceImpl<IoT::Devices::UltraSonicDevice, UltraSonicSensor>
{
public:
	struct Params
	{
		std::string id;
		
		double maxRange;
		double minRange;

		double angle;

		double initDistanceValue;

		double updateRate;
	};
	
	UltraSonicSensor(const Params& params, Poco::Util::Timer& timer);
		
	~UltraSonicSensor();
	
	double distanceValue() const;
	bool ready() const;

	static const std::string NAME;
	static const std::string SYMBOLIC_NAME;

protected:
	Poco::Any getDisplayValue(const std::string&) const;
	Poco::Any getDeviceIdentifier(const std::string&) const;
	Poco::Any getName(const std::string&) const;
	Poco::Any getSymbolicName(const std::string&) const;
	void update(double value);

private:
	double _distanceValue;
	Poco::SharedPtr<IoT::Devices::EventModerationPolicy<double> > _pEventPolicy;
	Poco::Any _deviceIdentifier;
	Poco::Any _symbolicName;
	Poco::Any _name;
	Poco::Util::Timer& _timer;
};
}
}

#endif