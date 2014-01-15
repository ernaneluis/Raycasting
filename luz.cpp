#include "luz.h"

Luz::Luz(vec4 amb, vec4 dif, vec4 esp,vec4 pos )
{
    ambiente = amb;
    difusa = dif;
    especular = esp;
    posicao = pos;

    shininess = 1;

}
