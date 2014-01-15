#include "material.h"

Material::Material(vec4 amb, vec4 dif, vec4 esp)
{
     ambiente = amb;
     difusa = dif;
     especular = esp;
}
