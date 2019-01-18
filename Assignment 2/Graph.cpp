#include <iostream>
#include <stdio.h>
#include "Graph.hpp"

using namespace std;

Graph::Graph(int numV, int numE) {
	//constructor
	int i;
	V = numV;
	E = numE;
	adjList = new AdjList[V];
	for (i = 0; i < V; ++i) {
		adjList[i].head = NULL;
	}
}

Node* Graph::addNode(int data) {
	//creates new node with given data
	Node *node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

void Graph::addEdge(int src, int dest) {
	//adds edge to adjacency list
	Node *newNode = addNode(dest);
	Node *curr = adjList[src].head;
	if(adjList[src].head) {					//if src head exists, place a end of list
		while(curr->next) { 
			curr = curr->next;
		}
		curr->next = newNode;
	}
	else { adjList[src].head = newNode; }	//if src head does not exist, set as head of list
	return;
}

void Graph::printGraph() {
	//prints adjacency list for each node
	int i;
	for (i=1; i <= V-1; ++i) {
		Node *curr = adjList[i].head;
		cout << "\n Adjacency list for " << i << "\n head";
	
		while(curr) {
			cout << " --> " << curr->data;
			curr = curr->next;
		}
	}
	cout << "\n";
}