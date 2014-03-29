#ifndef SKYCLASS_H
#define SKYCLASS_H

#include <GL/gl.h>

class skyClass
{
public:
    skyClass();
    skyClass(float Height, float Size);
    virtual ~skyClass();
    float getHeight();
    float getSize();
    GLuint getTexture();
    void setHeight(float newHeight);
    void setSize(float newSize);
    void setTexture(GLuint newTexture);
    void drawSky(float userForwardValue, float userSideValue);
private:
    float height_;
    float size_;
    GLuint texture_;
};

#endif // SKYCLASS_H
