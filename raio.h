#ifndef RAIO_H
#define RAIO_H

#include "Angel.h"


class Raio
{
public:
    Raio(const vec4& ori, const vec4& dir);

    // Retorna ponto: origem + direcao*t


    vec4 origem; //ponto
    vec4 direcao; //vetor

    int indiceTrianguloMin;
    int indiceObjetoMin;

    float t;



};

#endif // RAIO_H
