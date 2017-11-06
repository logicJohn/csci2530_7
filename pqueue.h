// CSCI 2530
// Assignment: Assignment 6
// Author:     Johnnie Hernandez
// File:       pqueue.h
// Tab stops:  10

/*
This program will prototype the structures and functions
neccsarry for the creation and management of a priority 
queue.

A priority queue in this case will be a list of items
ordered from in non descending order.  Items can be inserted
into the priority queue and will be placed in their appropriate
position however items will only be removed from least
priority to most priorirty.

In this case we will call an item in the priority queue
ItemType, and weight/priority of each item will be labled
as PriorityType

For example: (item, weight/priority) => (ItemType, PriorityType)
and items in a priority queue will be listed as such, with no
regards to ItemType

[(1,1) (a,2) (0,3) (hello,4) (world,4)]  
*/


#ifndef PQUEUE_H
#define PQUEUE_H


#include <cstdio>

//defines the data type of ItemType and PriorityType
//To adjust the data types change them here and pqueue.h
// and pqueue.cpp will all follow
typedef const char* ItemType;
typedef double PriorityType;

typedef void (*ItemPrinter)(ItemType);
typedef void (*PriorityPrinter)(PriorityType);

/*
PQCell will be used as a node of the priority queue,
The data types of Itemtype and Prioritytype will be
decided in pqueue.h however will remain constant 
through out the program
*/
struct PQCell;

/*
This structure contains the leader of the priority queue
*/
struct PriorityQueue{
	PQCell* head;
			
	PriorityQueue()
	{
		head = NULL;
	}
};

/*
Function returns true if q is an empty priority queue
*/
bool isEmpty(const PriorityQueue& q);

/*
funtion adds a an item x to Priority Queue q, in position p  
*/
void insert(PriorityQueue& q, ItemType x, PriorityType p);

/*
function removes the first item in the priority queue and passes
Item x, and priority p as out paramters of ItemType& x, PriorityType& p
*/
void remove(PriorityQueue& q, ItemType& x, PriorityType& p);

/*
This will print each of the items in the priority queue q from 
first to last pi and pp will be used as printing functions for 
the ItemType and PriorityQueue
*/
void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp);


#endif