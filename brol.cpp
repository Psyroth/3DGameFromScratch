#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "sdlglutils.h"
#include "TrackBallCamera.h"
#include "cubeClass.cpp"
#include "GroundClass.cpp"
#include "skyClass.cpp"
#include "wallClass.cpp"
#include "stickmanClass.cpp"
    
    
float PI = 3.141592653589793;    
    
float legAngle = 155;
float userForwardValue = 0;
float userSideValue = 0;

float xForwardValue;
float yForwardValue;
    

TrackBallCamera* camera;
GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
cubeClass* cube1 = new cubeClass(0,0,0,1,1,1);
cubeClass* cube2 = new cubeClass(-5,-5,0,1,1,1);
// cubeClass* cube3 = new cubeClass(2,0,2,1,1,1);

GroundClass* ground1 = new GroundClass(-1,50);
skyClass* sky1 = new skyClass(15,50000);

wallClass* wall1 = new wallClass(2,10,2,1,10,3);
wallClass* wall2 = new wallClass(2,-10,2,1,10,3);
wallClass* wall3 = new wallClass(13,0,2,10,1,3);
 
stickmanClass* stickman1 = new stickmanClass(0,0,0,1,0.5,0.5);

void Dessiner(int charPos);

void stop()
{
    delete camera; //destruction de la caméra allouée dynamiquement
    SDL_Quit();
}

int main()
{


    SDL_Event event;
    const Uint32 time_per_frame = 1000/50;
 
    SDL_Init(SDL_INIT_VIDEO);
    atexit(stop);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
    glEnable(GL_DEPTH_TEST);
 
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)1024/768,1,1000);
    
    SDL_EnableKeyRepeat(10,10);
    
    
    
//     Dessiner();
    
    camera = new TrackBallCamera();
    camera->setScrollSensivity(1.0);
    
    Uint32 start_time, stop_time;
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
 
    texture1 = loadTexture("/home/phvera/projects/testopengl/crate.jpg");
    texture2 = loadTexture("/home/phvera/projects/testopengl/ground.jpg");
    texture3 = loadTexture("/home/phvera/projects/testopengl/sky.jpg");
    texture4 = loadTexture("/home/phvera/projects/testopengl/BrickFacade.jpg");
    
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
                        legAngle += 1;
                    break;
                    case SDLK_UP:
//                         legAngle -= 1;
                        userForwardValue -= 0.1;
                        xForwardValue -= (cos(userSideValue*PI/180.0))*0.1;
                        yForwardValue -= (sin(userSideValue*PI/180.0))*0.1;
                    break;
                    case SDLK_DOWN:
//                         legAngle += 1;
                        userForwardValue += 0.1;
                        xForwardValue += (cos(userSideValue*PI/180.0))*0.1;
                        yForwardValue += (sin(userSideValue*PI/180.0))*0.1;
                    break;
                    case SDLK_RIGHT:
                        userSideValue += (360-5);
//                         userSideValue -= 5;
                        userSideValue = abs(userSideValue)%360;
                    break;
                    case SDLK_LEFT:
                        userSideValue += 5;
                        userSideValue = abs(userSideValue)%360;
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

        int intUserForwardValue = (userForwardValue)*10;
        int charPosition = abs(intUserForwardValue)%15;
        
        Dessiner(charPosition);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
            //SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}
 
bool collisionWallHero(wallClass* wall, stickmanClass* hero)
{
    
    //Check if Box1's max is greater than Box2's min and Box1's min is less than Box2's max
//     std::cout<<"1: "<<((wall->getX() + wall->getWidth()) > (hero->getX() - hero->getWidth())+xForwardValue)<<std::endl;
//     std::cout<<"2: "<<((wall->getX() - wall->getWidth()) < (hero->getX() + hero->getWidth())+xForwardValue)<<std::endl;
//     std::cout<<"3: "<<((wall->getY() - wall->getHeight()) < (hero->getY() + hero->getHeight())+yForwardValue)<<std::endl;
//     std::cout<<"4: "<<((wall->getY() + wall->getHeight()) > (hero->getY() - hero->getHeight())+yForwardValue)<<std::endl;
//     std::cout<<"5: "<<((wall->getZ() - wall->getDepth()) < (hero->getZ() + hero->getDepth()))<<std::endl;
//     std::cout<<"6: "<<((wall->getZ() + wall->getDepth()) > (hero->getZ() - hero->getDepth()))<<std::endl;
    return(((wall->getX() + wall->getWidth()) > (hero->getX() - hero->getWidth())+xForwardValue)
    && ((wall->getX() - wall->getWidth()) < (hero->getX() + hero->getWidth())+xForwardValue)
    && ((wall->getY() - wall->getHeight()) < (hero->getY() + hero->getHeight())+yForwardValue)
    && ((wall->getY() + wall->getHeight()) > (hero->getY() - hero->getHeight())+yForwardValue)
    && ((wall->getZ() - wall->getDepth()) < (hero->getZ() + hero->getDepth()))
    && ((wall->getZ() + wall->getDepth()) > (hero->getZ() - hero->getDepth()))
    );
}

void Dessiner(int charPos)
{
    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
//     gluLookAt(3,4,2,0,0,0,0,0,1);
    
    camera->look();
    
    glRotated(-userSideValue,0,0,1);
    glTranslated(-xForwardValue,-yForwardValue,0);
    
    ground1->setTexture(texture2);
    ground1->drawGround(userForwardValue, userSideValue);
    
    
    sky1->setTexture(texture3);
    sky1->drawSky(userForwardValue, userSideValue);
    
//     cube1->setTexture(texture1);
//     cube1->drawCube(userForwardValue, userSideValue);
//     cube2->setTexture(texture1);
//     cube2->drawCube(userForwardValue, userSideValue);
//     cube3->setTexture(texture1);
//     cube3->drawCube(userForwardValue, userSideValue);
    
    wall1->setTexture(texture1);
    wall1->drawWall(userForwardValue, userSideValue);
    wall2->setTexture(texture1);
    wall2->drawWall(userForwardValue, userSideValue);
    wall3->setTexture(texture1);
    wall3->drawWall(userForwardValue, userSideValue);
    
    GLUquadric* params = gluNewQuadric();
    glTranslated((wall3->getX() + wall3->getWidth()), (wall3->getY() - wall3->getHeight()+yForwardValue), (wall3->getZ() - wall3->getDepth()));
    gluSphere(params,0.1,20,20);
    glTranslated(-(wall3->getX() + wall3->getWidth()), -(wall3->getY() - wall3->getHeight()), -(wall3->getZ() - wall3->getDepth()));
    glTranslated((wall3->getX() - wall3->getWidth()), (wall3->getY() + wall3->getHeight()), (wall3->getZ() + wall3->getDepth()));
    gluSphere(params,0.1,20,20);
    glTranslated(-(wall3->getX() - wall3->getWidth()), -(wall3->getY() + wall3->getHeight()), -(wall3->getZ() + wall3->getDepth()));
    glTranslated((stickman1->getX() + stickman1->getWidth()+xForwardValue), (stickman1->getY() - stickman1->getHeight()+yForwardValue), (stickman1->getZ() - stickman1->getDepth()));
    gluSphere(params,0.1,20,20);
    glTranslated(-(stickman1->getX() + stickman1->getWidth()+xForwardValue), -(stickman1->getY() - stickman1->getHeight()+yForwardValue), -(stickman1->getZ() - stickman1->getDepth()));
    glTranslated((stickman1->getX() - stickman1->getWidth()+xForwardValue), (stickman1->getY() + stickman1->getHeight()+yForwardValue), (stickman1->getZ() + stickman1->getDepth()));
    gluSphere(params,0.1,20,20);
    glTranslated(-(stickman1->getX() - stickman1->getWidth()+xForwardValue), -(stickman1->getY() + stickman1->getHeight()+yForwardValue), -(stickman1->getZ() + stickman1->getDepth()));
    gluDeleteQuadric(params);

    if(collisionWallHero(wall3, stickman1) || collisionWallHero(wall1, stickman1))
    {
        std::cout<<"COLLISION!!!!!!!!!"<<std::endl;
    }
    else
    {
        std::cout<<"it's all good"<<std::endl;
    }
//     std::cout<<collisionWallHero(wall3, stickman1)<<std::endl;
    
    glTranslated(xForwardValue,yForwardValue,0);
    glRotated(userSideValue,0,0,1);
    
    
    float initLegAngle = 155;
    if(legAngle == initLegAngle)
    {
        stickman1->drawCharNeutralPos(legAngle);
        legAngle -= 1;
    }
    else
    {
        stickman1->drawCharPos(legAngle, charPos);
    }
    
//     stickman1->drawStickman(legAngle, charPos);

    
    
    glFlush();
    SDL_GL_SwapBuffers();

}