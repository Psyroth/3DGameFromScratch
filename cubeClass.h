#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include "sdlglutils.h"
#include "TrackBallCamera.h"


class cubeClass
{
public:
    cubeClass();
    cubeClass(float posx, float posy, float posz, float height, float width, float depth);
    virtual ~cubeClass();
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
    void drawCube(float userForwardValue, float userSideValue);
private:
    float posX_;
    float posY_;
    float posZ_;
    float height_;
    float width_;
    float depth_;
    GLuint texture1_;
};