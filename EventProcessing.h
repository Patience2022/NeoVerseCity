#ifndef EVENTPROCESSING_H
#define EVENTPROCESSING_H

#include <queue>
#include <string>
#include <stack>

using namespace std;

class EventProcessing
{
public:
    EventProcessing();
    ~EventProcessing();
    void setProcessedEnvents(int count);
    int getprocessedEnvents();
    void eventProcessedReport();
    void commonEvent();

    struct Event
    {
    private:
        string type;
        string description;
        string timestamp;
        int priority;

    public:
        Event();
        Event(string t, string desc, string time, int p);

        string getType() const;
        string getDescription() const;
        string getTimestamp() const;
        int getPriority() const;

        void setType(string t);
        void setDescription(string desc);
        void setTimestamp(string time);
        void setPriority(int p);
    };

    struct EmergencyEvent
    {
    private:
        string type;
        string description;
        string timestamp;
        int severityLevel;

    public:
        EmergencyEvent();
        EmergencyEvent(string t, string desc, string time, int severity);

        string getType() const;
        string getDescription() const;
        string getTimestamp() const;
        int getSeverityLevel() const;

        void setType(string t);
        void setDescription(string desc);
        void setTimestamp(string time);
        void setSeverityLevel(int severity);

    };
    void addEvent(Event eve);
    void processEvent();
    void displayEvents();
    Event event();

    
    void addEmergency(EmergencyEvent emEve);
    void resolveEmergency();
    void displayEmergencies();
    EmergencyEvent emergencyEvent();

private:
    int processedEnvents;
    queue<Event> eventQueue;               
    stack<EmergencyEvent> emergencyStack;  
};

#endif