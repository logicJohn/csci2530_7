// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       dijkstra.cpp
// Tab stops:  8

/*
This program takes reads a weighted graph from the user as 
well as a start and finish point on the weighted graph 

Definitions:
A graph is a set of vertices contected by edges.
*/

#include <cstdio>
#include <cstring>
#include "event.h"
#include "pqueue.h"


using namespace std;

int traceEnable = 0;

/*


*/
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

/*


*/
struct Vertex{
	Edge* head;
	int t; //time
	int f; //from
	Vertex()
	{
		head = NULL;
		t = -1;
		f = -1;
	}
};

/*


*/
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


/*


*/
Graph readGraph();

/*


*/
void insertEdge(Graph& v, int a, int b, double c );

/*


*/
void printGraph(Graph& g );

/*


*/
void printEdge(Edge* v );

/*


*/
void sendSignal (int u, int v, int t, PriorityQueue& q);

/*


*/
void propergateSignal( Graph& g, int x, PriorityQueue& q);

/*


*/
void findDijkstra( Graph& g, int x, int y);

/*


*/
void deletePriorityQueue(PriorityQueue& q);

/*


*/
void showPath(Graph g, int d);

//main function, option -t enables trace
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
	int start, finish;
	scanf("%i %i", &start, &finish);
	printf("%i \n", finish);
	printGraph(g);	
	findDijkstra( g, start, finish);
	showPath(g, finish);

		
	return 0;
}

Graph readGraph()
{
	int a, b;
	double c;
	scanf("%i" , &a);
	Graph temp(a);
	scanf("%i ", &a );
	while( a > 0 )
	{
		scanf("%i %lf ", &b, &c );
		insertEdge( temp , a, b, c );
		insertEdge( temp , b, a, c );
		temp.numE++;
		scanf("%i", &a);
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

void sendSignal (int u, int v, int t, PriorityQueue& q)
{
	ItemType temp = new Event(u, v, t); 
	insert( q, temp, t );
	delete temp;
	
	if (traceEnable == 1)
	{
		printf( "t, u, v");
	}
}

//draw this out
void propergateSignal( Graph& g, int x, PriorityQueue& q)
{
	Edge* temp = g.arrayV[x].head;
	while( temp != NULL )
	{
		if( g.arrayV[temp->v].t == -1 )
		{
			sendSignal( temp->v, temp->u, g.arrayV[x].t+temp->w, q);
		}
		temp = temp -> next;
	}
}

void processEvent( Graph& g, PriorityQueue& q, Event e )
{
	
	if( g.arrayV[e.reciever].t < 0  )
	{
		
		g.arrayV[e.reciever].t = e.times;
		g.arrayV[e.reciever].f = e.sender;
		//ItemType temp = &e;
		//insert( q, temp, e.times + g.arrayV[e.sender].t);
		
		propergateSignal( g, e.reciever , q);
		if(traceEnable == 1)
		{
			printf( "event porccessed" );
			printf( "the new vetwex is" );
		}
		
	}
}

void findDijkstra( Graph& g, int start, int finish)
{
	PriorityQueue q;
	sendSignal( start, 0, 0, q );
	ItemType it;
	PriorityType pt;
	printf("you are here 1 \n");
	printf(" finish %d " , finish);
	while( g.arrayV[finish].f == -1 )
	{
		printf("you are here 2 \n");
		remove(q, it, pt); 
		processEvent( g, q, *it);
	}
	printf("you are here 3 \n");
	deletePriorityQueue(q);
}

void deletePriorityQueue(PriorityQueue& q)
{
	ItemType it;
	PriorityType pt;
	while( !isEmpty(q) )
	{
		remove( q, it, pt);		
	}
}

void showPath(Graph g, int d)
{
	int temp = g.arrayV[d].f;
	if( temp == 0 )
	{
		printf(" %d", d );
	}
	else
	{
		showPath( g, temp );
		printf(" -----> %d ", temp );
	}
}

