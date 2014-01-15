#ifndef CAMERA_H
#define CAMERA_H

#include "Angel.h"
#include "raio.h"

class Camera
{

public:
    Camera(const vec4& eye, const vec4& at, const vec4& up);

    Raio tracarRaio(float x, float y);  // Retorna um raio que parte do centro de projeção e passa pelo pixel de coordenadas (x, y) da view pane

    vec4 eye;
    vec4 up;
    vec4 at;

    vec4 upCamera;
    vec4 right;
    vec4 back;

    float near; //distancia entre observador e viewpane
};

#endif // CAMERA_H
