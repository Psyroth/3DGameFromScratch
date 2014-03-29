#ifndef WALLCLASS_H
#define WALLCLASS_H

// #include <SDL/SDL.h>
#include <GL/gl.h>
// #include <GL/glu.h>
// #include <cstdlib>
// #include <iostream>
// #include "sdlglutils.h"

class wallClass
{
public:
    wallClass();
    wallClass(float posx, float posy, float posz, float height, float width, float depth);
    virtual ~wallClass();
    float getX();
    void setX(float X);
    float getY();
    void setY(float Y);
    float getZ();
    void setZ(float Z);
    float getHeight();
    void setHeight(float Height);
    float getWidth();
    void setWidth(float Width);
    float getDepth();
    void setDepth(float Depth);
    GLuint getTexture();
    void setTexture(GLuint Texture);
    void drawWall();
    void drawWall(float userForwardValue, float userSideValue);
private:
    float posX_;
    float posY_;
    float posZ_;
    float height_;
    float width_;
    float depth_;
    GLuint texture1_;
};

#endif // WALLCLASS_H
