
#include "pch.h"
#include <iostream>
#include"Graph.h"
#include<string>
using namespace std;

int main()
{

	Graph g1(7);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 7);
	g1.display();
	g1.coloring();

	return 0;
}
