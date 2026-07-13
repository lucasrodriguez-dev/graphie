#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
using std::vector, std::pair;

using Nodo = size_t;
using Peso = double;
using Arista = pair<Nodo,Peso>;

constexpr Nodo NODO_NULO = -1;

class Grafo {
    private:
        vector<vector<Arista>> salientes_;
        bool dirigido;
        void eliminarDeSalientes(Nodo origen, Nodo destino);
    public:
        Grafo(size_t V = 0, bool dirigido = false);
        void agregarArista(Nodo origen, Nodo destino, Peso p = 1);
        void eliminarArista(Nodo origen, Nodo destino);
        vector<Arista> salientes(Nodo u) const;
        vector<Arista> entrantes(Nodo u) const;
        size_t cantidadNodos() const;
        //size_t cantidadAristas() const;
        bool esDirigido() const;
        //Grafo operator-(int);
};

#endif