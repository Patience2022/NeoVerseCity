#include <iostream>
using namespace std;
#include "SecuritySystem.h"

	
	

SecuritySystem::SecuritySystem(): threatLevel(0)
{
}

SecuritySystem::SecuritySystem(int id, string name,int newThreatLevel):CityComponent(id, name), threatLevel(newThreatLevel)
{

}

SecuritySystem::~SecuritySystem(){}
void SecuritySystem::setThreatLevel(int level)
{
	threatLevel = level;
}
int SecuritySystem::getThreatLevel() const
{
	return threatLevel;
}
void SecuritySystem::monitorCity(){
	cout << "Monitoring security at NeoVerse city" << endl;
}
void SecuritySystem::processEvent() const
{
	cout << "Processing security system event" << endl;
}
