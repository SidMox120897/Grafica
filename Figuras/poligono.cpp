#include "poligono.h"
#include <iostream>
#include <bits/stdc++.h>


#define PI 3.14159265359

poligono::poligono()
{
}

poligono::poligono(std::vector<punto> V)
{
    this->V=V;
}

void poligono::addVertices(punto V)
{
    this->V.push_back(V);
}

void poligono::DibujarPoligono()
{
    for(long unsigned int i=0; i<this->V.size()-1 ;i++){
        recta R=recta(this->V[i], this->V[i+1]);
        R.DibujarRectaBresenham();
    }
    recta R=recta(this->V[V.size()-1], this->V[0]);
    R.DibujarRectaBresenham();
    for(long unsigned int i=0;i<this->V.size();i++){
        this->V[i].Dibujar2D();
    }
}


void poligono::GenerarPoligonoRegular(int N, punto C, float radio)
{
    if(this->V.size()==0){
        for(int n=0; n<N ;n++){
            int x=radio*cos(2*PI*n/N )+ C.get_x();
            int y=radio*sin(2*PI*n/N )+ C.get_y();
            punto P= punto(x,y,1);
            this->V.push_back(P);
        }
    }
}


void poligono::GenerarPoligonoCirculo(punto C, float radio)
{
    if(this->V.size()==0){
        for(float n=0.0; n<360; n=n+0.001){
            int x=radio*cos(2*PI*n);
            int y=radio*sin(2*PI*n);
            punto P= punto(x,y,1);
            this->V.push_back(P);
        }
    }
}

void poligono::GenerarPoligonoEstrella(int N, punto C, float r1,float r2){
    
    float angulo=2*PI/N;
    if(this->V.size()==0){
        for(int i=0; i<N ; i++){
            int outx=r1*cos(i*angulo )+ C.get_x();
            int outy=r1*sin(i*angulo )+ C.get_y();

            int inx=r2*cos((i+0.5)*angulo )+ C.get_x();
            int iny=r2*sin((i+0.5)*angulo )+ C.get_y();
            
            this->V.push_back(punto(outx,outy,1));
            this->V.push_back(punto(inx,iny,1));

        }
    }
}


poligono::~poligono()
{
}
