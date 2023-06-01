#include "punto.h"

punto::punto()
{
}

punto::punto(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;

    this->tamanio = 1;
}

punto::~punto()
{
}

void punto::set_tamanio(float T)
{
    this->tamanio=T;
}

void punto::Imprimir()
{
}

void punto::Dibujar2D()
{
    glColor3ub(this->Red,this->Green,this->Blue);
    glPointSize(this->tamanio);
    glBegin(GL_POINTS);
    glVertex2d(this->x, this->y);
    glEnd();
}


float punto::get_x()
{
    return this->x;
}

float punto::get_y()
{
    return this->y;
}

float punto::get_z()
{
    return this->z;
}
