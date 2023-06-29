#include <iostream>
#include <cstdlib>
#include "../glad/include/glad/glad.h"

#include "RGB.h"

#ifndef PUNTO_H
#define PUNTO_H

class punto : public RGB
{
private:
    float x, y, z;
    /*No tan importante*/
    float tamanio;
    //int forma[];

public:
    punto();
    punto(float x, float y, float z);
    ~punto();
    void set_tamanio(float T);
    void Imprimir();
    void Dibujar2D();
    void Dibujar2D(float x1,float y1);

    float get_x();
    float get_y();
    float get_z();

};
#endif