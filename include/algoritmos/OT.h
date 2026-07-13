#ifndef OT_H
#define OT_H

#include <queue>
#include "modelo/Grafo.h"
using std::queue;

namespace algoritmos::orden_topologico {
    queue<Nodo> OT(Grafo* G);
}

#endif