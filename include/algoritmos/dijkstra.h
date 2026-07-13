#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "modelo/Grafo.h"
#include <limits>
using std::numeric_limits;

struct dijkstra_return {
    vector<int> predecesor;
    vector<int> distancia;
};

constexpr float INF = numeric_limits<float>::infinity();

namespace algoritmos::camino_mas_corto::dijkstra::clasico {
    dijkstra_return dijkstra(Grafo* G, int s);
}

namespace algoritmos::camino_mas_corto::dijkstra::pq {
    dijkstra_return dijkstra(Grafo* G, int s);
}

#endif