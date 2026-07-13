#include "algoritmos/dijkstra.h"
#include <set>
#include <queue>
using std::set, std::priority_queue, std::greater;
using Estado = std::pair<Peso,Nodo>;

namespace algoritmos::camino_mas_corto::dijkstra::clasico {
    dijkstra_return dijkstra(Grafo* G, Nodo s) {
        size_t n = G->cantidadNodos();
        set<Nodo> S;
        vector<Peso> d;
        vector<Nodo> pred;
        S.insert(s);
        d[s]=0;
        pred[s]=NODO_NULO;
        while(S.size() < n){
            Peso minimo = INF;
            Nodo mejorU = NODO_NULO;
            Nodo mejorV = NODO_NULO;
            for(Nodo u: S){
                auto salientes = G->salientes(u);
                for(auto& [v,peso]: salientes){
                    if(S.count(v)){
                        continue;
                    }
                    Peso candidato = d[u] + peso;
                    if(candidato < minimo){
                        minimo = candidato;
                        d[v]=candidato;
                        mejorU = u;
                        mejorV = v;
                    }
                }
            }
            S.insert(mejorV);
            d[mejorV]=minimo;
            pred[mejorV]=mejorU;
        }
        return dijkstra_return{pred, d};
    }
}

namespace algoritmos::camino_mas_corto::dijkstra::pq {
    dijkstra_return dijkstra(Grafo* G, Nodo s) {
        size_t n = G->cantidadNodos();
        vector<Peso> d(n,INF);
        vector<Nodo> pred(n,NODO_NULO);
        d[s]=0;
        priority_queue<Estado,vector<Estado>,greater<Estado>> Q;
        Q.push({0,s});
        while(!Q.empty()){
            auto [costo, u] = Q.top();
            Q.pop();
            //costo=d[u] si y solo si u pertenece a S
            if(costo != d[u]){
                continue;
            }
            auto salientes = G->salientes(u);
            for(auto& [v, peso]: salientes){
                Peso costo_hasta_v = d[u] + peso;
                if(costo_hasta_v < d[v]){
                    d[v] = costo_hasta_v;
                    pred[v] = u;
                    Q.push({d[v],v});
                }
            }
        }
        return dijkstra_return{pred, d};
    }
}