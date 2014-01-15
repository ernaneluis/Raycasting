#include "raycasting.h"

using namespace std;

Raycasting::Raycasting()
{
}


float Raycasting::calcularT(Raio raio, Triangulo triangulo){
    //calculo do t => parametro da equacao parametrica da reta, ele representa a distancia do vetor
    // R(t) => P0 +t*(Pix - P0)
    // R(t) = P0 + t*D
    // t para cada plano

    float A =  dot(*triangulo.p1, triangulo.normal);

    float B =  dot(raio.direcao, triangulo.normal);
    float t =  A/B;
    return t;
}

bool Raycasting::interceptaPlano(Raio raio, Triangulo triangulo){

    raio.t = calcularT(raio,triangulo);
    if( raio.t != 0 )
        return true;
    else
        return false;

}


bool Raycasting::interceptaTriangulo(Raio raio, Triangulo triangulo)
{

        vec4 P = raio.t * raio.direcao;
        vec4 v0 = *triangulo.p3 - *triangulo.p1;
        vec4 v1 = *triangulo.p2 - *triangulo.p1;
        vec4 v2 = P - *triangulo.p1;

        // Compute dot products
        float dot00 = dot(v0, v0);
        float dot01 = dot(v0, v1);
        float dot02 = dot(v0, v2);
        float dot11 = dot(v1, v1);
        float dot12 = dot(v1, v2);

        // Compute barycentric coordinates
        float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
        float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
        float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

        // Check if point is in triangle
        if( (u >= 0) && (v >= 0) && (u + v < 1) ) return true;
        else return false;



}
