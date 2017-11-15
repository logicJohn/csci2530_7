// CSCI 2530
// Assignment: Assignment 6
// Author:     Johnnie Hernandez
// File:       pqueue.cpp
// Tab stops:  10

/*
This program defines the prototypes in pqueue.h
While also defining 
*/


#include <cstdio>
#include "event.h"
#include "pqueue.h"

using namespace std;

/*
PQCell will be used as a node of the priority queue,
The data types of Itemtype and Priority type will be
decided in pqueue.h however will remain constant 
through out the program

The constructor will initiate the first PQCell with
the values of of x for the item, p for the priority
and Null for the next.
*/
struct PQCell{
	PQCell* next;
	PriorityType pri;
	ItemType	item;
	
	PQCell( ItemType x, PriorityType p)
	{
		pri=p;
		item=x;
		next=NULL;
	}
};

void insertCell(PQCell*& L, ItemType x, PriorityType p);


bool isEmpty(const PriorityQueue& q)
 {
	 if( q.head == NULL )
	 {
		 return true;
	 }
	 return false;
 }

void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
	insertCell(q.head,x,p);
}

void insertCell(PQCell*& L, ItemType x, PriorityType p)
{
	
	if( !L )
	{	
		
		PQCell* temp = new PQCell( x, p);
		L = temp;
	}
	else if( p <= L->pri)
	{	
		
		PQCell* temp = new PQCell( x, p);
		temp->next = L;
		L = temp;
	}
	else if( L->next == NULL )
	{	
		
		PQCell* temp = new PQCell( x, p);
		L->next->next = temp;
	}
	else 
	{
		
		insertCell(L->next, x, p);
	}
	
}

void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp)
{
	//pi(x); //item x 
	//pp(y); //priority y
	
	PQCell* temp = q.head;
	
	while( temp )
	{
		
		pi(temp->item);
		printf("\n");
		pp(temp->pri);
		printf("\n \n");
		temp=temp->next;
	}
	
}

void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
	
	PQCell* temp = q.head;
	q.head = temp->next;
	x = temp->item;
	p = temp->pri;
	delete temp;
	
}



