#include "algoritmos/BFS.h"
using std::vector;

namespace algoritmos::componente_conexa {
    componente_capas BFS(Grafo* G, int s) {
        size_t n = G->cantidadVertices();
        vector<bool> explorado(n, false); explorado[s] = true;
        vector<vector<int>> L;
        L[0].push_back(s);
        Grafo T(n, G->esDirigido());
        size_t i = 0;
        while(!L[i].empty()){
            for(auto u: L[i]){
                auto adyacentes = G->adyacentes(u);
                for(auto e: adyacentes){
                    int v = e.getDestino();
                    if(!explorado[v]){
                        explorado[v] = true;
                        L[i+1].push_back(v);
                        T.agregarArista(u,v,e.getCosto());
                    }
                }
            }
            i++;
        }
        return componente_capas{T, L};
    }
}