
#include "punto.h"
#include "recta.h"
#include <iostream>
#include <vector>



#ifndef POLIGONO_H
#define POLIGONO_H


class poligono : public RGB
{
private:
    std::vector<punto> V; /* Vertices*/
public:
    poligono();
    poligono(std::vector<punto> V);
    void addVertices(punto V);
    void DibujarPoligono();
    void GenerarPoligonoRegular(int N, punto C, float radio);
    void GenerarPoligonoCirculo(punto C, float radio);
    void GenerarPoligonoEstrella(int N, punto C, float r1,float r2);

    ~poligono();
};

#endif