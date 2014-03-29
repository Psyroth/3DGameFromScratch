#include "skyClass.h"



//Constructors
skyClass::skyClass()
{}

skyClass::skyClass(float Height, float Size):
height_(Height), size_(Size)
{}

//Destructor
skyClass::~skyClass()
{}

//Getters
float skyClass::getHeight()
{
    return height_;
}

float skyClass::getSize()
{
    return size_;
}

GLuint skyClass::getTexture()
{
    return texture_;
}

//Setters
void skyClass::setHeight(float newHeight)
{
    height_ = newHeight;
}

void skyClass::setSize(float newSize)
{
    size_ = newSize;
}

void skyClass::setTexture(GLuint newTexture)
{
    texture_ = newTexture;
}

void skyClass::drawSky(float userForwardValue, float userSideValue)
{
    glTranslated(-userForwardValue,0,0);
    glRotated(-userSideValue,0,0,1);
    
    glBindTexture(GL_TEXTURE_2D, this->getTexture());
    float skySize = this->getSize();
    float skyHeight = this->getHeight();
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
        
        //upper left
        glTexCoord2d(0,10);
        glVertex3d(skySize, -skySize, skyHeight);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-skySize, -skySize, skyHeight);
        
        //lower right
        glTexCoord2d(10,0); 
        glVertex3d(-skySize, skySize, skyHeight);
        
        //lower left
        glTexCoord2d(10,10); 
        glVertex3d(skySize, skySize, skyHeight);
    
    
    glEnd();
    
    glRotated(userSideValue,0,0,1);
    glTranslated(userForwardValue,0,0);
}
