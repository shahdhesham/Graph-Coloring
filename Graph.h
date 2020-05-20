#pragma once
#include"Graph.h"
#include<string>
using namespace std;

class Graph
{

public:
	class Node {
	public:
		int data;
		Node* next;//pointer to point to the start of the first edge of the edged linked list
		string vertexColor;
		bool available;
		Node(int data) {
			this->data = data;
			next = 0;
			vertexColor = "";
			available = false;
		}
		Node() {
			next = 0;
		}
		
	};
	int vertices;
	Node*adj;
	
public:
	
	Graph(int vertices);
	void addEdge(int j, int data);
	void DeleteEdge(int j, int data);
	void display();
	bool IsEmpty();
	void coloring();
	~Graph();
};