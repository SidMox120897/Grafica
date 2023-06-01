#ifndef RGB_H
#define RGB_H

class RGB
{
public:
    float Red;
    float Green;
    float Blue;
    float alfa;
public:
    RGB();
    RGB(float R,float G,float B);
    RGB(float R,float G,float B, float a);

    ~RGB();
    void RGBf(float R,float G,float B);
};

#endif
