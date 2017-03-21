#include "IoT/Devices/UltraSonicDeviceEventDispatcher.h"
#include "Poco/Delegate.h"
#include "Poco/RemotingNG/Deserializer.h"
#include "Poco/RemotingNG/RemotingException.h"
#include "Poco/RemotingNG/Serializer.h"
#include "Poco/RemotingNG/TypeDeserializer.h"
#include "Poco/RemotingNG/TypeSerializer.h"
#include "Poco/RemotingNG/URIUtility.h"


namespace IoT {
namespace Devices {


UltraSonicDeviceEventDispatcher::UltraSonicDeviceEventDispatcher(UltraSonicDeviceRemoteObject* pRemoteObject, const std::string& protocol):
	Poco::RemotingNG::EventDispatcher(protocol),
	_pRemoteObject(pRemoteObject)
{
	_pRemoteObject->valueChanged += Poco::delegate(this, &UltraSonicDeviceEventDispatcher::event__valueChanged);
}


UltraSonicDeviceEventDispatcher::~UltraSonicDeviceEventDispatcher()
{
	try
	{
		_pRemoteObject->valueChanged -= Poco::delegate(this, &UltraSonicDeviceEventDispatcher::event__valueChanged);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


void UltraSonicDeviceEventDispatcher::event__valueChanged(const void* pSender, const double& data)
{
	remoting__staticInitBegin(REMOTING__EVENT_NAME);
	static const std::string REMOTING__EVENT_NAME("valueChanged");
	remoting__staticInitEnd(REMOTING__EVENT_NAME);
	if (pSender)
	{
		Poco::Clock now;
		Poco::FastMutex::ScopedLock lock(_mutex);
		SubscriberMap::iterator it = _subscribers.begin();
		while (it != _subscribers.end())
		{
			if (it->second->expireTime != 0 && it->second->expireTime < now)
			{
				SubscriberMap::iterator itDel(it++);
				_subscribers.erase(itDel);
			}
			else
			{
				try
				{
					if (accept(it->second->filters, REMOTING__EVENT_NAME, data))
					{
						event__valueChangedImpl(it->first, data);
					}
				}
				catch (Poco::RemotingNG::RemoteException&)
				{
					throw;
				}
				catch (Poco::Exception&)
				{
				}
				++it;
			}
		}
	}
}


void UltraSonicDeviceEventDispatcher::event__valueChangedImpl(const std::string& subscriberURI, const double& data)
{
	remoting__staticInitBegin(REMOTING__NAMES);
	static const std::string REMOTING__NAMES[] = {"valueChanged","subscriberURI","data"};
	remoting__staticInitEnd(REMOTING__NAMES);
	Poco::RemotingNG::Transport& remoting__trans = transportForSubscriber(subscriberURI);
	Poco::ScopedLock<Poco::RemotingNG::Transport> remoting__lock(remoting__trans);
	Poco::RemotingNG::Serializer& remoting__ser = remoting__trans.beginMessage(_pRemoteObject->remoting__objectId(), _pRemoteObject->remoting__typeId(), REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	remoting__ser.serializeMessageBegin(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	Poco::RemotingNG::TypeSerializer<double >::serialize(REMOTING__NAMES[2], data, remoting__ser);
	remoting__ser.serializeMessageEnd(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	remoting__trans.sendMessage(_pRemoteObject->remoting__objectId(), _pRemoteObject->remoting__typeId(), REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
}


const std::string UltraSonicDeviceEventDispatcher::DEFAULT_NS("");
} // namespace Devices
} // namespace IoT

