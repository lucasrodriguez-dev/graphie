#include "modelo/Grafo.h"
#include <stdexcept>
#include <algorithm>
using std::runtime_error, std::find;

Grafo::Grafo(size_t V = 0, bool dirigido = false): salientes_(V), dirigido(dirigido) {}

//pre: no existe en G una arista de origen a destino
void Grafo::agregarArista(Nodo origen, Nodo destino, Peso p = 1) {
    salientes_[origen].push_back({destino, p});
    if(!esDirigido){
        salientes_[destino].push_back({origen, p});
    }
}

void Grafo::eliminarDeSalientes(Nodo origen, Nodo destino) {
    auto salientes_origen = salientes_[origen];
    for(auto it = salientes_origen.begin(); it != salientes_origen.end(); ++it){
        if(it->first == destino){
            salientes_origen.erase(it);
            break;
        }
    }
}

void Grafo::eliminarArista(Nodo origen, Nodo destino) {
    eliminarDeSalientes(origen, destino);
    if(!esDirigido){
        eliminarDeSalientes(destino, origen);
    }
}

vector<Arista> Grafo::salientes(Nodo u) const {
    return salientes_[u];
}

vector<Arista> Grafo::entrantes(Nodo u) const {
    if(!esDirigido){
        return salientes_[u];
    }
    vector<Arista> res;
    size_t size = cantidadNodos();
    for(Nodo origen = 0; origen < size; origen++){
        auto salientes_origen = salientes_[origen];
        for(auto& [destino, peso]: salientes_origen){
            if(destino == u){
                res.push_back({destino, peso});
            }
        }
    }
    return res;
}

bool Grafo::esDirigido() const {
    return dirigido;
}

size_t Grafo::cantidadNodos() const {
    return salientes_.size();
}