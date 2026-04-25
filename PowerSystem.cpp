#include <iostream>
using namespace std;
#include "PowerSystem.h"


PowerSystem::PowerSystem()
{
}

PowerSystem::PowerSystem(double newPowerLevel)
{
}

PowerSystem::~PowerSystem()
{
}
void PowerSystem::setPowerLevel(double level)
	{
		powerLevel = level;
	}
	double PowerSystem::getPowerLevel()
	{
		return powerLevel;
	}
	void PowerSystem::supplyPower() {}
	void PowerSystem::processEvent() const
	{
		cout << "Processing power";
	}
