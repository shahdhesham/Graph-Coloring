#include "pch.h"
#include "Graph.h"
#include<iostream>
#include<string>
using namespace std;

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adj = new Node[vertices];
}


Graph::~Graph()
{
	Node*pt;
	Node*pt1;



	for (int i = 0; i < vertices; i++) {
		pt = adj[i].next;
		while (pt != 0) {
			pt1 = pt->next;
			delete pt;
			pt = pt1;

		}
	}
	delete adj;
}



void Graph::addEdge(int j, int data)
{
	Node*ptr;
	if (adj[j].next == 0)
		adj[j].next = new Node(data);
	else {
		ptr = adj[j].next;
		while (ptr->next != 0)
			ptr = ptr->next;
		ptr->next = new Node(data);

	}
}
void Graph::DeleteEdge(int j, int data)
{
	Node* ptr;
	Node*ptr2;
	Node*ptr3;
	ptr = adj[j].next;
	if (adj[j].next == 0) // no edges to delete

		return; //list  is empty nothing to delete

	while (ptr->next->data != data)
		ptr = ptr->next;
	ptr3 = ptr->next;
	ptr2 = ptr3->next;
	delete ptr2;
	ptr = ptr3;
}
void Graph::display() {
	Node* ptr;
	for (int i = 0; i < vertices; i++) {
		ptr = adj[i].next;
		cout << adj[i].data <<i;
		while (ptr != 0) {
			cout << "->" << i;
			ptr = ptr->next;
		}
		cout << endl;

	}



}
//bool Graph::Search(int key)
//{
//	bool found = true;
//
//	Node * temp = first;
//	while (temp != NULL)
//	{
//		if (temp->data == key)
//		{
//			cout << "Found in vertex" << i << endl;*/
//			found = true;
//			return found;
//		}
//		
//			temp = temp->nextVertex;
//			found = false;
//
//		
//	}
//	return found;
//
//
//}
bool Graph::IsEmpty()
{
	if (adj == 0)
		return true;
	else
		return false;
}

void Graph::coloring() {
	string cr;
	string color[10] = { " red", "blue", "yellow", "green", "purple", "grey", "black", "brown", "white","orange" };
	for (int i = 0; i < vertices; i++) {
		Node*ptr = adj[i].next;
		int z = 0;
		while (ptr!= 0) {
			if (adj[i].available == false) {
				adj[i].vertexColor = color[z];
				adj[i].available = true;
			}
			else if(adj[i].vertexColor==color[z]){
				adj[ptr->data].vertexColor =color[z+1];
				adj[ptr->data].available = true;

			}
			z++;
			ptr = ptr->next;
		}
	

	}
	
	

}