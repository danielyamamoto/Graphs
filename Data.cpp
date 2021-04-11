#include "Data.h"

Data::Data(int node, int access, string ip) {
    this->node = node;
    this->access = access;
    this->ip = ip;
}

Data::~Data() { }

int Data::getNode() { return node; }

string Data::getIP() { return ip; }

ostream& operator<<(ostream& os, const Data& d) {
    os << "Nodo: " <<  d.node << "\tAccesos: " << d.access << "\tIP: " << d.ip << endl;
    return os;
}

bool operator<(const Data& d1, const Data& d2) {
    return d1.access < d2.access;
}