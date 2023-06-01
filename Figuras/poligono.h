
#include "punto.h"
#include "recta.h"
#include <iostream>
#include <vector>



#ifndef POLIGONO_H
#define POLIGONO_H


class poligono : public RGB, public recta
{
private:
    std::vector<punto> V;
public:
    poligono(/* args */);
    ~poligono();
};

#endif