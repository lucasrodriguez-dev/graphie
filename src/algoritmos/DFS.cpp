#include "algoritmos/DFS.h"
#include <stack>
using std::stack;

namespace algoritmos::componente_conexa {
    Grafo DFS(Grafo* G, int s) {
        size_t n = G->cantidadVertices();
        vector<bool> explorado(n, false);
        Grafo T(n, G->esDirigido());
        stack<int> S;
        S.push(s);
        while(!S.empty()){
            int u = S.top();
            S.pop();
            if(!explorado[u]){
                explorado[u] = true;
                auto adyacentes = G->adyacentes(u);
                for(auto e: adyacentes){
                    int v = e.getDestino();
                    S.push(v);
                    if(!explorado[v]){
                        T.agregarArista(u,v,e.getCosto());
                    }
                }
            }
        }
        return T;
    }
}