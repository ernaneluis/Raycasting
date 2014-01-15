#include "triangulo.h"
#include <iostream>
using namespace std;

Triangulo::Triangulo(vec4 *_p1, vec4 *_p2, vec4 *_p3)
{
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;

    vec4 A = (*p3-*p1);
    vec4 B = (*p2-*p1);
    //na normalizacao coordenadas homogeneas nao entra
    vec4 BxA(cross(B,A), 0.0); //regra da mao direita
    normal = normalize(BxA); //N = (P3-P0)X(P1-P0)

}

Triangulo::Triangulo(vec4 *_p1, vec4 *_p2, vec4 *_p3 ,vec4 _cor)
{
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;

    vec4 A = (*p3-*p1);
    vec4 B = (*p2-*p1);
    //na normalizacao coordenadas homogeneas nao entra
    vec4 BxA(cross(B,A), 0.0); //regra da mao direita
    normal = normalize(BxA); //N = (P3-P0)X(P1-P0)

    cor = _cor;

}

void Triangulo::recalculaNormal(){
    vec4 A = (*p3-*p1);
    vec4 B = (*p2-*p1);
    vec4 BxA(cross(B,A), 0.0);
    normal = normalize(BxA);


}


