#include <iostream>
using namespace std;
#include "TransportSystem.h"
	void TransportSystem::manageTraffic(){}
	
	TransportSystem::TransportSystem()
	{
	}

	TransportSystem::TransportSystem(int newTrafficFlow)
	{
	}
	void TransportSystem::setTrafficFlow(int flow)
	{
		trafficFlow = flow;

	}
	int TransportSystem::getTrafficFlow() const
	{
		return trafficFlow;
	}
	void TransportSystem::processEvent() const{
	}
	TransportSystem::~TransportSystem() {}


