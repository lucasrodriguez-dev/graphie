#include "Arista.h"

Arista::Arista(int destino, float costo = 1) {
    this->destino = destino;
    this->costo = costo;
}

int Arista::getDestino() const {
    return destino;
}

float Arista::getCosto() const {
    return costo;
}