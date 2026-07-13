#include "algoritmos/BFS.h"

namespace algoritmos::componente_conexa {
    componente_capas BFS(Grafo* G, int s) {
        size_t n = G->cantidadNodos();
        vector<bool> explorado(n, false);
        explorado[s] = true;
        vector<vector<Nodo>> L;
        L[0].push_back(s);
        Grafo T(n, G->esDirigido());
        size_t i = 0;
        while(!L[i].empty()){
            for(auto u: L[i]){
                auto salientes = G->salientes(u);
                for(auto& [v, peso]: salientes){
                    if(!explorado[v]){
                        explorado[v] = true;
                        L[i+1].push_back(v);
                        T.agregarArista(u,v,peso);
                    }
                }
            }
            i++;
        }
        return componente_capas{T, L};
    }
}