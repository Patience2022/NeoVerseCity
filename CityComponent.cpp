#include <iostream>
#include "CityComponent.h"
using namespace std;

CityComponent::CityComponent()
{
}

CityComponent::CityComponent(int id, std::string name)
{
}

void CityComponent::setComponentId(int id)
{
	componentId = id;
}

int CityComponent::getComponentId() const
{
	return componentId;
}

void CityComponent::setName(string compName)
{
	name = compName;
}

string CityComponent::getName()
{
	return name;
}

void CityComponent::activate()
{
}

void CityComponent::deactivate()
{
}

string CityComponent::getStatus()
{
	return "No resources";
}

void CityComponent::processEvent() const
{
}

CityComponent::~CityComponent()
{
}
