// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       event.h
// Tab stops:  8

#include <cstdio>
#include pqueue.h

#ifndef EVENT_H
#define EVENT_H

//documentation for type Event


struct Event{
	int sender;
	int reciever;
	double time;
};
typedef Event* ItemType;

#endif