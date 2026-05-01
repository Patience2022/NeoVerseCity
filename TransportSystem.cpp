#include <iostream>
using namespace std;
#include "TransportSystem.h"
	
	TransportSystem::TransportSystem() :CityComponent(), trafficFlow(0)
	{
	}

	TransportSystem::TransportSystem(int id, string name,int newTrafficFlow):CityComponent(id, name), trafficFlow(newTrafficFlow)
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
	void TransportSystem::manageTraffic() {
		cout << "Managing traffic "<< endl;
	}
	void TransportSystem::processEvent() const{
		cout << "Processing transport system event" << endl;
	}
	TransportSystem::~TransportSystem() {}


