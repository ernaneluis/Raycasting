#ifndef MATERIAL_H
#define MATERIAL_H

#include "Angel.h"

class Material
{
public:
    Material(vec4 amb , vec4 dif, vec4 esp);

    vec4 ambiente;
    vec4 difusa;
    vec4 especular;

};

#endif // MATERIAL_H



