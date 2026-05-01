#include <iostream>
using namespace std;
#include "PowerSystem.h"


PowerSystem::PowerSystem() : powerLevel(0.00)
{
}

PowerSystem::PowerSystem(int id, string name, double level)
	: CityComponent(id, name), powerLevel(level)
{
}

PowerSystem::~PowerSystem()
{
}
void PowerSystem::setPowerLevel(double level)
	{
		powerLevel = level;
	}
	double PowerSystem::getPowerLevel() const
	{
		return powerLevel;
	}
	void PowerSystem::supplyPower() {
		cout << "Power has been restored" << endl;
	}
	void PowerSystem::processEvent() const
	{
		cout << "Processing power event";
	}
