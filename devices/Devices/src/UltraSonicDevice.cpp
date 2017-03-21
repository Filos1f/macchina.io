#include "IoT/Devices/UltraSonicDevice.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/RemotingNG/EventDispatcher.h"
#include "Poco/RemotingNG/ORB.h"


namespace IoT 
{
namespace Devices 
{


void UltraSonicDevice::clearValueChangedFilter(const std::string& subscriberURI)
{
	Poco::RemotingNG::ORB& orb = Poco::RemotingNG::ORB::instance();
	Poco::RemotingNG::Context::Ptr pContext = Poco::RemotingNG::Context::get();
	std::string uri = pContext->getValue<std::string>("uri");
	std::string proto = pContext->getValue<std::string>("transport");
	Poco::RemotingNG::EventDispatcher::Ptr pED = orb.findEventDispatcher(uri, proto);
	pED->removeEventFilter(subscriberURI, "valueChanged");
}


void UltraSonicDevice::setValueChangedIsGreaterThanFilter(const std::string& subscriberURI, double limit)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::IsGreaterThanFilter<double>(limit));
}


void UltraSonicDevice::setValueChangedIsGreaterThanOrEqualToFilter(const std::string& subscriberURI, double limit)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::IsGreaterThanOrEqualToFilter<double>(limit));
}


void UltraSonicDevice::setValueChangedIsLessThanThanFilter(const std::string& subscriberURI, double limit)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::IsLessThanFilter<double>(limit));
}


void UltraSonicDevice::setValueChangedIsLessThanOrEqualToFilter(const std::string& subscriberURI, double limit)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::IsLessThanOrEqualToFilter<double>(limit));
}


void UltraSonicDevice::setValueChangedMinimumDeltaFilter(const std::string& subscriberURI, double delta)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::MinimumDeltaFilter<double>(delta));
}


void UltraSonicDevice::setValueChangedMinimumIntervalFilter(const std::string& subscriberURI, long milliseconds)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::MinimumIntervalFilter<double>(static_cast<Poco::Clock::ClockDiff>(milliseconds)*1000));
}


void UltraSonicDevice::setValueChangedMinimumIntervalOrDeltaFilter(const std::string& subscriberURI, long milliseconds, double delta)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::MinimumIntervalOrDeltaFilter<double>(static_cast<Poco::Clock::ClockDiff>(milliseconds)*1000, delta));
}


void UltraSonicDevice::setValueChangedHysteresisFilter(const std::string& subscriberURI, double lowerThreshold, double upperThreshold)
{
	setValueChangedFilter(subscriberURI, new Poco::RemotingNG::HysteresisFilter<double>(lowerThreshold, upperThreshold));
}


void UltraSonicDevice::setValueChangedFilter(const std::string& subscriberURI, Poco::RemotingNG::EventFilter<double>::Ptr pFilter)
{
	Poco::RemotingNG::ORB& orb = Poco::RemotingNG::ORB::instance();
	Poco::RemotingNG::Context::Ptr pContext = Poco::RemotingNG::Context::get();
	std::string uri = pContext->getValue<std::string>("uri");
	std::string proto = pContext->getValue<std::string>("transport");
	Poco::RemotingNG::EventDispatcher::Ptr pED = orb.findEventDispatcher(uri, proto);
	pED->setEventFilter<double>(subscriberURI, "valueChanged", pFilter);
}


} } // namespace IoT::Devices
