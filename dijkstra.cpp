// CSCI 2530
// Assignment: 7
// Author:     Johnnie Hernandez
// File:       dijkstra.cpp
// Tab stops:  8

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
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
	int s; //shortest distance to start vertex
	int f; //start?
	Vertex()
	{
		head = NULL;
		s = -1
		f = -1
	}
};

struct Graph{
	int numV; //num of Verticies
	int numE; //num of Edges
	Vertex* arrayV; //Array of Verticies
	Graph(int n)
	{
		numV=n;
		numE=0
		arrayV = new Vertex[n+1];
	}
}

void readGraph( Graph& g );
void insertEdge( Graph& g, int a, int b, int c );
void printGraph( Graph& g );

int main(int argc, char** argv)
{
  return 0;
}

void readGraph( Graph& g)
{
	int a, b;
	scanf("%d" , g.numV);
	for(int i = 1; i >= 1&& g.numV >= 1; i++)
	{
		scanf("%d %d %d", a, b, c);
		insertGraph( g, a, b, c);
	}
	scanf("%d %d", a, b)
}

void insertEdge(g, a, b, c)
{
	Edge* temp = new edge(NULL, a, b, c);
	Edge* counter = g.arrayV[a].head;
	while(counter->next != NULL)
	{
		counter = counter->next;
	}
	counter->next= temp;
}

void printGraph( Graph& g )
{
	
}

