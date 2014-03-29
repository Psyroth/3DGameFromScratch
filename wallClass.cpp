#include "wallClass.h"


//Constructors
wallClass::wallClass()
{

}

wallClass::wallClass(float posx, float posy, float posz, float height, float width, float depth):
posX_(posx), posY_(posy), posZ_(posz), height_(height),width_(width), depth_(depth)
{}

//Destructor
wallClass::~wallClass()
{

}

//getters
float wallClass::getX()
{
    return posX_;
}

float wallClass::getY()
{
    return posY_;
}

float wallClass::getZ()
{
    return posZ_;
}

float wallClass::getHeight()
{
    return height_;
}

float wallClass::getWidth()
{
    return width_;
}

float wallClass::getDepth()
{
    return depth_;
}

GLuint wallClass::getTexture()
{
    return texture1_;
}


//Setters

void wallClass::setX(float X)
{
    posX_ = X;
}

void wallClass::setY(float Y)
{
    posY_ = Y;
}

void wallClass::setZ(float Z)
{
    posZ_ = Z;
}

void wallClass::setHeight(float Height)
{
    height_ = Height;
}

void wallClass::setWidth(float Width)
{
    width_ = Width;
}

void wallClass::setDepth(float Depth)
{
    depth_ = Depth;
}

void wallClass::setTexture(GLuint Texture)
{
    texture1_ = Texture;
}



void wallClass::drawWall()
//x,y,z center of wall.
{ 
    float x = this->getX();
    float y = this->getY();
    float z = this->getZ();
    float height = this->getHeight();
    float width = this->getWidth();
    float depth = this->getDepth();
    
    
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
}


void wallClass::drawWall(float userForwardValue, float userSideValue)
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
