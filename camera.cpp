#include "camera.h"

Camera::Camera(const vec4& eye, const vec4& at, const vec4& up) : eye(eye), at(at), up(up)
{

}


//Transforma para as coordenadas da camera
//Coordenadas Homogenas => zero = vetor
//eye = posicao onde esta a camera
//at = poisicao absoluta para onde a camera esta vendo
//up = vetor UP
/*

   Descrição dos parâmetros: eyex, eyey e eyez são usados para definir as coordenadas x, y e z,
respectivamente, da posição da câmera (ou observador); centerx, centery e centerz são usados para definir as coordenadas x, y e z,
respectivamente, da posição do alvo, isto é, para onde o observador está olhando (normalmente, o centro da cena); upx, upy e upz são as
coordenadas x, y e z, que estabelecem o vetor up (indica o "lado de cima" de uma cena 3D) [Wright 2000].

no lookat pra frente da camera sao valore de z  negativos
 */

Raio Camera::tracarRaio(float x, float y)
{
    //incerteza no near
    vec4 direcao(x,y,this->near, 0);
    Raio R(vec4(0,0,0 ,1), direcao);
    return R;

}
