#include "RGB.h"

RGB::RGB()
{
    this->Red=255;
    this->Blue=255;
    this->Green=255;
}


RGB::RGB(float R,float G,float B)
{
    this->Red=R;
    this->Blue=G;
    this->Green=B;
}

RGB::RGB(float R,float G,float B, float a)
{
    this->Red=R;
    this->Blue=G;
    this->Green=B;
    this->alfa=a;
}

void RGB::RGBf(float R,float G,float B)
{
    this->Red=R;
    this->Blue=G;
    this->Green=B;
}


RGB::~RGB()
{
}