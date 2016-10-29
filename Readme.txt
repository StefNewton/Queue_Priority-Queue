*******************************************************
*  Name      :  Stefani Moore        
*  Student ID:  106789878  
*  Class     :  CSCI 2421           
*  HW#       :  7                
*  Due Date  :  Oct. 19, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program implements an event-driven simulation of a 
bank using a queue of arrival events and a priority queue 
of arrival / departure events. 


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls 
   the simulation function. 

Name:  event.h
   Contains the definition for the event class.  

Name: simulation.cpp
   Defines and implements the simulation class.  
 
Name:  simulation.h
   Contains the function definitions for the processing
   of arrival and departure events.  
 
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Microsoft Visual
   Studios Community 2015.  It was compiled, run, and tested 
   on the csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [MooreHW7]

   Now you should see a directory named homework with the files:
        main.cpp
        event.h
        simulation.cpp
	simulation.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [MooreHW7] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[queue]

4. Delete the obj files, executables, and core dump by
   %./make clean
