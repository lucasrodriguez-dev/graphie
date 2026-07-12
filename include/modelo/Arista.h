#ifndef ARISTA_H
#define ARISTA_H

class Arista {
    private:
        int destino;
        float costo;
    public:
        Arista(int destino, float costo = 1);
        int getDestino() const;
        float getCosto() const;
};

#endif