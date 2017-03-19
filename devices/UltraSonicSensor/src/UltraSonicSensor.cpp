#include "UltraSonicSensor.h"
#include "Poco/NumberFormatter.h"
#include "Poco/Util/TimerTask.h"
#include "Poco/Random.h"


namespace IoT 
{
namespace UltraSonicSensor 
{
const std::string UltraSonicSensor::NAME("UltraSonic Sensor");
const std::string UltraSonicSensor::SYMBOLIC_NAME("io.macchina.UltraSonicSensor");


UltraSonicSensor::UltraSonicSensor(const Params& params, Poco::Util::Timer& timer):
	_distanceValue(params.initDistanceValue),
	_pEventPolicy(new IoT::Devices::NoModerationPolicy<double>(valueChanged)),
	_deviceIdentifier(params.id),
	_symbolicName(SYMBOLIC_NAME),
	_name(NAME),
	_timer(timer)
{
	addProperty("displayValue", &UltraSonicSensor::getDisplayValue);
	addProperty("deviceIdentifier", &UltraSonicSensor::getDeviceIdentifier);
	addProperty("symbolicName", &UltraSonicSensor::getSymbolicName);
	addProperty("name", &UltraSonicSensor::getName);
	/* NEED TO ADD TIME UPDATER
	if (params.updateRate > 0)
	{
		long interval = 1000/params.updateRate;
		_timer.scheduleAtFixedRate(new LinearUpdateTimerTask(*this, params.initialValue, params.delta, params.cycles), interval, interval);
	}
	*/
}

	
UltraSonicSensor::~UltraSonicSensor()
{
}

double UltraSonicSensor::distanceValue() const
{
	Poco::Mutex::ScopedLock lock(_mutex);
	return _distanceValue;
}


bool UltraSonicSensor::ready() const
{
	return true;
}

Poco::Any UltraSonicSensor::getDisplayValue(const std::string&) const
{
	// Validate number format
	return Poco::NumberFormatter::format(distanceValue(), 0, 1);
}


Poco::Any UltraSonicSensor::getDeviceIdentifier(const std::string&) const
{
	return _deviceIdentifier;
}


Poco::Any UltraSonicSensor::getName(const std::string&) const
{
	return _name;
}


Poco::Any UltraSonicSensor::getSymbolicName(const std::string&) const
{
	return _symbolicName;
}


void UltraSonicSensor::update(double value)
{
	Poco::Mutex::ScopedLock lock(_mutex);

	if (_distanceValue != _distanceValue)
	{
		_distanceValue = value;
		_pEventPolicy->valueChanged(value);
	}
}

}
}

