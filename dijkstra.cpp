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
	int w; //weight w
	Edge( Edge* n, int a, int b, int c)
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
		arrayV = new Vertex[n+1];
		for(int i = 0; i <= n ; i++)
		{
			arrayV[i].head = NULL;
		}
	}
};


Graph readGraph();
void insertEdge(Graph& v, int a, int b, double c );
void printGraph(Graph& g );
void printEdge(Edge* v );
void sendSignal (int u, int v, int t, Event* q);
void propergateSignal( Graph& g, int v, Event* q);
void findDijkstra( Graph& g);



int main(int argc, char* argv[])
{
	if( argc > 1 )
	{
		if(argv[1] == "t")
		{
			traceEnable = 1;
		}
		else
		{
			printf("\n usage: dijkstra [-t] \n");
			return 1;
		}
	}
	
	
	Graph g(0);
	g = readGraph();
	printGraph(g);
	
	
	Event* eventQueue = NULL;
	
	
	return 0;
}


Graph readGraph()
{
	int a, b, c;
	scanf("%i" , &a);
	Graph temp(a);
	while( a > 0 )
	{
		
		scanf(" %i %i %i ", &a, &b, &c );
		if(a>0)
		{	
			insertEdge( temp , a, b, c );
			insertEdge( temp , b, a, c );
			temp.numE++;
		}
		else {
			//store the other two numbers somewhere in here
			//at thise point you havent read the assigment
			//and dont know what to do
			
		}
	}
	return temp;
}

void insertEdge( Graph& g, int a, int b, double c )
{
	if(g.arrayV[a].head == NULL)
	{
		g.arrayV[a].head = new Edge(NULL,a,b,c);
	}
	else
	{
		Edge* temp = g.arrayV[a].head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new Edge(NULL, a, b, c);
	}
}

void printGraph( Graph& g )
{
	printf("There are %d vertices and %d edges. \n", g.numV, g.numE);
	printf("The edges are as follows. \n\n");
	for(int i = 1; i <= g.numV; i++)
	{
		printEdge(g.arrayV[i].head);
	}
}

void printEdge( Edge* v )
{
	
	Edge* temp = v;
	while( temp != NULL )
	{
		if( temp->u < temp->v || traceEnable )
		{
			printf("(%d,%d) weight %d\n",temp->u,temp->v,temp->w);
		}
	temp = temp->next;
	}
	
}



void sendSignal (int u, int v, int t, Event* q)
{
	Event* temp = new Event( u, v, t);
	Event* counter = q;
	while ( counter -> next != NULL )
	{
		counter = counter -> next;
	}
	counter -> next = temp;
	
}

//draw this out
void propergateSignal( Graph& g, int v, Event* q)
{
	Edge* temp = g.arrayV[v];
	while( temp != NULL )
	{
		temp = temp -> next;
	}
}


void findDijkstra( Graph& g)
{
	
}

