#include "Poco/OSP/BundleActivator.h"
#include "Poco/OSP/BundleContext.h"
#include "Poco/OSP/Bundle.h"
#include "Poco/OSP/ServiceRegistry.h"
#include "Poco/OSP/ServiceRef.h"
#include "Poco/OSP/ServiceFinder.h"
#include "Poco/OSP/PreferencesService.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/Util/Timer.h"
#include "IoT/Devices/UltraSonicDeviceServerHelper.h"
#include "Poco/Delegate.h"
#include "Poco/ClassLibrary.h"
#include "Poco/Format.h"
#include "Poco/NumberFormatter.h"
#include "Poco/SharedPtr.h"
#include "UltraSonicSensor.h"
#include <vector>

using Poco::OSP::BundleContext;
using Poco::OSP::ServiceRegistry;
using Poco::OSP::ServiceRef;
using Poco::OSP::ServiceFinder;
using Poco::OSP::Properties;
using Poco::OSP::PreferencesService;

namespace IoT
{
namespace UltraSonicSensor
{

class BundleActivator: public Poco::OSP::BundleActivator
{
public:
	BundleActivator()
	{
	}
	
	~BundleActivator()
	{
	}

	void createUltraSonicSensor(const UltraSonicSensor::Params& params)
	{
		typedef Poco::RemotingNG::ServerHelper<IoT::Devices::UltraSonicDevice> ServerHelper;
		
		Poco::SharedPtr<UltraSonicSensor> pSensor = new UltraSonicSensor(params, *_pTimer);
		ServerHelper::RemoteObjectPtr pSensorRemoteObject = ServerHelper::createRemoteObject(pSensor, params.id);
		
		Properties props;
		props.set("io.macchina.device", UltraSonicSensor::SYMBOLIC_NAME);
		
		ServiceRef::Ptr pServiceRef = _pContext->registry().registerService(params.id, pSensorRemoteObject, props);
		_serviceRefs.push_back(pServiceRef);
	}

	void start(BundleContext::Ptr pContext)
	{
		_pContext = pContext;

		UltraSonicSensor::Params params;
		params.id = UltraSonicSensor::SYMBOLIC_NAME;
		params.id += "#";
		params.id += Poco::NumberFormatter::format(_serviceRefs.size());

		params.maxRange = 400;
		params.minRange = 10;
		params.angle = 45.0;
		params.initDistanceValue = 0.0;
		params.updateRate = 1;

		createUltraSonicSensor(params);
	}
		
	void stop(BundleContext::Ptr pContext)
	{
		_pTimer->cancel(true);
		_pTimer = 0;

		for (std::vector<ServiceRef::Ptr>::iterator it = _serviceRefs.begin(); it != _serviceRefs.end(); ++it)
		{
			_pContext->registry().unregisterService(*it);
		}
		_serviceRefs.clear();

		_pPrefs = 0;
		_pContext = 0;
	}
	
private:
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
	BundleContext::Ptr _pContext;
	PreferencesService::Ptr _pPrefs;
	std::vector<ServiceRef::Ptr> _serviceRefs;
};
}
}