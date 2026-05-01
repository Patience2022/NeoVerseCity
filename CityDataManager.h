#ifndef CITYDATAMANAGER_H
#define CITYDATAMANAGER_H

#include <vector>
#include <string>
#include <list>

using namespace std;

class CityDataManager
{
public:
    CityDataManager();
    ~CityDataManager();

    // -------- CITY DATA --------
    struct CityData
    {
    private:
        int day;
        double populationLevel;
        double energyUsage;
        double trafficDensity;
        int numberOfAlerts;

    public:
        // Constructors
        CityData();
        CityData(int d, double pop, double energy, double traffic, int alerts);

        // Getters
        int getDay() const;
        double getPopulationLevel() const;
        double getEnergyUsage() const;
        double getTrafficDensity() const;
        int getNumberOfAlerts() const;

        // Setters
        void setDay(int d);
        void setPopulationLevel(double pop);
        void setEnergyUsage(double energy);
        void setTrafficDensity(double traffic);
        void setNumberOfAlerts(int alerts);
    };

    // -------- CITY LOGS --------
    struct CityLogs
    {
    private:
        string timestamp;
        string message;

    public:
        // Constructors
        CityLogs();
        CityLogs(string time, string msg);

        // Getters
        string getTimestamp() const;
        string getMessage() const;

        // Setters
        void setTimestamp(string time);
        void setMessage(string msg);
    };

    void addCityData(CityData data);
    void removeCityData();
    CityData findCityData();
    void printCityData();
    CityData city_Data();
    void sortData();
    CityData findByDay();
    CityData findMin();
    CityData findMax();
    int countElements();

    void loadCityData();

    void addCityLogs(CityLogs data);
    void removeCityLog();
    void findCityLogs();
    void printCityLog();
    CityLogs city_Log();
    void exportCityLogs();
private:
    vector<CityData> cityData;
    list<CityLogs> cityLogs;
};

#endif