#pragma once

#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include "Edge.h"
#include "Data.h"
#include "HashTable.cpp"

using namespace std;

class Graph {
public:
	Graph(string file);
	~Graph();
	void DFS();
	void BFS();
	void show();
	void FanOut();
	void FanOutMax(int size);
	void getBotmaster();

private:
	int firstNode;
	vector<list<Edge>> result;
	vector<string>nodesIPs;
	HashTable<int>ht = HashTable<int>(1000000);

	void readFile(string file);
	void loadGraph(int source, int destination, int weight);
	void loadGraph(int source, int destination, string reason);
	void DFS1(vector<bool>& mark, int node);
};

#endif // GRAPH