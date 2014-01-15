#ifndef LUZ_H
#define LUZ_H

#include "Angel.h"

class Luz
{
public:
    Luz(vec4 amb, vec4 dif, vec4 esp,vec4 pos );

    vec4 ambiente;
    vec4 difusa;
    vec4 especular;
    vec4 posicao;

    //valores de atenuacao
    float a; // atenuacao constante
    float b; // atenuacao lienar
    float c; // atenuacao quadratica


    float shininess;


};

#endif // LUZ_H
