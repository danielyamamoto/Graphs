#include "Edge.h"

Edge::Edge(int destination, int weight) {
	this->destination = destination;
	this->weight = weight;
}

Edge::Edge(int destination, string reason) {
	this->destination = destination;
	this->reason = reason;
}

Edge::~Edge() { }

int Edge::getNodeDestination() { return destination; }

int Edge::getWeight() { return weight; }

string Edge::getReason() { return reason; }