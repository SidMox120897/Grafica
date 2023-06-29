
#include "punto.h"
#include <iostream>



#ifndef CIRCULO_H
#define CIRCULO_H

class circulo : public RGB
{

private:
    punto centro;
    float radio;
public:
    circulo();
    circulo(punto centro,float radio);
    void dibujarBresenham();
    void dibujarPuntoMedio();
    ~circulo();
};




#endif