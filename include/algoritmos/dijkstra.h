#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "modelo/Grafo.h"
#include <limits>
using std::numeric_limits;

struct dijkstra_return {
    vector<Nodo> predecesor;
    vector<Peso> distancia;
};

constexpr float INF = numeric_limits<Peso>::infinity();

namespace algoritmos::camino_mas_corto::dijkstra::clasico {
    dijkstra_return dijkstra(Grafo* G, Nodo s);
}

namespace algoritmos::camino_mas_corto::dijkstra::pq {
    dijkstra_return dijkstra(Grafo* G, Nodo s);
}

#endif