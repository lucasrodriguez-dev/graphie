#include "algoritmos/OT.h"
#include <stack>
using std::stack;

namespace algoritmos::orden_topologico {
    queue<int> OT(Grafo* G) {
        size_t n = G->cantidadVertices();
        vector<int> i(n, 0);
        for(int u = 0; u < n; u++){
            auto aristas_desde_u = G->adyacentes(u);
            for(auto e: aristas_desde_u){
                i[e.getDestino()]++;
            }
        }
        stack<int> S;
        for(int v = 0; v < n; v++){
            if(i[v] == 0){
                S.push(v);
            }
        }
        queue<int> resultado;
        while(!S.empty()){
            int v = S.top();
            S.pop();
            resultado.push(v);
            auto aristas_desde_v = G->adyacentes(v);
            for(auto e: aristas_desde_v){
                int w = e.getDestino();
                i[w]--;
                if(i[w] == 0){
                    S.push(w);
                }
            }
        }
        return resultado;
    }
}