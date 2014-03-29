#include "GroundClass.h"
#include <iostream>

//Constructors
GroundClass::GroundClass()
{}

GroundClass::GroundClass(float Height, float Size):
height_(Height), size_(Size)
{}

//Destructor
GroundClass::~GroundClass()
{}

//Getters
float GroundClass::getHeight()
{
    return height_;
}

float GroundClass::getSize()
{
    return size_;
}

GLuint GroundClass::getTexture()
{
    return texture_;
}

//Setters
void GroundClass::setHeight(float newHeight)
{
    height_ = newHeight;
}

void GroundClass::setSize(float newSize)
{
    size_ = newSize;
}

void GroundClass::setTexture(GLuint newTexture)
{
    texture_ = newTexture;
}

void GroundClass::drawGround(float userForwardValue, float userSideValue)
{
    
//     glTranslated(-userForwardValue,0,0);
//     glRotated(-userSideValue,0,0,1);
    glBindTexture(GL_TEXTURE_2D, this->getTexture());
    float groundSize = this->getSize();
    float groundHeight = this->getHeight();
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
        
//         glRotated(userSideValue,0,0,1);
        //upper left
        glTexCoord2d(0,10);
        glVertex3d(groundSize, -groundSize, groundHeight);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-groundSize, -groundSize, groundHeight);
        
        //lower right
        glTexCoord2d(10,0); 
        glVertex3d(-groundSize, groundSize, groundHeight);
        
        //lower left
        glTexCoord2d(10,10); 
        glVertex3d(groundSize, groundSize, groundHeight);
        
    
    glEnd();
//     glRotated(userSideValue,0,0,1);
//     glTranslated(userForwardValue,0,0);
}
