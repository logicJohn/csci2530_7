// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       event.h
// Tab stops:  8

#include <cstdio>


#ifndef EVENT_H
#define EVENT_H

/*
An event is the signal that will be sent
from vertex to vertex as going through
a path.  The sender will be where the vertex
comes from and the receiver will be where the 
vertex is headed.  Times will the weight off_type
each origin.
Next will go to the event follwoing this one in the
PriorityQueue/Event Queue
*/

struct Event{
	Event* next;
	int sender;
	int receiver;
	double times;
	Event(int u, int v, double t)
	{
		next = NULL;
		sender = u;
		receiver = v;
		times = t;
		
	}	
};
//typedef Event* ItemType;

#endif
