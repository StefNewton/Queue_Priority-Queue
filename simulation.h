#pragma once
/*
Name:					Stefani Moore
Last Date Modified:		10-17-2016
Assignment:				HW7
*/

//******************************************************
//simulation.h File
//
//simulation class declaration
//
//******************************************************

#ifndef SIMULATION_H
#define SIMULATION_H

#include <queue> //priority queue
#include <iostream> //input-output stream
#include <fstream> //file stream
#include <functional> //greater
#include <vector> //vector

#include "event.h" //header

class eventCompare //used
{
public:
	bool operator()(Event& e1, Event& e2)
	{
		if (e1.getArrival() > e2.getArrival())
			return true;
		return false;
	}
};


class Simulation
{
	
public:
	typedef std::queue<int> Queue; //queue of ints for bank line
	typedef std::priority_queue<Event, std::vector<Event>, eventCompare> PriorityQueue; //priority queue for arrival and departure events


	//Constructor
	Simulation() {};

	//Member functions
	void bankSimulation();
	void processArrival(Event, PriorityQueue &, Queue &);
	void processDeparture(Event, PriorityQueue &, Queue &);

private:
	//member variables
	int arrivalTime= 0;
	int departureTime = 0;
	int waitTime = 0;
	int currentTime = 0;
	int customer = 0;

	//vectors used to calculate total wait time and average
	std::vector<int> departTime;
	std::vector<int> arrivalT;

	bool tellerAvailable = false;


};




#endif // !SIMULATION_H
