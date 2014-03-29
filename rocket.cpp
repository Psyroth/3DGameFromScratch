#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include "sdlglutils.h"
 
 
double angleZ = 0;
double angleY = 0;
double angleX = 0;
 

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture_rocket_bottom;
GLuint texture_rocket_motor;
GLuint texture_top;
GLuint texture_middle;

void Dessiner();

void drawCube2()
{ 
    //red surface
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    
    glBegin(GL_QUADS);
    
//         glColor3ub(255,0,0);
    
    
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,1,1);
        
        //lower left
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,-1);
        
        //upper right
        glTexCoord2d(1,1); 
        glVertex3d(-1,1,1);
        
    glEnd();
    
    //green surface
    glBegin(GL_QUADS);
    
//         glColor3ub(0,255,0);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(1,1,1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(1,1,-1);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,-1,-1);
    
    glEnd();
    
    //yellow surface
    
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,0);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,1);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,1,1);
    
    glEnd();
    
    //white surface
//     
    glBegin(GL_QUADS);
    
//         glColor3ub(255,255,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,-1,-1);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,-1,-1);
    
    glEnd();
    
    //blue surface
    glBegin(GL_QUADS);
    
//         glColor3b(0,0,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(1,-1,-1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,-1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,1,-1);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(1,1,-1);
        
    glEnd();

    //cyan surface
    glBegin(GL_QUADS);
    
//         glColor3ub(0,255,255);
        
        //upper left
        glTexCoord2d(0,1);
        glVertex3d(-1,1,1);
        
        //upper right
        glTexCoord2d(0,0);
        glVertex3d(-1,-1,1);
        
        //lower right
        glTexCoord2d(1,0); 
        glVertex3d(-1,-1,-1);
        
        //lower left
        glTexCoord2d(1,1); 
        glVertex3d(-1,1,-1);
    
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
 
    gluQuadricDrawStyle(params,GLU_LINE);
    gluCylinder(params,1,1,2,20,1);
 
//     gluQuadricDrawStyle(params,GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
//     glTranslated(0,0,2);
//     gluSphere(params,0.75,20,20);
 
    gluDeleteQuadric(params);
}

void DrawRocket()
{
    //rocket top
    glTranslated(0,0,1);
    
    glBindTexture(GL_TEXTURE_2D, texture_top);
    
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params, GL_TRUE);
    
    gluCylinder(params, .5, 0, 2, 20, 20);
    
    
    
    //rocket middle
    glTranslated(0,0,-1);
    
    
    glBindTexture(GL_TEXTURE_2D, texture_middle);
    
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params, GL_TRUE);
    
    gluCylinder(params, .3,.5, 1,20,20);
    
    
    //rocket bottom
    glTranslated(0,0,-.5);
    
    glBindTexture(GL_TEXTURE_2D, texture_rocket_bottom);
    
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params, GL_TRUE);
    
    gluCylinder(params, .5,.3,.5,20,20);
    
    
    //rocket under
    
    glTranslated(0,0,0);
    
    glBindTexture(GL_TEXTURE_2D, texture_rocket_motor);
    
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params, GL_TRUE);
    
    gluDisk(params, 0,.5,20,1);
    
    gluDeleteQuadric(params);
}

int rocket(int argc, char *argv[])
{
    SDL_Event event;
 
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
    glEnable(GL_DEPTH_TEST);
 
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)1024/768,1,1000);
    
    SDL_EnableKeyRepeat(10,10);
    
    Dessiner();
 
    
    Uint32 start_time;
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    texture1 = loadTexture("/home/phvera/projects/testopengl/crate.jpg");
    texture2 = loadTexture("/home/phvera/projects/testopengl/ground.jpg");
    texture3 = loadTexture("/home/phvera/projects/testopengl/sky.jpeg");
    texture4 = loadTexture("/home/phvera/projects/testopengl/earth.jpg");
    texture_rocket_bottom = loadTexture("/home/phvera/projects/testopengl/rocket_textures/rocket_bottom.jpg");
    texture_rocket_motor = loadTexture("/home/phvera/projects/testopengl/rocket_textures/rocket_motor.jpg");
    texture_top = loadTexture("/home/phvera/projects/testopengl/rocket_textures/rocket_top.jpg");
    texture_middle = loadTexture("/home/phvera/projects/testopengl/rocket_textures/rocket_middle.jpg");
    
    if (texture1 == NULL || texture2 == NULL || texture3 == NULL || texture_top == NULL)
    {
        std::cout<<"fail"<<std::endl;
    }
    
    for (;;)
    {
        while (SDL_PollEvent(&event))
        {
 
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
                case SDLK_UP:
                    case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                        angleX += 1;
                        break;
                        
                        case SDLK_DOWN:
                        angleX -= 1;
                        break;
                        
                        case SDLK_RIGHT:
                        angleZ += 1;
                        break;
                        
                        case SDLK_LEFT:
                        angleZ -= 1;
                        break;
                        
                        case SDLK_INSERT:
                        angleY += 1;
                        break;
                        
                        case SDLK_DELETE:
                        angleY -= 1;
                        break;
                    }
                break;
            }
        }
        
        current_time = SDL_GetTicks();
        ellapsed_time = current_time - last_time;
        last_time = current_time;
 
//         angleZ += 0.05 * ellapsed_time;
//         angleX += 0.05 * ellapsed_time;
//         angleY += 0.05 * ellapsed_time;
        
        ellapsed_time = SDL_GetTicks() - start_time;
        if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        }
        
 
 
        Dessiner();
 
    }
 
    return 0;
}
 
void Dessiner()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
    gluLookAt(3,4,2,0,0,0,0,0,1);
    
    glRotated(angleZ,0,0,1);
    glRotated(angleY,0,1,0);
    glRotated(angleX,1,0,0);
 
//     DrawGround();
    
    DrawRocket();
 
    glFlush();
    SDL_GL_SwapBuffers();
}