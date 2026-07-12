#include "Grafo.h"
#include <stdexcept>
using std::runtime_error;

Grafo::Grafo(size_t n, bool dirigido = false) {
    this->n = n;
    this->dirigido = dirigido;
}

//pre: no existe en G una arista de origen a destino
void Grafo::agregarArista(int origen, int destino, float costo = 1) {
    listas_adyacencia[origen].push_back(Arista(destino, costo));
    if(!esDirigido){
        listas_adyacencia[destino].push_back(Arista(origen, costo));
    }
}

void Grafo::eliminarDeLista(int origen, int destino) {
    auto lista = listas_adyacencia[origen];
    for(auto it = lista.begin(); it != lista.end(); ++it){
        if(it->getDestino() == destino){
            lista.erase(it);
            break;
        }
    }
}

void Grafo::eliminarArista(int origen, int destino) {
    eliminarDeLista(origen, destino);
    if(!esDirigido){
        eliminarDeLista(destino, origen);
    }
}

size_t Grafo::getN() const {
    return n;
}

bool Grafo::esDirigido() const {
    return dirigido;
}