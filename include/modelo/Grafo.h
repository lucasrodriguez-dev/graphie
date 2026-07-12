#ifndef GRAFO_H
#define GRAFO_H

#include "modelo/Arista.h"
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
        vector<Arista> adyacentes(int v) const;
        size_t getN() const;
        bool esDirigido() const;
        size_t cantidadVertices() const;
};

#endif