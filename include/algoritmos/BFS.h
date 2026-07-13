#ifndef BFS_H
#define BFS_H

#include "modelo/Grafo.h"

struct componente_capas {
    Grafo componente_conexa;
    vector<vector<Nodo>> capas;
};

namespace algoritmos::componente_conexa {
    componente_capas BFS(Grafo* G, int s);
}

#endif