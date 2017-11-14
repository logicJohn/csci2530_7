// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       event.h
// Tab stops:  8

#include <cstdio>


#ifndef EVENT_H
#define EVENT_H

//documentation for type Event


struct Event{
	Event* next;
	int sender;
	int reciever;
	double times;
	Event(int u, int v, int t)
	{
		next = NULL;
		sender = u;
		reciever = v;
		times = t;
		
	}	
};
//typedef Event* ItemType;

#endif
