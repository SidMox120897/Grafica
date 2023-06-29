#include "recta.h"

recta::recta()
{
}

recta::recta(punto I,punto F)
{
    this->I=I;
    this->F=F;
}

recta::recta(float x1,float y1,float x2,float y2)
{
    this->I=punto(x1,y1,0);
    this->F=punto(x2,y2,0);
}

recta::recta(float x1,float y1,float z1,float x2,float y2,float z2)
{
    this->I=punto(x1,y1,z1);
    this->F=punto(x2,y2,z2);
}


void recta::Imprimir()
{
}

void recta::DibujarRecta(){
    
    float dx=this->F.get_x()-this->I.get_x();
    float dy=this->F.get_y()-this->I.get_y();
    
    float m = dx==0 ? 1 : dy/dx;
    //float b = 0;//this->I.get_x()-m*this->F.get_y();

    float indecX = this->I.get_x()<this->F.get_x() ? 1 : -1;
    float indecY = this->I.get_y()<this->F.get_y() ? 1 : -1;

    float x=this->I.get_x();
    float y=this->I.get_y();


    this->I.Dibujar2D();



    if( abs(dx) >= abs(dy) ){
        while( x != this->F.get_x()){
            y=y+m;
            x=x+indecX;
            punto P=punto(x,y,0);
            P.RGBf(this->Red,this->Green,this->Blue);
            P.Dibujar2D();
        }
    }else{
        while( y != this->F.get_y()){
            x=x+1/m;
            y=y+indecY;
            punto P=punto(x,y,0);
            P.RGBf(this->Red,this->Green,this->Blue);

            P.Dibujar2D();
        }
    }
    
    this->F.Dibujar2D();
}

void recta::DibujarRectaBresenham(){

    float dx=abs(this->F.get_x()-this->I.get_x());
    float dy=abs(this->F.get_y()-this->I.get_y());

    float indecX = this->I.get_x()<this->F.get_x() ? 1 : -1;
    float indecY = this->I.get_y()<this->F.get_y() ? 1 : -1;

    float err=dx-dy;

    float x=this->I.get_x();
    float y=this->I.get_y();

    while (x!=this->F.get_x() || y!=this->F.get_y())
    {
        float err2=2*err;
        if(err2>-dy){
            err-=dy;
            x+=indecX;
        }
        if(err2<dx){
            err+=dx;
            y+=indecY;
        }
        punto P=punto(x,y,0);
        P.RGBf(this->Red,this->Green,this->Blue);
        P.Dibujar2D();
    }
    

}

void recta::DibujarRectaPuntoMedio(){
    float dx=this->F.get_x()-this->I.get_x();
    float dy=this->F.get_y()-this->I.get_y();

    float d=2*dy-dx;

    float incrE=2*dy;
    float incrNE=2*(dy-dx);

    float x=this->I.get_x();
    float y=this->I.get_y();

    while (x<this->F.get_x())
    {
        if(d<=0){
            d+=incrE;
        }else{
            d+=incrNE;
            y++;
        }
        x++;
        punto P=punto(x,y,0);
        P.Dibujar2D();
    }
    


}


recta::~recta()
{
}

