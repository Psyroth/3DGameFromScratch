#ifndef STICKMANCLASS_H
#define STICKMANCLASS_H

#include <GL/gl.h>
#include <GL/glu.h>

class stickmanClass
{
public:
    stickmanClass();
    stickmanClass(float posx, float posy, float posz, float height, float width, float depth);
    virtual ~stickmanClass();
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
    void drawStickman(float legAngle, int CharPos);
    void drawCharNeutralPos(float legAngle);
    void drawCharPos(float legAngle, int CharPos);
    void drawStickman(float legAngle, float userForwardValue, int CharPos, float userSideValue);
    void drawCharNeutralPos(float legAngle, float userForwardValue, int CharPos, float userSideValue);
    void drawCharPos(float legAngle, float userForwardValue, int CharPos, float userSideValue);
private:
    float posX_;
    float posY_;
    float posZ_;
    float height_;
    float width_;
    float depth_;
    GLuint texture1_;
};

#endif // STICKMANCLASS_H
