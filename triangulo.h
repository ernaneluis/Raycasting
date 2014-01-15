#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Angel.h"


class Triangulo
{
public:
    Triangulo(vec4 *_p1,  vec4 *_p2,  vec4 *_p3, vec4 _cor);
    Triangulo(vec4 *_p1,  vec4 *_p2,  vec4 *_p3);

    void recalculaNormal();


    vec4 *p1,*p2,*p3; //pontos
    vec4 normal;
    vec4 cor;
    float t;


};

#endif // TRIANGULO_H


