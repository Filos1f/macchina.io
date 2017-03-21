#ifndef DEVICE_ULTRASONICDEVICE_HPP
#define DEVICE_ULTRASONICDEVICE_HPP


#include "IoT/Devices/Device.h"
#include "Poco/RemotingNG/EventFilter.h"
#include "Poco/BasicEvent.h"


namespace IoT 
{
namespace Devices 
{
class IoTDevices_API UltraSonicDevice: public Device
{
public:
	Poco::BasicEvent<const double> valueChanged;
 		
	UltraSonicDevice();
		
	~UltraSonicDevice();


	virtual double distanceValue() const = 0;
		
	virtual bool ready() const = 0;

	void clearValueChangedFilter(const std::string& subscriberURI);

	void setValueChangedIsGreaterThanFilter(const std::string& subscriberURI, double limit);

	void setValueChangedIsGreaterThanOrEqualToFilter(const std::string& subscriberURI, double limit);

	void setValueChangedIsLessThanThanFilter(const std::string& subscriberURI, double limit);

	void setValueChangedIsLessThanOrEqualToFilter(const std::string& subscriberURI, double limit);

	void setValueChangedMinimumDeltaFilter(const std::string& subscriberURI, double delta);

	void setValueChangedMinimumIntervalFilter(const std::string& subscriberURI, long milliseconds);
		
	void setValueChangedMinimumIntervalOrDeltaFilter(const std::string& subscriberURI, long milliseconds, double delta);
		
	void setValueChangedHysteresisFilter(const std::string& subscriberURI, double lowerThreshold, double upperThreshold);
	
	
private:
	void setValueChangedFilter(const std::string& subscriberURI, Poco::RemotingNG::EventFilter<double>::Ptr pFilter);
};


} } // namespace IoT::Devices


#endif // IoT_Devices_Sensor_INCLUDED
