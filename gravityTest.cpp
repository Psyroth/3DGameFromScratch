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
 

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;

TrackBallCamera* camera;


void Dessiner(int cubeHeight);
 
void drawCube1()
{
    glBegin(GL_LINE_LOOP);
        glColor3ub(0,255,0);    glVertex3d(0,0,0.5);
        glColor3ub(0,0,255);    glVertex3d(0,.5,0);
        glColor3ub(255,0,0);    glVertex3d(.5,0,0);
        glColor3ub(255,255,255);    glVertex3d(.5,-.5,.5);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glColor3ub(0,255,0);    glVertex3d(-.5,0,0.5);
        glColor3ub(0,0,255);    glVertex3d(-.5,.5,0);
        glColor3ub(255,0,0);    glVertex3d(0,0,0);
        glColor3ub(255,255,255);    glVertex3d(0,-.5,.5);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
        glColor3ub(0,0,255);    glVertex3d(0,.5,0);
        glColor3ub(0,0,255);    glVertex3d(-.5,.5,0);
        
        glColor3ub(0,255,0);    glVertex3d(-.5,0,0.5);
        glColor3ub(0,255,0);    glVertex3d(0,0,0.5);

        glColor3ub(255,0,0);    glVertex3d(0,0,0);
        glColor3ub(255,0,0);    glVertex3d(.5,0,0);

        glColor3ub(255,255,255);    glVertex3d(.5,-.5,.5);
        glColor3ub(255,255,255);    glVertex3d(0,-.5,.5);
    glEnd();
}

void drawCube2(int height)
{ 
    //red surface
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
    
    
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,1,1+height);
        
        //lower left
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,-1+height);
        
        //upper right
        glTexCoord2d(1,1); 
        glVertex3d(-1,1,1+height);
        
    glEnd();
    
    //green surface
    glBegin(GL_QUADS);
    
//         glColor3ub(0,255,0);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1+height);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(1,1,1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(1,1,-1+height);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,-1,-1+height);
    
    glEnd();
    
    //yellow surface
    
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,0);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1+height);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,1+height);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,1,1+height);
    
    glEnd();
    
    //white surface
//     
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1+height);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,-1,-1+height);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,-1,-1+height);
    
    glEnd();
    
    //blue surface
    glBegin(GL_QUADS);
    
//         glColor3b(0,0,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,-1+height);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,-1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,-1+height);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,1,-1+height);
        
    glEnd();

    //cyan surface
    glBegin(GL_QUADS);
    
//         glColor3ub(0,255,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(-1,1,1+height);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1+height);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,-1,-1+height);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(-1,1,-1+height);
    
    glEnd();
}

void DrawGround()
{
    glBindTexture(GL_TEXTURE_2D, texture2);
    int groundSize = 10;
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
        
        //upper left
        glTexCoord2d(0,10);
        glVertex3d(groundSize, -groundSize, -1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-groundSize, -groundSize, -1);
        
        //lower right
        glTexCoord2d(10,0); 
        glVertex3d(-groundSize, groundSize, -1);
        
        //lower left
        glTexCoord2d(10,10); 
        glVertex3d(groundSize, groundSize, -1);
    
    
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
        glVertex3d(-skySize, skySize, -1);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(-skySize, -skySize, -1);
    
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
        glVertex3d(-skySize, -skySize, -1);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(skySize, -skySize, -1);
    
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
        glVertex3d(skySize, skySize, -1);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(-skySize, skySize, -1);
    
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
        glVertex3d(skySize, skySize, -1);
        
        //lower left
        glTexCoord2d(0,0); 
        glVertex3d(skySize, -skySize, -1);
    
    glEnd();
    
    
}

void DrawSphere()
{
    glBindTexture(GL_TEXTURE_2D,texture4);
 
    GLUquadric* params = gluNewQuadric();
 
//     gluQuadricDrawStyle(params,GLU_LINE);
//     gluCylinder(params,1,1,2,20,1);
 
    gluQuadricDrawStyle(params,GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    glTranslated(0,0,2);
    gluSphere(params,0.75,20,20);
 
    gluDeleteQuadric(params);
    
}

void stop()
{
    delete camera; //destruction de la caméra allouée dynamiquement
    SDL_Quit();
}

int gravityTest(int argc, char *argv[])
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
    camera->setScrollSensivity(0.5);
    
    Uint32 start_time, stop_time;
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    texture1 = loadTexture("/home/phvera/projects/testopengl/crate.jpg");
    texture2 = loadTexture("/home/phvera/projects/testopengl/ground.jpg");
    texture3 = loadTexture("/home/phvera/projects/testopengl/sky.jpeg");
    texture4 = loadTexture("/home/phvera/projects/testopengl/earth.jpg");
    
//     if (texture1 == NULL || texture2 == NULL || texture3 == NULL)
//     {
//         std::cout<<"fail"<<std::endl;
//     }
//     for (;;)
//     {
//         while (SDL_PollEvent(&event))
//         {
//  
//             switch(event.type)
//             {
//                 case SDL_QUIT:
//                 exit(0);
//                 break;
//                 case SDLK_UP:
//                     case SDL_KEYDOWN:
//                     switch (event.key.keysym.sym)
//                     {
//                         case SDLK_UP:
//                         angleX += 1;
//                         break;
//                         
//                         case SDLK_DOWN:
//                         angleX -= 1;
//                         break;
//                         
//                         case SDLK_RIGHT:
//                         angleZ += 1;
//                         break;
//                         
//                         case SDLK_LEFT:
//                         angleZ -= 1;
//                         break;
//                         
//                         case SDLK_INSERT:
//                         angleY += 1;
//                         break;
//                         
//                         case SDLK_DELETE:
//                         angleY -= 1;
//                         break;
//                     }
//                 break;
//             }
//         }
        
//         current_time = SDL_GetTicks();
//         ellapsed_time = current_time - last_time;
//         last_time = current_time;
//  
// //         angleZ += 0.05 * ellapsed_time;
// //         angleX += 0.05 * ellapsed_time;
// //         angleY += 0.05 * ellapsed_time;
//         
//         ellapsed_time = SDL_GetTicks() - start_time;
//         if (ellapsed_time < 10)
//         {
//             SDL_Delay(10 - ellapsed_time);
//         }
        
 
 
 
//     }
 
    int cubeHeight = 50;
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

        
        cubeHeight -= 0.01;
        
        Dessiner(cubeHeight);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
            //SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}
 


void Dessiner(int cubeHeight)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
//     gluLookAt(3,4,2,0,0,0,0,0,1);
    
    camera->look();
    
//     glRotated(angleZ,0,0,1);
//     glRotated(angleY,0,1,0);
//     glRotated(angleX,1,0,0);
 
    
    drawCube2(cubeHeight);
//     DrawGround();
//     DrawSky();
//     DrawSphere();
 
    glFlush();
    SDL_GL_SwapBuffers();

}