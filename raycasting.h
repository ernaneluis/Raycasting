#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "raio.h"
#include "triangulo.h"

class Raycasting
{
public:
    Raycasting();

   static float calcularT(Raio raio, Triangulo triangulo);
   static bool interceptaTriangulo(Raio raio, Triangulo triangulo);
   static bool interceptaPlano(Raio raio, Triangulo triangulo);
};

#endif // RAYCASTING_H
