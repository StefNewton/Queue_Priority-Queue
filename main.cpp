/*
Name:					Stefani Moore
Last Date Modified:		10-17-2016
Course:					CSCI 2421 - Data Structures
Assignment:				HW7
Description:			This program implements an event-driven simulation of a bank using a queue of arrival events
						and a priority queue of arrival / departure events. 

Status:					Compiles and runs via Microsoft Visual Studios Community 2015 and the csegrid.ucdenver.pvt

						**Meets all of the requirements as understood by the student**

*/

#include "simulation.h" //header file



int main()
{

	Simulation bankSim; //Simulation object

	//Run bank simulation
	bankSim.bankSimulation();


	std::cin.get(); //Pause the program before exitting
	return 0;
}