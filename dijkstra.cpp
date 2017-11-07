// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       dijkstra.cpp
// Tab stops:  8

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
#include "event.h"
#include "pqueue.h"

using namespace std;

int traceEnable = 0;

struct Edge{
	Edge* next;
	int u; //vertex u
	int v; //vertex v
	double w; //weight w
	Edge( Edge* n, int a, int b, double c)
	{
		//note roads are 1 way, u=a & v=b != u=b & v=a
		next=n;
		u = a;
		v = b;
		w = c;
	}
};

struct Vertex{
	Edge* head;
	int t; //shortest time/distance to start vertex
	int f; //start?
	Vertex()
	{
		head = NULL;
		t = -1;
		f = -1;
	}
};

struct Graph{
	int numV; //num of Verticies
	int numE; //num of Edges
	Vertex* arrayV; //Array of Verticies
	Graph(int n)
	{
		numV=n;
		numE=0;
	}
};


void readGraph( Graph& g );
void insertEdge( Edge* v, int a, int b, double c );
void printGraph( Graph& g );
void printEdge( Vertex* v );


int main(int argc, char** argv)
{
	
	Graph g(0);
	readGraph(g);
	printf("print graph\n");
	printGraph(g);
	
	return 0;
}

void readGraph( Graph& g)
{
	int a, b, c;
	scanf("%i" , &g.numV);
	g.arrayV = new Vertex[g.numV+1];
	for(int i = 0; i <= g.numV; i++)
	{
		g.arrayV[i].head = NULL;
	}
	printf("insert Edge\n");
	for(int i = 1; i <= g.numV && g.numV >= 1; i++)
	{
		
		scanf("%i %i %d", &a, &b, &c);
		insertEdge( g.arrayV[i].head, a, b, c);
		g.numE++;
	}
	scanf("%d %d", &a, &b);
}

void insertEdge( Edge* v, int a, int b, double c )
{
	Edge* temp = new Edge(NULL, a, b, c);
	Edge* counter = NULL;
	while(counter->next != NULL)
	{
		printf("4\n");
		counter = counter->next;
	}
	counter->next= temp;
}

void printGraph( Graph& g )
{
	
	printf("There are %d vertices and %d edges. \n", g.numV, g.numE);
	printf("The edges are as follows. \n\n");
	for(int i = 1; i < g.numV; i++)
	{
		printEdge(g.arrayV);
	}
}

void printEdge( Vertex* v )
{
	
	Edge* temp = v->head;
	while( temp != NULL )
	{
		if( temp->u < temp->v || traceEnable )
		{
			printf("(%d,%d) weight %d\n",temp->u,temp->v,temp->w);
		}
	temp = temp->next;
	}
	
}


