#include <GL/gl.h>



class GroundClass
{
public:
    GroundClass();
    GroundClass(float Height, float Size);
    virtual ~GroundClass();
    float getHeight();
    float getSize();
    GLuint getTexture();
    void setHeight(float newHeight);
    void setSize(float newSize);
    void setTexture(GLuint newTexture);
    void drawGround(float userForwardValue, float userSideValue);
private:
    float height_;
    float size_;
    GLuint texture_;
};