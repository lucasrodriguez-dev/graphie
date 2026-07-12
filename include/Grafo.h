#ifndef GRAFO_H
#define GRAFO_H

#include "Arista.h"
#include <vector>
using std::vector;

class Grafo {
    private:
        size_t n;
        vector<vector<Arista>> listas_adyacencia;
        bool dirigido;
        void eliminarDeLista(int origen, int destino);
    public:
        Grafo(size_t n, bool dirigido = false);
        void agregarArista(int origen, int destino, float costo = 1);
        void eliminarArista(int origen, int destino);
        size_t getN() const;
        bool esDirigido() const;
};

#endif