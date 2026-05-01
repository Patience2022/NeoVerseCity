#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthSystem.h"
#include "PowerSystem.h"
#include "TransportSystem.h"
#include "SecuritySystem.h"
#include "Engineer.h"
#include "EngineerManager.h"
#include "CityDataManager.h"
#include "EventProcessing.h"
#include <sstream>
#include <fstream>

using namespace std;

static void saveConfig()
{
    ofstream file("config.txt");

    file << "maxEvents\t100\n";
    file << "alertThreshold\t10\n";
    file << "systemMode\tNormal\n";
    file.close();
}

//Reading from txt file
static void loadConfigs()
{
    ifstream file("config.txt");

    string line;

    while (getline(file, line))
    {
        size_t pos = line.find("\t");

        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);

        if (key == "maxEvents")
            cout << "Max Events: " << value << endl;

        else if (key == "alertThreshold")
            cout << "Alert Threshold: " << value << endl;

        else if (key == "systemMode")
            cout << "System Mode: " << value << endl;
    }

    file.close();
}

int main()
{
    HealthSystem health;
    PowerSystem power;
    TransportSystem transport;
    SecuritySystem security;
    Engineer engineer;
    EngineerManager engManager;
    CityDataManager cityDataManager;
    EventProcessing eventProcessing;
    vector<CityComponent*> cityComponents;

     //Part 1
     //Adding or creating engineer. Done by admin
     //enginer = engManager.createEngineer();
     //engManager.addEngineer(engineer);

     //Method used to load all engineers
     //engManager.loadEngineers();

     //Login Functionality for an engineer
     //engManager.logIn();

     //Part 2 & Part 5
     //Method used to store daily sensor readings. NB: To show if data was captured successfully, cityDataManager.printCityData() must be called as well
     //auto sensorData = cityDataManager.city_Data();
     //cityDataManager.addCityData(sensorData);
    
     
     ////Method used to load sensor readings from a file
      //cityDataManager.loadCityData();
      ////Method used to sort sensor readings
      //cityDataManager.sortData();
      ////Method used to display sensor readings
      //cityDataManager.printCityData();
       //auto newCityData = cityDataManager.findByDay();
       //cout<<"Day: "<< newCityData.getDay() <<"\nPopulation: "<< newCityData.getPopulationLevel()<<"\nEnergy Level: "<<
           //newCityData.getEnergyUsage()<<"\nTraffic Density: "<<
           //newCityData.getTrafficDensity()<<"\nNumber of alerts: "<< newCityData.getNumberOfAlerts()<<endl;//Finds data for a particular day
     //cityDataManager.findMax(); //For part 5 (Finding maximum)
     //cityDataManager.findMin(); //For part 5 (Finding minimum)
     //cityDataManager.countElements();//For part 5 (Counting elements)

     //Method used to remove city data
     //cityDataManager.removeCityData();

     //Method used to store city logs. NB: To show if data was captured successfully, cityDataManager.printCityLog() must be called as well
     //auto cityLogs = cityDataManager.city_Log();
     //cityDataManager.addCityLogs(cityLogs); //Part 7 to persist city logs on city_logs.dat performed here
     //cityDataManager.exportCityLogs(); //Part 7 exporting logs to csv file
    
    //Method used to display city logs
    //cityDataManager.printCityLog();

    //Method used to remove log
    //cityDataManager.removeCityLog();

    //Part 3

    //Method used to add event NB: To show if data was captured successfully, eventProcessing.displayEvents() must be called as well
    //auto event = eventProcessing.event();
    //eventProcessing.addEvent(event);
 
    //Method used to remove event
    //eventProcessing.processEvent();
    //Method used to display events
    //eventProcessing.displayEvents();

    //Method used to add emergency events.NB: To show if data was captured successfully, eventProcessing.displayEvents() must be called as well
    //auto emergencyEvent = eventProcessing.emergencyEvent();
    //eventProcessing.addEmergency(emergencyEvent);

    //Method used to remove emergency event
    //eventProcessing.resolveEmergency();
    //Method used to display emergency events
    //eventProcessing.displayEmergencies();

    //Part 4

    // Creating different componets
 /*   cityComponents.push_back(new PowerSystem(1, "Power System", 75.0));
    cityComponents.push_back(new TransportSystem(2, "Transport System", 120));
    cityComponents.push_back(new HealthSystem(3, "Health System", 10));
    cityComponents.push_back(new SecuritySystem(4, "Security System", 5));

    cout << "\nActivating city components" << endl;

    for (auto component : cityComponents)
    {
        component->activate();
    }

    cout << "\nActivation completed" << endl;

    cout << "\nProcessing events" << endl;

    for (auto component : cityComponents)
    {
        component->processEvent(); 
    }
    cout << "\nProcessing of city components have been completed" << endl;

    cout << "\nDeactivating city components" << endl;

    for (auto component : cityComponents)
    {
        component->deactivate();
    }

    cout << "\nDeactivation completed" << endl;

    cout << "\nChecking statuses" << endl;

    for (auto component : cityComponents)
    {
        cout<<"\n"<<component->getStatus() << endl;
    }

    cout << "\nChecking statuses completed" << endl;*/

    //Performing operations for different components
 /*   for (auto component : cityComponents)
    {
        TransportSystem* transport = dynamic_cast<TransportSystem*>(component);
        PowerSystem* power = dynamic_cast<PowerSystem*>(component);
        HealthSystem* health = dynamic_cast<HealthSystem*>(component);
        SecuritySystem* security = dynamic_cast<SecuritySystem*>(component);

        if (transport != nullptr)
        {
            transport->manageTraffic(); 
        }
        if (power != nullptr)
        {
            power->supplyPower();
        }
        if (health != nullptr)
        {
            health->provideCare();
        }
        if (security != nullptr)
        {
            security->monitorCity();
        }
    }*/

    
    //Part 7 - Persisting and retrieving data on config.txt
     //saveConfig();
     //loadConfigs();
 

    return 0;
}

