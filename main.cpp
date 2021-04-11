/*
    Las funciones están comentadas porque la consola no tiene la 
    capacidad de almacenar tantos datos dentro de ella, por lo que
    se decidió comentarlas. Esto no significa que no compile. ¡Lo hace!
    Pero si se desea utilizar las funciones es recomendable que 
    sea una por una, ya que es demasiada información en la consola.
    Y la lectura es difícil de realizarla.
*/

#include <iostream>
#include "Graph.h"

using namespace std;

int main () {    
    int size = 5;
    Graph grafo = Graph("bitacoraGrafos.txt");
    //grafo.show(); // Imprime todo el grafo
    //grafo.BFS(); // Imprime todo el BFS
    //grafo.DFS();  // Imprime tood el DFS
    //grafo.FanOut(); // Imprime el número de accesos por nodo
    cout << "<#" << to_string(size) << " IP's con más accesos/>" << endl;
    grafo.FanOutMax(size); // Imprime los accesos de [n] cantidad de nodos
    cout << "El botmaster se encuentra en la ip con más accesos, la cual es: " << endl;
    grafo.getBotmaster(); // Obtiene el botmaster 
    return 0;
}