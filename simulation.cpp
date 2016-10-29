/*
Name:					Stefani Moore
Last Date Modified:		10-17-2016
Assignment:				HW7
*/

//*******************************************************************
//simulation.cpp
//
//Contains simulation class implentations 
//
//*******************************************************************

#include "simulation.h" //header file

//Bank simulation
void Simulation::bankSimulation()
{
	//priority queue of Events (int arrival,int time)
	PriorityQueue eventPriorityQueue; 

	//queue for bank line
	Queue bankLine;

	//queue for arrival times obtained from the file. Used for determining whether a time is an arrival or departure
	Queue arrival;

	//Event object 
	Event newArrivalEvent;

	int custSize = 0, sum = 0; //custSize tracks total number of customers
							   //sum used to calculate total wait time

	tellerAvailable = true; //Teller is available for a customer

	//Read from file
	std::string fileName = "input.txt";
	std::ifstream inFile;
	inFile.open(fileName);

	if (!inFile) //Error check that file open properly
	{
		std::cout << "Error: Could not open file.\n";
	}
	else
	{
		std::cout << "Simulatin Begins: \n\n";
		while (inFile >> arrivalTime >> waitTime) //read from file until there are no more times
		{
			arrival.push(arrivalTime); //push arrivalTime into a queue

			arrivalT.push_back(arrivalTime);  //vector of arrivalTime's used for wait time calculation

			newArrivalEvent.setArrival(arrivalTime); //Set event arrival time
			newArrivalEvent.setTime(waitTime); //Set event time (representing wait time)

			eventPriorityQueue.push(newArrivalEvent); //Add newArrivalEvent into eventPriorityQueue

		}
	}

	departTime.push_back(0); //Used to align depart times with arrival times for total wait time calculation

	while (!eventPriorityQueue.empty()) //Process arrival and departure events while the eventPriorityQueue is not empty
	{
		Event newEvent = eventPriorityQueue.top(); //Event object = first event in eventPriorityQueue

		currentTime = newEvent.getArrival(); //current time is either an arrival time or calculated departure time

		if (arrival.front() == currentTime) //Use arrival queue to determine if the current time matches an arrival time. If yes, process an arrival event
		{
			std::cout << "Process arrival event at time: " << currentTime << std::endl; //display arrival time
			processArrival(newEvent, eventPriorityQueue, bankLine); //Call processArrival function
			if (arrival.size() != 1) //Keeps .pop() from going out of range of the arrival queue
				arrival.pop();

			custSize++; //increment custSize to track total number of customers
		}
		else //If not an arrival time, then process a departure event
		{
			departTime.push_back(currentTime); //Track departure times
			std::cout << "Process departure event at time: " << currentTime << std::endl; //Display departure time 
			processDeparture(newEvent, eventPriorityQueue, bankLine); //Call processDeparture function
		}

	}

	
	for (int i = 0; i < custSize - 1; i++) //Loop 0 -> 10-1 to calculate total wait time
	{
		int waitT = departTime[i] - arrivalT[i]; //Wait time = departure time - arrival time

		if (waitT > 0) //Only add values > 0 to wait time sum. Values < 0 means that there was no wait involved
		{
			sum = sum + waitT;
		}
	}

	float avg = (float)sum / custSize; //Calculate average as a float and cast operand to float to get the answer of 5.6

	//Display results
	std::cout << "\nFinal Statistics: \n\n";
	std::cout << "\tNumber of people processed: " << custSize << std::endl;
	std::cout << "\tCumulative wait time: " << sum << std::endl;
	std::cout << "\tAverage wait time: " << avg << std::endl;
	std::cout << "\nSimulation Ends\n";
	inFile.close();
}

//processArrival Function
void Simulation::processArrival(Event event1, PriorityQueue & pq, Queue & line)
{
		pq.pop(); //Remove top element of priority queue

	if (!line.empty()) //only calls line.front() if line as any elements
		customer = line.front();
	else //customer = 1
		customer = 1;

	if (line.empty() && tellerAvailable) //Line and teller are open, process arrival event
	{
		departureTime = currentTime + event1.getTime(); //Use arrival and wait time to determine when the customer leaves

		Event departure; //Create temp departure Event
		departure.setArrival(departureTime); //Set new event arrival to current departure time
		pq.push(departure); //push departure time into priority queue

		tellerAvailable = false; //teller is no longer available
	}
	else
		line.push(customer); //add customer to the line queue
}

//processDeparture Function
void Simulation::processDeparture(Event event1, PriorityQueue & pq, Queue & line)
{

	Event newE; //Event object


	if (pq.size() > 2) //if size is greater than 2 use top of priority queue 
	{
		pq.pop();
		newE = pq.top();
	}
	else //use event1 for newE for departureTime calculation
	{
		pq.pop();
		newE = event1;
	}
	

	if (!line.empty()) //if line is not empty
	{
		customer = line.front(); //current customer is at the front of the line
		line.pop(); // remove first person in line
		departureTime = currentTime + newE.getTime(); //calculate departure time to be currunt time - wait time

		Event departure; //Event object
		departure.setArrival(departureTime); //Set arrival time of departure
		departure.setTime(5); //Set time (a.k.a wait time)

		pq.push(departure); //Add new departure time to priority queue


	}
	else
		tellerAvailable = true; //teller is now available
}

