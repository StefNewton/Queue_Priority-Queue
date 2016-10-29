#pragma once

/*
Name:					Stefani Moore
Last Date Modified:		10-17-2016
Assignment:				HW7
*/

//******************************************************
//event.h File
//
//event class declaration
//
//******************************************************

#ifndef  EVENT_H
#define EVENT_H



class Event
{
public:
	//constructor
	Event() { arrival = 0; time = 0; }

	//mutators
	void setArrival(unsigned int newArrival) { arrival = newArrival; }
	void setTime(int newTime) { time = newTime; }

	//accessors
	int getArrival() const { return arrival; }
	int getTime() const { return time; }


private:
	int arrival; //arrival event initialized to 0
	int time;
};

#endif // ! EVENT_H
