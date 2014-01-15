#ifndef CUBO_H
#define CUBO_H

#include "Angel.h"
#include "triangulo.h"
//#include "material.h"

#include <stdlib.h>
#include <list>
#include <vector>

#include <qlist.h>

class Cubo
{
public:
    Cubo();

    //static vec4 vertices[8];
   // static Triangulo triangulos[20];
    //std::vector <Triangulo> triangulos;
    QList<Triangulo> triangulos;
    QList<vec4> vertices;

    //Material mate;

    vec4 ambiente;
    vec4 difusa;
    vec4 especular;

    mat4 matriz_corrente;

    void carregarMatriz(mat4 matriz);
    void aplicarMatriz();


};

#endif // CUBO_H
