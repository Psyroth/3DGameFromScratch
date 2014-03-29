#include "stickmanClass.h"
#include <iostream>


//Constructors
stickmanClass::stickmanClass()
{

}

stickmanClass::stickmanClass(float posx, float posy, float posz, float height, float width, float depth):
posX_(posx), posY_(posy), posZ_(posz), height_(height),width_(width), depth_(depth)
{}

//Destructor
stickmanClass::~stickmanClass()
{

}

//getters
float stickmanClass::getX()
{
    return posX_;
}

float stickmanClass::getY()
{
    return posY_;
}

float stickmanClass::getZ()
{
    return posZ_;
}

float stickmanClass::getHeight()
{
    return height_;
}

float stickmanClass::getWidth()
{
    return width_;
}

float stickmanClass::getDepth()
{
    return depth_;
}

GLuint stickmanClass::getTexture()
{
    return texture1_;
}


//Setters

void stickmanClass::setX(float X)
{
    posX_ = X;
}

void stickmanClass::setY(float Y)
{
    posY_ = Y;
}

void stickmanClass::setZ(float Z)
{
    posZ_ = Z;
}

void stickmanClass::setHeight(float Height)
{
    height_ = Height;
}

void stickmanClass::setWidth(float Width)
{
    width_ = Width;
}

void stickmanClass::setDepth(float Depth)
{
    depth_ = Depth;
}

void stickmanClass::setTexture(GLuint Texture)
{
    texture1_ = Texture;
}



void stickmanClass::drawStickman(float legAngle, float userForwardValue, int CharPos, float userSideValue)
{ 
    this->drawCharNeutralPos(legAngle, userForwardValue, CharPos,userSideValue);
}

void stickmanClass::drawStickman(float legAngle, int CharPos)
{
    float initLegAngle = 155;
    if(legAngle == initLegAngle)
    {
        this->drawCharNeutralPos(legAngle);
    }
    else
    {
        this->drawCharPos(legAngle, CharPos);
    }
}

void stickmanClass::drawCharNeutralPos(float legAngle)
{
    
    float height = this->getHeight();
    
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
 
    gluQuadricDrawStyle(params,GLU_FILL);
//     gluQuadricTexture(params,GL_TRUE);
    
    glTranslated(0,0,0+height);
    glRotated(0,0,0,1);
    
    //Drawing Head
    glTranslated(0,0,1);
    gluSphere(params,0.3,20,20);
    //Drawing Torso
    glTranslated(0,0,-2);
    gluCylinder(params,0.1,0.1,2,20,1);
    //Drawing Arm 1
    glTranslated(0,0,1.5);
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
//     glTranslated(0,0,-1.5);
    //Drawing Arm 1
//     glTranslated(0,0,1.5);
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
    glTranslated(0,0,-1.5);
    //Drawing Leg1
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
    //Drawing Leg2
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
 
    gluDeleteQuadric(params);
    
//     glLoadIdentity();
    
//     glRotated(0,0,0,1);
//     glTranslated(0,0,0);
    
}

void stickmanClass::drawCharPos(float legAngle, int CharPos)
{
    
    
    float height = this->getHeight();
    int legsAngle;
    switch(CharPos)
    {
//         case(0):
//             legsAngle = 130;
//         break;
//         case(1):
//             legsAngle = 140;
//         break;
//         case(2):
//             legsAngle = 150;
//         break;
//         case(3):
//             legsAngle = 160;
//         break;
//         case(4):
//             legsAngle = 170;
//         break;
//         case(5):
//             legsAngle = 180;
//         break;
//         case(6):
//             legsAngle = 170;
//         break;
//         case(7):
//             legsAngle = 160;
//         break;
//         case(8):
//             legsAngle = 150;
//         break;
//         case(9):
//             legsAngle = 140;
//         break;
//         default:
//         break;
        case(0):
            legsAngle = 110;
        break;
        case(1):
            legsAngle = 120;
        break;
        case(2):
            legsAngle = 130;
        break;
        case(3):
            legsAngle = 140;
        break;
        case(4):
            legsAngle = 150;
        break;
        case(5):
            legsAngle = 160;
        break;
        case(6):
            legsAngle = 170;
        break;
        case(7):
            legsAngle = 180;
        break;
        case(8):
            legsAngle = 170;
        break;
        case(9):
            legsAngle = 160;
        break;
        case(10):
            legsAngle = 150;
        break;
        case(11):
            legsAngle = 140;
        break;
        
        case(12):
            legsAngle = 130;
        break;
        case(13):
            legsAngle = 120;
        break;
        case(14):
            legsAngle = 110;
        break;
        default:
        break;
    }
    
    
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
 
    gluQuadricDrawStyle(params,GLU_FILL);
//     gluQuadricTexture(params,GL_TRUE);
    
    glTranslated(0,0,0+height);
//     glRotated(0,0,0,1);
    
    //Drawing Head
    glTranslated(0,0,1);
    gluSphere(params,0.3,20,20);
    //Drawing Torso
    glTranslated(0,0,-2);
    gluCylinder(params,0.1,0.1,2,20,1);
    //Drawing Arm 1
    glTranslated(0,0,1.5);
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
//     glTranslated(0,0,-1.5);
    //Drawing Arm 2
//     glTranslated(0,0,1.5);
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
    glTranslated(0,0,-1.5);
    //Drawing Leg1
    glRotated(legsAngle,0,1,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legsAngle,0,1,0);
    //Drawing Leg2
    glRotated(-legsAngle,0,1,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legsAngle,0,1,0);
 
    gluDeleteQuadric(params);
    
//     glLoadIdentity();
    
//     glRotated(0,0,0,1);
//     glTranslated(0,0,0);
    
}



void stickmanClass::drawCharNeutralPos(float legAngle, float userForwardValue, int CharPos, float userSideValue)
{
    
    float height = this->getHeight();
    
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
 
    gluQuadricDrawStyle(params,GLU_FILL);
//     gluQuadricTexture(params,GL_TRUE);
    
    glTranslated(userForwardValue,0,0+height);
    glRotated(userSideValue,0,0,1);
    
    //Drawing Head
    glTranslated(0,0,1);
    gluSphere(params,0.3,20,20);
    //Drawing Torso
    glTranslated(0,0,-2);
    gluCylinder(params,0.1,0.1,2,20,1);
    //Drawing Arm 1
    glTranslated(0,0,1.5);
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
//     glTranslated(0,0,-1.5);
    //Drawing Arm 1
//     glTranslated(0,0,1.5);
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
    glTranslated(0,0,-1.5);
    //Drawing Leg1
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
    //Drawing Leg2
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
 
    gluDeleteQuadric(params);
    
//     glLoadIdentity();
    
    glRotated(-userSideValue,0,0,1);
    glTranslated(-userForwardValue,0,0);
    
}

void stickmanClass::drawCharPos(float legAngle, float userForwardValue, int CharPos, float userSideValue)
{
    float height = this->getHeight();
    int legsAngle;
    switch(CharPos)
    {
//         case(0):
//             legsAngle = 130;
//         break;
//         case(1):
//             legsAngle = 140;
//         break;
//         case(2):
//             legsAngle = 150;
//         break;
//         case(3):
//             legsAngle = 160;
//         break;
//         case(4):
//             legsAngle = 170;
//         break;
//         case(5):
//             legsAngle = 180;
//         break;
//         case(6):
//             legsAngle = 170;
//         break;
//         case(7):
//             legsAngle = 160;
//         break;
//         case(8):
//             legsAngle = 150;
//         break;
//         case(9):
//             legsAngle = 140;
//         break;
//         default:
//         break;
        case(0):
            legsAngle = 110;
        break;
        case(1):
            legsAngle = 120;
        break;
        case(2):
            legsAngle = 130;
        break;
        case(3):
            legsAngle = 140;
        break;
        case(4):
            legsAngle = 150;
        break;
        case(5):
            legsAngle = 160;
        break;
        case(6):
            legsAngle = 170;
        break;
        case(7):
            legsAngle = 180;
        break;
        case(8):
            legsAngle = 170;
        break;
        case(9):
            legsAngle = 160;
        break;
        case(10):
            legsAngle = 150;
        break;
        case(11):
            legsAngle = 140;
        break;
        case(12):
            legsAngle = 130;
        break;
        case(13):
            legsAngle = 120;
        break;
        case(14):
            legsAngle = 110;
        break;
        default:
        break;
    }
    
    
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
 
    gluQuadricDrawStyle(params,GLU_FILL);
//     gluQuadricTexture(params,GL_TRUE);
    
    glTranslated(userForwardValue,0,0+height);
    glRotated(userSideValue,0,0,1);
    
    //Drawing Head
    glTranslated(0,0,1);
    gluSphere(params,0.3,20,20);
    //Drawing Torso
    glTranslated(0,0,-2);
    gluCylinder(params,0.1,0.1,2,20,1);
    //Drawing Arm 1
    glTranslated(0,0,1.5);
    glRotated(legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legAngle,1,0,0);
//     glTranslated(0,0,-1.5);
    //Drawing Arm 2
//     glTranslated(0,0,1.5);
    glRotated(-legAngle,1,0,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legAngle,1,0,0);
    glTranslated(0,0,-1.5);
    //Drawing Leg1
    glRotated(legsAngle,0,1,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(-legsAngle,0,1,0);
    //Drawing Leg2
    glRotated(-legsAngle,0,1,0);
    gluCylinder(params,0.1,0.1,1,20,1);
    glRotated(legsAngle,0,1,0);
 
    gluDeleteQuadric(params);
    
//     glLoadIdentity();
    
    glRotated(-userSideValue,0,0,1);
    glTranslated(-userForwardValue,0,0);
    
}