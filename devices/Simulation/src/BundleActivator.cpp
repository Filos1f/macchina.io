//
// BundleActivator.cpp
//
// $Id$
//
// Copyright (c) 2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/OSP/BundleActivator.h"
#include "Poco/OSP/BundleContext.h"
#include "Poco/OSP/Bundle.h"
#include "Poco/OSP/ServiceRegistry.h"
#include "Poco/OSP/ServiceRef.h"
#include "Poco/OSP/ServiceFinder.h"
#include "Poco/OSP/PreferencesService.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/Util/Timer.h"
#include "IoT/Devices/GNSSSensorServerHelper.h"
#include "Poco/Delegate.h"
#include "Poco/ClassLibrary.h"
#include "Poco/Format.h"
#include "Poco/NumberFormatter.h"
#include "Poco/SharedPtr.h"
#include "SimulatedSensor.h"
#include "SimulatedGNSSSensor.h"
#include <vector>


using Poco::OSP::BundleContext;
using Poco::OSP::ServiceRegistry;
using Poco::OSP::ServiceRef;
using Poco::OSP::ServiceFinder;
using Poco::OSP::Properties;
using Poco::OSP::PreferencesService;


namespace IoT {
namespace Simulation {


class BundleActivator: public Poco::OSP::BundleActivator
{
public:
	BundleActivator()
	{
	}
	
	~BundleActivator()
	{
	}

	void createGNSSSensor(const SimulatedGNSSSensor::Params& params)
	{
		typedef Poco::RemotingNG::ServerHelper<IoT::Devices::GNSSSensor> ServerHelper;
		
		Poco::SharedPtr<SimulatedGNSSSensor> pGNSSSensor = new SimulatedGNSSSensor(params);
		ServerHelper::RemoteObjectPtr pGNSSSensorRemoteObject = ServerHelper::createRemoteObject(pGNSSSensor, params.id);
		
		Properties props;
		props.set("io.macchina.device", SimulatedGNSSSensor::SYMBOLIC_NAME);
		
		ServiceRef::Ptr pServiceRef = _pContext->registry().registerService(params.id, pGNSSSensorRemoteObject, props);
		_serviceRefs.push_back(pServiceRef);
	}
	
	void start(BundleContext::Ptr pContext)
	{
		_pTimer = new Poco::Util::Timer;
		_pContext = pContext;
		_pPrefs = ServiceFinder::find<PreferencesService>(pContext);
		
		std::string gpxPath = _pPrefs->configuration()->getString("simulation.gnss.gpxPath", "");
		if (!gpxPath.empty())
		{
			SimulatedGNSSSensor::Params params;
			params.id = SimulatedGNSSSensor::SYMBOLIC_NAME;
			params.gpxPath = gpxPath;
			params.loopReplay = _pPrefs->configuration()->getBool("simulation.gnss.loopReplay", true);
			params.speedUp = _pPrefs->configuration()->getDouble("simulation.gnss.speedUp", 1.0);
		
			try
			{
				createGNSSSensor(params);
			}
			catch (Poco::Exception& exc)
			{
				pContext->logger().error(Poco::format("Cannot create simulated GNSS sensor: %s", exc.displayText())); 
			}
		}
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


} } // namespace IoT::Simulation


POCO_BEGIN_MANIFEST(Poco::OSP::BundleActivator)
	POCO_EXPORT_CLASS(IoT::Simulation::BundleActivator)
POCO_END_MANIFEST
