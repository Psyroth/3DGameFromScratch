#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include "sdlglutils.h"
#include "TrackBallCamera.h"
 
 
double angleZ = 0;
double angleY = 0;
double angleX = 0;
float heightOfGround = -1;
float legAngle = 155;
float userForwardValue = 0;
float userSideValue = 0;

GLuint texture2;
GLuint texture3;

TrackBallCamera* camera;


void Draw(int CharPos);
void DrawOtherWorld();

void DrawGround()
{
    glBindTexture(GL_TEXTURE_2D, texture2);
    int groundSize = 10;
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
        
        //upper left
        glTexCoord2d(0,10);
        glVertex3d(groundSize, -groundSize, heightOfGround);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-groundSize, -groundSize, heightOfGround);
        
        //lower right
        glTexCoord2d(10,0); 
        glVertex3d(-groundSize, groundSize, heightOfGround);
        
        //lower left
        glTexCoord2d(10,10); 
        glVertex3d(groundSize, groundSize, heightOfGround);
    
    
    glEnd();
}

void DrawSky()
{
    glBindTexture(GL_TEXTURE_2D, texture3);
    int skySize = 10;
    
    glBegin(GL_QUADS);
    
        //upper left
        glTexCoord2d(1,0);
        glVertex3d(-skySize, -skySize, skySize*5);
        
        //upper right
        glTexCoord2d(1,1);
        glVertex3d(-skySize, skySize, skySize*5);
        
        //lower right
        glTexCoord2d(0,1); 
        glVertex3d(-skySize, skySize, heightOfGround);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(-skySize, -skySize, heightOfGround);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
        //upper left
        glTexCoord2d(1,0);
        glVertex3d(skySize, -skySize, skySize*5);
        
        //upper right
        glTexCoord2d(1,1);
        glVertex3d(-skySize, -skySize, skySize*5);
        
        //lower right
        glTexCoord2d(0,1); 
        glVertex3d(-skySize, -skySize, heightOfGround);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(skySize, -skySize, heightOfGround);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
        //upper left
        glTexCoord2d(1,0);
        glVertex3d(-skySize, skySize, skySize*5);
        
        //upper right
        glTexCoord2d(1,1);
        glVertex3d(skySize, skySize, skySize*5);
        
        //lower right
        glTexCoord2d(0,1); 
        glVertex3d(skySize, skySize, heightOfGround);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(-skySize, skySize, heightOfGround);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
        //upper left
        glTexCoord2d(1,0);
        glVertex3d(skySize, -skySize, skySize*5);
        
        //upper right
        glTexCoord2d(1,1);
        glVertex3d(skySize, skySize, skySize*5);
        
        //lower right
        glTexCoord2d(0,1); 
        glVertex3d(skySize, skySize, heightOfGround);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(skySize, -skySize, heightOfGround);
    
    glEnd();
    
    
}

void DrawCharNeutralPos()
{
    
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
 
    gluQuadricDrawStyle(params,GLU_FILL);
//     gluQuadricTexture(params,GL_TRUE);
    
    glTranslated(userForwardValue,0,0);
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

void DrawCharPos(int CharPos)
{
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
    
    glTranslated(userForwardValue,0,0);
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

void stop()
{
    delete camera; //destruction de la caméra allouée dynamiquement
    SDL_Quit();
}

int firstAnimation(int argc, char *argv[])
{
    
    
    SDL_Event event;
    const Uint32 time_per_frame = 1000/50;
 
    SDL_Init(SDL_INIT_VIDEO);
    atexit(stop);
    SDL_WM_SetCaption("Testing Animation", NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
    glEnable(GL_DEPTH_TEST);
 
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)1024/768,1,1000);
    
    SDL_EnableKeyRepeat(10,10);
    
    
    
//     Dessiner();
    
    camera = new TrackBallCamera();
    camera->setScrollSensivity(0.1);
    
    Uint32 start_time, stop_time;
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
//     texture1 = loadTexture("/home/phvera/projects/testopengl/crate.jpg");
    texture2 = loadTexture("/home/phvera/projects/testopengl/ground.jpg");
    texture3 = loadTexture("/home/phvera/projects/testopengl/sky.jpeg");
//     texture4 = loadTexture("/home/phvera/projects/testopengl/earth.jpg");
 
     for (;;)
    {

        start_time = SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_p:
                    takeScreenshot("test.bmp");
                    break;
                    case SDLK_ESCAPE:
                    exit(0);
                    break;
                    case SDLK_t:
                        legAngle += 10;
                    break;
                    case SDLK_UP:
                        userForwardValue += 0.1;
                    break;
                    case SDLK_DOWN:
                        userForwardValue -= 0.1;
                    break;
                    case SDLK_RIGHT:
                        userSideValue += 5;
                    break;
                    case SDLK_LEFT:
                        userSideValue -= 5;
                    break;
                    default :
                    camera->OnKeyboard(event.key);
                }
                break;
                case SDL_MOUSEMOTION:
                camera->OnMouseMotion(event.motion);
                break;
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEBUTTONDOWN:
                camera->OnMouseButton(event.button);
                break;
            }
        }

        current_time = SDL_GetTicks();
        ellapsed_time = current_time - last_time;
        last_time = current_time;

        int intUserForwardValue = (userForwardValue)*10 ;
        int charPosition = abs(intUserForwardValue)%15;
        
        Draw(charPosition);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
            //SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}
 


void Draw(int CharPos)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
//     gluLookAt(3,4,2,0,0,0,0,0,1);
    
    camera->look();
    
//     glRotated(angleZ,0,0,1);
//     glRotated(angleY,0,1,0);
//     glRotated(angleX,1,0,0);
 
    
    DrawCharPos(CharPos);


    DrawGround();
    DrawSky();
 
    glFlush();
    SDL_GL_SwapBuffers();

}

void DrawOtherWorld()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
//     gluLookAt(3,4,2,0,0,0,0,0,1);
    
    camera->look();
    
//     glRotated(angleZ,0,0,1);
//     glRotated(angleY,0,1,0);
//     glRotated(angleX,1,0,0);
 
    
    DrawCharNeutralPos();
    DrawGround();
//     DrawSky();
 
    glFlush();
    SDL_GL_SwapBuffers();

}