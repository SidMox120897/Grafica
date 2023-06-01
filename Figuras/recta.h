
#include "punto.h"

#include <iostream>
#include <cstdlib>

#ifndef RECTA_H
#define RECTA_H

class recta :public RGB
{
private:
    punto I;
    punto F;

public:
    recta(punto I, punto F);
    recta(float x1,float y1,float x2,float y2);
    recta(float x1,float y1,float z1,float x2,float y2,float z2);

    void Imprimir();
    void DibujarRecta();
    void DibujarRectaBresenham();
    void DibujarRectaPuntoMedio();

    ~recta();
};

#endif