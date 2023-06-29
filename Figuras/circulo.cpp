#include "circulo.h"


circulo::circulo()
{
}


circulo::circulo(punto centro,float radio)
{
    this->centro = centro;
    this->radio=radio;
}

void circulo::dibujarBresenham(){
    float x=0;
    float y=this->radio;
    float d=3-2*this->radio;
    punto P=punto();
    P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()+y);
    P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()+y);
    P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()-y);
    P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()-y);
    P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()+x);
    P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()+x);
    P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()-x);
    P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()-x);

    while (x<=y)
    {
        if(d<=0){
            d+=4*x+6;
        }else{
            d+=4*(x-y)+10;
            y--;
        }
        x++;
            P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()+y);
            P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()+y);
            P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()-y);
            P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()-y);
            P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()+x);
            P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()+x);
            P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()-x);
            P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()-x);
    }
    

}

void circulo::dibujarPuntoMedio(){
    float x=0;
    float y=this->radio;
    float d=1-this->radio;
    float dE=3;
    float dSE=-2*this->radio+5;

    punto P=punto();
    P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()+y);
    P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()+y);
    P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()-y);
    P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()-y);


    while (y>x)
    {
        if(d<0){
            d+=dE;
            dSE+=2;
            dE+=2;
        }else{
            d+=dSE;
            dSE+=4;
            dE+=2;
            y--;
        }
        x++;
            P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()+y);
            P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()+y);
            P.Dibujar2D(this->centro.get_x()+x,this->centro.get_y()-y);
            P.Dibujar2D(this->centro.get_x()-x,this->centro.get_y()-y);
            P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()+x);
            P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()+x);
            P.Dibujar2D(this->centro.get_x()+y,this->centro.get_y()-x);
            P.Dibujar2D(this->centro.get_x()-y,this->centro.get_y()-x);
    }
    

}


circulo::~circulo()
{
}