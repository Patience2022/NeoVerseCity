#include "CityDataManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

CityDataManager::CityDataManager()
{
}

CityDataManager::~CityDataManager()
{
}

CityDataManager::CityData::CityData()
{
}

CityDataManager::CityData::CityData(int d, double pop, double energy, double traffic, int alerts)
{
	day = d; populationLevel = pop; energyUsage = energy; trafficDensity = traffic; numberOfAlerts = alerts;
}

int CityDataManager::CityData::getDay() const
{
	return day;
}

double CityDataManager::CityData::getPopulationLevel() const
{
	return populationLevel;
}

double CityDataManager::CityData::getEnergyUsage() const
{
	return energyUsage;
}

double CityDataManager::CityData::getTrafficDensity() const
{
	return trafficDensity;
}

int CityDataManager::CityData::getNumberOfAlerts() const
{
	return numberOfAlerts;
}

void CityDataManager::CityData::setDay(int d)
{
	day = d;
}

void CityDataManager::CityData::setPopulationLevel(double pop)
{
	populationLevel = pop;
}

void CityDataManager::CityData::setEnergyUsage(double energy)
{
	energyUsage = energy;
}

void CityDataManager::CityData::setTrafficDensity(double traffic)
{
	trafficDensity = traffic;
}

void CityDataManager::CityData::setNumberOfAlerts(int alerts)
{
	numberOfAlerts = alerts;
}

CityDataManager::CityLogs::CityLogs()
{
}

CityDataManager::CityLogs::CityLogs(string time, string msg)
{
	timestamp = time; message = msg;
}

string CityDataManager::CityLogs::getTimestamp() const
{
	return timestamp;
}

string CityDataManager::CityLogs::getMessage() const
{
	return message;
}

void CityDataManager::CityLogs::setTimestamp(string time)
{
	timestamp = time;
}

void CityDataManager::CityLogs::setMessage(string msg)
{
	message = msg;
}

void CityDataManager::addCityData(CityData data)
{
	cityData.push_back(data);
}

void CityDataManager::removeCityData()
{
	int day;
	cout << "Enter Day: " << endl;
	while (!(cin >> day)) {
		cout << "Day must be a number. Please enter a valid number: " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	for (auto it = cityData.begin(); it != cityData.end(); ++it) {
		if (it->getDay() == day) {
			cityData.erase(it);
			cout << "Data has been successfully deleted" << endl;
			break;
		}
		else
		{
			cout << "No data for the given day"<<endl;
		}
	}
}

CityDataManager::CityData CityDataManager::findCityData()
{
	int index;
	cout << "Enter index: "<<endl;
	while (!(cin >> index)) {
		cout << "Index must be a number. Please enter a valid number: " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (index >= 0 && index < cityData.size()) {
		return cityData[index];
	}
	else {
		cout << "Index given is out of bound" << endl;
		return CityData();
	}
}

void CityDataManager::printCityData()
{
	for (const auto& data : cityData) {
		if (cityData.size()>0) {
			cout << "Day: "<<data.getDay()<<
				"\tPopulation: " << data.getPopulationLevel() << 
				"\tEnergy: " << data.getEnergyUsage() << 
				"\tTraffic: " << data.getTrafficDensity() << 
				"\tAlerts: " << data.getNumberOfAlerts()  << endl;
		}
	}
}

CityDataManager::CityData CityDataManager::city_Data()
{
	int day;
	cout << "Enter day:  " << endl;
	cin >> day;
	double populationLevel;
	cout << "Enter number of people:  " << endl;
	cin >> populationLevel;
	double energyUsage;
	cout << "Enter energy level:  " << endl;
	cin >> energyUsage;
	double trafficDensity;
	cout << "Enter traffic:  " << endl;
	cin >> trafficDensity;
	int numberOfAlerts;
	cout << "Enter number of alerts received:  " << endl;
	cin >> numberOfAlerts;
	CityData newCityData =  CityData(day, populationLevel, energyUsage, trafficDensity, numberOfAlerts);
	return newCityData;
}

// Sorting data based on Energy levels
void CityDataManager::sortData()
{
	if (cityData.empty()) {
		cout << "There is no data available" << endl;
		return;
	}
	else {
		sort(cityData.begin(), cityData.end(), [](const CityData& a, const CityData& b) {
			return a.getEnergyUsage() < b.getEnergyUsage();
			});
	}
}
//This method is used to find data for a given day
CityDataManager::CityData CityDataManager::findByDay(int day)
{
	if (cityData.empty()) {
		cout << "There is no data available" << endl;
		return CityData();
	}
	auto it = find_if(cityData.begin(), cityData.end(), [&](const CityData& data) {
		return data.getDay() == day;
		});
	if (it != cityData.end()) {
		cout << "No data found for the given day: " << day << endl;
	}
}
//This method is used to find data with the lowest number of alerts
CityDataManager::CityData CityDataManager::findMin()
{
	if (cityData.empty()) {
		cout << "There is no data available" << endl;
		return CityData();
	}
	auto minElement = min_element(cityData.begin(), cityData.end(), [](const CityData& a, const CityData& b) {
		return a.getNumberOfAlerts() < b.getNumberOfAlerts();
		});
	if (minElement != cityData.end()) {
		cout << "The lowest number of alerts is: "<<minElement->getNumberOfAlerts() << endl;
	}
	CityData data = CityData(minElement->getDay(), minElement->getPopulationLevel(), minElement->getEnergyUsage(),
		minElement->getTrafficDensity(), minElement->getNumberOfAlerts());
	return data;
}
//This method is used to find data with the highest number of alerts
CityDataManager::CityData CityDataManager::findMax()
{
	if (cityData.empty()) {
		cout << "There is no data available" << endl;
		return CityData();
	}
	auto maxElement = max_element(cityData.begin(), cityData.end(), [](const CityData& a, const CityData& b) {
		return a.getNumberOfAlerts() < b.getNumberOfAlerts();
		});
	if (maxElement != cityData.end()) {
		cout << "The highest number of alerts is: " << maxElement->getNumberOfAlerts() << endl;
	}
	CityData data = CityData(maxElement->getDay(), maxElement->getPopulationLevel(), maxElement->getEnergyUsage(),
		maxElement->getTrafficDensity(), maxElement->getNumberOfAlerts());
	return data;
}
//This method is used to count data with number of alerts greater or equals to 10
int CityDataManager::countElements()
{
	if (cityData.empty()) {
		cout << "There is no data available" << endl;
		return 0;
	}
	int countAlerts = count_if(cityData.begin(), cityData.end(), [](const CityData& data) {
		return data.getNumberOfAlerts() >= 10;
		});
	cout << "Total elements with critical alerts are: " << countAlerts << endl;
	return countAlerts;
}

void CityDataManager::addCityLogs(CityLogs data)
{
	cityLogs.push_back(data);
	cout << "Data has been added successfully" << endl;
}

//Removing outdated logs
void CityDataManager::removeCityLog()
{
	string time;
	cout << "Enter timestamp"<<endl;
	cin >> time;
	for (auto it = cityLogs.begin(); it != cityLogs.end();)
	{
		if (it->getTimestamp() < time) {
			it = cityLogs.erase(it);
		}
		else
			++it;
	}
}

void  CityDataManager::findCityLogs()
{
	string time;
	cout << "Enter timestamp:  " << endl;
	cin >> time;
	for (auto it = cityLogs.begin(); it != cityLogs.end(); ++it) {
		if (it->getTimestamp() == time) {

			cout << "Time: " <<  it->getTimestamp()<<
				"\tMessage: " <<it->getMessage()<< endl;
		}
	};
}

void CityDataManager::printCityLog()
{

	for (const auto& data : cityLogs) {
		if (cityLogs.size() > 0) {
			cout << "Time: " << data.getTimestamp() <<
				"\tMessage: " << data.getMessage() << endl;
		}
	}
}

CityDataManager::CityLogs CityDataManager::city_Log()
{
	string time;
	string message;
	cout << "Enter timestamp:  " << endl;
	cin >> time;
	cout << "Enter message:  " << endl;
	cin >> message;
	CityLogs newCityLog = CityLogs(time, message);
	return newCityLog;
}

