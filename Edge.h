#pragma once

#ifndef EDGE
#define EDGE

#include <iostream>

using namespace std;

class Edge {
protected:
	string reason;
	int destination, weight;

public:
	Edge(int destination, int weight);
	Edge(int destination, string reason);
	~Edge();
	int getNodeDestination();
	int getWeight();
	string getReason();
};

#endif // EDGE