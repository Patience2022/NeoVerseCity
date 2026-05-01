#define _CRT_SECURE_NO_WARNINGS
#include "EventProcessing.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

EventProcessing::EventProcessing()
{
}

EventProcessing::~EventProcessing()
{
}

void EventProcessing::setProcessedEnvents(int count)
{
}

int EventProcessing::getprocessedEnvents()
{
	return 0;
}

void EventProcessing::eventProcessedReport()
{
	if (!eventQueue.empty()) {
		eventQueue.pop();
		processedEnvents++;
	}
	if (!emergencyStack.empty()) {
		emergencyStack.pop();
		processedEnvents++;
	}
	time_t now = time(0);
	char* date = ctime(&now);
	cout << "Date\t" << "Total number of Events" << endl;
	cout << date<<"\t" << getprocessedEnvents() << endl;

}

void EventProcessing::commonEvent()
{
	vector<string> types;
	int mostCommon;
	if (!eventQueue.empty()) {
		types.push_back(eventQueue.front().getType());
		eventQueue.pop();

	}
	if (!emergencyStack.empty()) {
		types.push_back(emergencyStack.top().getType());
		emergencyStack.pop();
	}
	string commonEvent = "";
	int maxCount = 0;
	if (!types.empty()) {
		for (const auto& type : types) {
			int count = count_if(types.begin(), types.end(),
				[&](const string& t) {
					return t == type;
				});
			if (count > maxCount) {
				maxCount = count;
				commonEvent = type;
			}
		}
	}
	cout << "Most common event is: " << commonEvent << " Number: " << maxCount << endl;
}

EventProcessing::Event::Event(){}

EventProcessing::Event::Event(string t, string desc, string time, int p)
{
	type = t; description = desc; timestamp = time; priority = p;
}

EventProcessing::EmergencyEvent::EmergencyEvent()
{
}

EventProcessing::EmergencyEvent::EmergencyEvent(string t, string desc, string time, int severity)
{
	type = t; description = desc; timestamp = time; severityLevel = severity;
}

string EventProcessing::Event::getType() const
{
	return type;
}
string EventProcessing::Event::getTimestamp() const {
	return timestamp;
}
int EventProcessing::Event::getPriority() const
{
	return priority;
}

string EventProcessing::Event::getDescription() const
{
	return description;
}



void EventProcessing::Event::setType(string t)
{
	type = t;
}

void EventProcessing::Event::setDescription(string desc)
{
	description = desc;
}

void EventProcessing::Event::setTimestamp(string time){
	timestamp = time;
}

void EventProcessing::Event::setPriority(int p)
{
	priority = p;
}

string EventProcessing::EmergencyEvent::getType() const
{
	return type;
}
string EventProcessing::EmergencyEvent::getDescription() const
{
	return description;
}
string EventProcessing::EmergencyEvent::getTimestamp() const
{
	return timestamp;
}
int EventProcessing::EmergencyEvent::getSeverityLevel() const
{
	return severityLevel;
}

void EventProcessing::EmergencyEvent::setType(string t)
{
	type = t;
}
void EventProcessing::EmergencyEvent::setDescription(string desc)
{
	description = desc;
}
void EventProcessing::EmergencyEvent::setTimestamp(string time)
{
	timestamp = time;
}
void EventProcessing::EmergencyEvent::setSeverityLevel(int severity)
{
	severityLevel = severity;
}
void EventProcessing::addEvent(Event eve)
{
	eventQueue.push(eve);
	ofstream eventFile("events.dat", ios::app);
	eventFile << eve.getType() << ", " << eve.getDescription() << ", " << eve.getPriority() << ", " << eve.getTimestamp() << endl;
	eventFile.close();
}

void EventProcessing::processEvent()
{
	if (eventQueue.empty()) {
		cout << "There are no events" << endl;
	}
	else {
		Event eve = eventQueue.front();
		cout << "Processing event " << eve.getType() << " " << eve.getDescription() << endl;
		eventQueue.pop();

	}
}

void EventProcessing::displayEvents()
{
	queue<Event> tempEvent = eventQueue;
	if (tempEvent.empty()) {
		cout << "There are no events";
		return;
	}
	while (!tempEvent.empty())
	{
		Event eve = tempEvent.front();

		cout << eve.getTimestamp() << " \t "
			<< eve.getType() << " \t "
			<< eve.getDescription() << " \t "
			<< eve.getPriority()
			<< endl;
		tempEvent.pop();
	}
}

void EventProcessing::addEmergency(EmergencyEvent emEve)
{
	emergencyStack.push(emEve);
}

void EventProcessing::resolveEmergency()
{
	if (emergencyStack.empty()) {
		cout << "There are no emergencies." << endl;
	}
	else {
		EmergencyEvent em = emergencyStack.top();

		cout << "Resolving Emergency: "
			<< em.getType() << " \t "
			<< em.getDescription() << endl;

		emergencyStack.pop();
	}
}

void EventProcessing::displayEmergencies()
{
	stack<EmergencyEvent> tempEvent = emergencyStack;

	while (!tempEvent.empty())
	{
		EmergencyEvent eve = tempEvent.top();

		cout << eve.getTimestamp() << " \t "
			<< eve.getType() << " \t "
			<< eve.getDescription() << " \t "
			<< eve.getSeverityLevel()
			<< endl;

		tempEvent.pop();
	}
}
EventProcessing::EmergencyEvent EventProcessing::emergencyEvent()
{
	string type;
	string description;
	string timestamp;
	int severityLevel;
	cout << "Enter type:  " << endl;
	cin >> type;
	cout << "Enter description:  " << endl;
	cin >> description;
	cout << "Enter timestamp:  " << endl;
	cin >> timestamp;
	cout << "Enter severity level:  " << endl;
	cin >> severityLevel;
	EmergencyEvent emEvent = EmergencyEvent(type, description, timestamp, severityLevel);
	return emEvent;
}

EventProcessing::Event EventProcessing::event()
{
	string type;
	string description;
	string timestamp;
	int priority;

	cout << "Press any key to add event" << endl;
	cin.ignore(10000, '\n');

	cout << "Enter type: " << endl;
	getline(cin, type);

	cout << "Enter description: " << endl;
	getline(cin, description);

	cout << "Enter timestamp: " << endl;
	getline(cin, timestamp);

	cout << "Enter priority level: " << endl;
	cin >> priority;

	cin.ignore(10000, '\n');

	Event newEvent(type, description, timestamp, priority);
	return newEvent;
}