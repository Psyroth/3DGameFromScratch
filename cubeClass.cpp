#include "cubeClass.h"


//Constructors
cubeClass::cubeClass()
{

}

cubeClass::cubeClass(float posx, float posy, float posz, float height, float width, float depth):
posX_(posx), posY_(posy), posZ_(posz), height_(height),width_(width), depth_(depth)
{}

//Destructor
cubeClass::~cubeClass()
{

}

//getters
float cubeClass::getX()
{
    return posX_;
}

float cubeClass::getY()
{
    return posY_;
}

float cubeClass::getZ()
{
    return posZ_;
}

float cubeClass::getHeight()
{
    return height_;
}

float cubeClass::getWidth()
{
    return width_;
}

float cubeClass::getDepth()
{
    return depth_;
}

GLuint cubeClass::getTexture()
{
    return texture1_;
}


//Setters

void cubeClass::setX(float X)
{
    posX_ = X;
}

void cubeClass::setY(float Y)
{
    posY_ = Y;
}

void cubeClass::setZ(float Z)
{
    posZ_ = Z;
}

void cubeClass::setHeight(float Height)
{
    height_ = Height;
}

void cubeClass::setWidth(float Width)
{
    width_ = Width;
}

void cubeClass::setDepth(float Depth)
{
    depth_ = Depth;
}

void cubeClass::setTexture(GLuint Texture)
{
    texture1_ = Texture;
}


void cubeClass::drawCube(float userForwardValue, float userSideValue)
//x,y,z center of cube.
{ 
    float x = this->getX()/*-userForwardValue*/;
    float y = this->getY();
    float z = this->getZ();
    float height = this->getHeight();
    float width = this->getWidth();
    float depth = this->getDepth();
    
//     glTranslated(-userForwardValue,0,0);
//     glRotated(-userSideValue,0,0,1);
    
    glBindTexture(GL_TEXTURE_2D, this->getTexture());
    
    //red surface
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
    
    
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(1,1,1);
        glVertex3d(x+width,y+height,z+depth);
        
        //lower left
        glTexCoord2d(0,0);
//         glVertex3d(1,1,-1);
        glVertex3d(x+width,y+height,z-depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(-1,1,-1);
        glVertex3d(x-width,y+height,z-depth);
        
        //upper right
        glTexCoord2d(1,1); 
//         glVertex3d(-1,1,1);
        glVertex3d(x-width,y+height,z+depth);
        
    glEnd();
    
    //green surface
    glBegin(GL_QUADS);
    
//         glColor3ub(0,255,0);
        
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(1,-1,1);
        glVertex3d(x+width,y-height,z+depth);
        
        //upper right
        glTexCoord2d(0,0);
//         glVertex3d(1,1,1);
        glVertex3d(x+width,y+height,z+depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(1,1,-1);
        glVertex3d(x+width,y+height,z-depth);
        
        //lower left
        glTexCoord2d(1,1); 
//         glVertex3d(1,-1,-1);
        glVertex3d(x+width,y-height,z-depth);
    
    glEnd();
    
    //yellow surface
    
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,0);
        
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(1,-1,1);
        glVertex3d(x+width,y-height,z+depth);
        
        //upper right
        glTexCoord2d(0,0);
//         glVertex3d(-1,-1,1);
        glVertex3d(x-width,y-height,z+depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(-1,1,1);
        glVertex3d(x-width,y+height,z+depth);
        
        //lower left
        glTexCoord2d(1,1); 
//         glVertex3d(1,1,1);
        glVertex3d(x+width,y+height,z+depth);
    
    glEnd();
    
    //white surface
//     
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,255);
        
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(1,-1,1);
        glVertex3d(x+width,y-height,z+depth);
        
        //upper right
        glTexCoord2d(0,0);
//         glVertex3d(-1,-1,1);
        glVertex3d(x-width,y-height,z+depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(-1,-1,-1);
        glVertex3d(x-width,y-height,z-depth);
        
        //lower left
        glTexCoord2d(1,1); 
//         glVertex3d(1,-1,-1);
        glVertex3d(x+width,y-height,z-depth);
    
    glEnd();
    
    //blue surface
    glBegin(GL_QUADS);
    
//         glColor3b(0,0,255);
        
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(1,-1,-1);
        glVertex3d(x+width,y-height,z-depth);
        
        //upper right
        glTexCoord2d(0,0);
//         glVertex3d(-1,-1,-1);
        glVertex3d(x-width,y-height,z-depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(-1,1,-1);
        glVertex3d(x-width,y+height,z-depth);
        
        //lower left
        glTexCoord2d(1,1); 
//         glVertex3d(1,1,-1);
        glVertex3d(x+width,y+height,z-depth);
        
    glEnd();

    //purple surface
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,255);
        
        //upper left
        glTexCoord2d(0,1);
//         glVertex3d(-1,1,1);
        glVertex3d(x-width,y+height,z+depth);
        
        //upper right
        glTexCoord2d(0,0);
//         glVertex3d(-1,-1,1);
        glVertex3d(x-width,y-height,z+depth);
        
        //lower right
        glTexCoord2d(1,0); 
//         glVertex3d(-1,-1,-1);
        glVertex3d(x-width,y-height,z-depth);
        
        //lower left
        glTexCoord2d(1,1); 
//         glVertex3d(-1,1,-1);
        glVertex3d(x-width,y+height,z-depth);
    
    glEnd();
    
//     glRotated(userSideValue,0,0,1);
//     glTranslated(userForwardValue,0,0);
}