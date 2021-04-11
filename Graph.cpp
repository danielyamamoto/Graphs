#include "Graph.h"

Graph::Graph(string file) {
	firstNode = 1;  
	nodesIPs.push_back("NO SOY UN NODO");
	readFile(file);	
}

Graph::~Graph() { }

// Complejidad lineal O(n)
void Graph::readFile(string file) {
	ifstream f;
	f.open(file);

	string nodes, edges;
	int numNodes, numEdges;

	getline(f, nodes, ' ');
	getline(f, edges);
	numNodes = stoi(nodes);
	numEdges = stoi(edges);
	
	string ip;

	for (int i = 1; i <= numNodes; i++) {
		getline(f, ip);
		ht.add(ip, i);
		nodesIPs.push_back(ip);

		list<Edge>entry;
		result.push_back(entry);
	}

	string mes, dia, tiempo;
	string ipOrigen, puertoOrigen, ipDestino, puertoDestino, reasonNode;
	int originNode, destinationNode;
	
	for (int i = 0; i < numEdges; i++) {
		getline(f, mes, ' ');
		getline(f, dia, ' ');
		getline(f, tiempo, ' ');
		getline(f, ipOrigen, ':');
		getline(f, puertoOrigen, ' ');
		getline(f, ipDestino, ':');
		getline(f, puertoDestino, ' ');
		getline(f, reasonNode);

		originNode = ht.get(ipOrigen);
		destinationNode = ht.get(ipDestino);

		loadGraph(originNode, destinationNode, reasonNode);
	}
}

// Complejidad lineal O(n)
void Graph::loadGraph(int origin, int destination, int weight) {
	Edge edge(destination, weight);
	result[origin - 1].push_back(edge);
}

// Complejidad lineal O(n)
void Graph::loadGraph(int origin, int destination, string reason) {
	Edge edge(destination, reason);
	result[origin - 1].push_back(edge);
}

// Complejidad O(n log n)
void Graph::DFS1(vector<bool>& mark, int node) {
	cout << node << "\t"; // Se imprime nodo
	mark[node] = true; // Se marca como visitado el nodo
	for (auto tmp : result[node - 1]) { // Se recorre la lista de adyacencia
		if (!mark[tmp.getNodeDestination()]) {
			DFS1(mark, tmp.getNodeDestination());
		}
	}
}

// Complejidad lineal O(n)
void Graph::DFS() {
	vector<bool>mark(result.size(), false);
	DFS1(mark, firstNode);
	cout << endl;
}

// Complejidad cuadrática O(n^2)
void Graph::BFS() {
	vector<bool>mark(result.size(), false);
	queue<int>stack;
	cout << firstNode << "\t";
	mark[firstNode] = true;
	stack.push(firstNode);

	while (!stack.empty()) {
		int n = stack.front();
		stack.pop();
		for (auto tmp : result[n - 1]) {
			if (!mark[tmp.getNodeDestination()]) {
				cout << tmp.getNodeDestination() << "\t";
				mark[tmp.getNodeDestination()] = true;
				stack.push(tmp.getNodeDestination());
			}
		}
	}
	cout << endl;
}

// Complejidad cuadrática O(n^2)
void Graph::show() {
	for(int i = 0; i < result.size(); i++) { 
		for(auto edge : result[i]) {
			cout << "El nodo " << to_string(i + 1) << " se conecta con el nodo " << edge.getNodeDestination() << " con la razon de " << edge.getReason() << endl;
		}
	}
}

// Complejidad lineal O(n)
void Graph::FanOut() {
	for(int i = 0; i < result.size(); i++) {
		cout << "El nodo " << to_string(i + 1) << " tuvo " << result[i].size() << " accesos" << endl;
	}
}

// Complejidad cuadrática O(n^2)
// REFENCIA DEL SORT
// https://www.tutorialspoint.com/Sorting-a-vector-of-custom-objects-using-Cplusplus-STL
void Graph::FanOutMax(int size) {
	vector<Data>datos;
	datos.push_back(Data(0, 0, "NO IP"));

	for(int i = 1; i <= result.size(); i++) {
		Data tmp = Data(i, result[i - 1].size(), nodesIPs[i]);
		datos.push_back(tmp);
	}

	sort(datos.begin(), datos.end(), [](const Data& d1, const Data& d2) {
		return d1 < d2;
	});

	for(int i = datos.size() - 1; i >= datos.size() - size; i--) {
		cout <<  datos[i];
	}
}

void Graph::getBotmaster() {
	FanOutMax(1);
}