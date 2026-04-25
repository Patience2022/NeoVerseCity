#include <iostream>
using namespace std;
#include "SecuritySystem.h"

	
	

SecuritySystem::SecuritySystem()
{
}

SecuritySystem::SecuritySystem(int newThreatLevel)
{
}

SecuritySystem::~SecuritySystem(){}
void SecuritySystem::setThreatLevel(int level)
{
	threatLevel = level;
}
int SecuritySystem::getThreatLevel()
{
	return threatLevel;
}
void SecuritySystem::monitorCity(){}
void SecuritySystem::processEvent() const
{
}
