#include "algoritmos/dijkstra.h"
#include <set>
#include <queue>
using std::set, std::priority_queue, std::greater;
using Estado = std::pair<float,int>;

namespace algoritmos::camino_mas_corto::dijkstra::clasico {
    dijkstra_return dijkstra(Grafo* G, int s) {
        size_t n = G->cantidadVertices();
        set<int> S; vector<int> d; vector<int> pred;
        S.insert(s); d[s]=0; pred[s]=VERTICE_NULO;
        while(S.size() < n){
            float minimo = INF;
            int mejorU = VERTICE_NULO;
            int mejorV = VERTICE_NULO;
            for(int u: S){
                auto adyacentes = G->adyacentes(u);
                for(auto e: adyacentes){
                    int v = e.getDestino();
                    if(S.count(v)){
                        continue;
                    }
                    float candidato = d[u] + e.getCosto();
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

namespace algoritmos::camino_mas_corto::dijkstra::priorityqueue {
    dijkstra_return dijkstra(Grafo* G, int s) {
        size_t n = G->cantidadVertices();
        vector<int> d; vector<int> pred;
        for(int v = 0; v < n; v++){
            d[v]=INF;
            pred[v]=VERTICE_NULO;
        }
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
            auto adyacentes = G->adyacentes(u);
            for(auto e: adyacentes){
                int v = e.getDestino();
                float costo_hasta_v = d[u] + e.getCosto();
                if(costo_hasta_v == d[v]){
                    continue;
                }
                d[v] = costo_hasta_v;
                pred[v] = u;
            }
        }
        return dijkstra_return{pred, d};
    }
}

/*
Dijkstra(G=(V,E), s)
para todo v ∈ V
    d[v] = ∞
    pred[v] = NIL
d[s] = 0
Q = PriorityQueue()
insertar (0,s) en Q
while Q ≠ ∅
    (dist,u) = ExtractMin(Q)
    si dist > d[u]
        continuar
    para cada arista (u,v)
        si d[v] > d[u] + l(u,v)
            d[v] = d[u] + l(u,v)
            pred[v] = u
            insertar (d[v],v) en Q
return (d,pred)
*/