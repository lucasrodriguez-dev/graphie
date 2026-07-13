#include "algoritmos/OT.h"
#include <stack>
using std::stack;

namespace algoritmos::orden_topologico {
    queue<Nodo> OT(Grafo* G) {
        size_t n = G->cantidadNodos();
        vector<Nodo> i(n, 0);
        for(int u = 0; u < n; u++){
            auto aristas_desde_u = G->salientes(u);
            for(auto& [v, peso]: aristas_desde_u){
                i[v]++;
            }
        }
        stack<int> S;
        for(int v = 0; v < n; v++){
            if(i[v] == 0){
                S.push(v);
            }
        }
        queue<Nodo> resultado;
        while(!S.empty()){
            int v = S.top();
            S.pop();
            resultado.push(v);
            auto aristas_desde_v = G->salientes(v);
            for(auto& [w, peso]: aristas_desde_v){
                i[w]--;
                if(i[w] == 0){
                    S.push(w);
                }
            }
        }
        return resultado;
    }
}