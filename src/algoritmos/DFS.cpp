#include "algoritmos/DFS.h"
#include <stack>
using std::stack;

namespace algoritmos::componente_conexa {
    Grafo DFS(Grafo* G, int s) {
        size_t n = G->cantidadNodos();
        vector<bool> explorado(n, false);
        Grafo T(n, G->esDirigido());
        stack<int> S;
        S.push(s);
        while(!S.empty()){
            int u = S.top();
            S.pop();
            if(!explorado[u]){
                explorado[u] = true;
                auto salientes = G->salientes(u);
                for(auto& [v, peso]: salientes){
                    S.push(v);
                    if(!explorado[v]){
                        T.agregarArista(u,v,peso);
                    }
                }
            }
        }
        return T;
    }
}