#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768


int angle1 = 315;
int angle2 = 250;
int length = 0;

void drawCraneBase()
{
//         glClear(GL_COLOR_BUFFER_BIT);
    
        //base
        glBegin(GL_POLYGON);
        
            //upper left corner
            glColor3ub(255,255,0);
            glVertex3d(0,50,0);
            
            //upper right corner
            glColor3ub(255,255,0);
            glVertex3d(100,50,0);
            
            //lower right corner
            glColor3ub(255,255,0);
            glVertex3d(100,0,0);
            
            //lower left corner
            glColor3ub(255,255,0);
            glVertex3d(0,0,0);
        glEnd();
        
        
    
//         glFlush();
//         SDL_GL_SwapBuffers();
}



void drawCraneMainArm()
{
    glBegin(GL_POLYGON);
    
    glColor3ub(255,255,0);
    
    //upper left corner
    glVertex3d(0,600,0);
    
    //upper right corner
    glVertex3d(50,600,0);
    
    //lower right corner
    glVertex3d(50,0,0);
    
    //lower left corner
    glVertex3d(0,0,0);
    
    glEnd();
}

void drawCraneSmallArm()
{
    glBegin(GL_POLYGON);
    
    glColor3ub(255,255,0);
    
    //upper left corner
    glVertex3d(0,200,0);
    
    //upper right corner
    glVertex3d(20,200,0);
    
    //lower right corner
    glVertex3d(20,0,0);
    
    //lower left corner
    glVertex3d(0,0,0);
    
    glEnd();
}

void drawCraneCable()
{
    glBegin(GL_LINES);
    
    glColor3ub(255,255,0);
    
    //upper corner
    glVertex3d(0,0,0);

    //lower corner
    glVertex3d(0,-100+length,0);
    
    glEnd();
}

void drawCrane()
{

    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );    
    
    drawCraneBase();
    
    //we rotate to draw the main arm
    glRotated(angle1,0,0,1);
    
    drawCraneMainArm();
    
    //we place the axis at the end of the main arm
    glTranslated(50,600,0);
    
    //we rotate to draw the small arm
    glRotated(angle2,0,0,1);
    
    drawCraneSmallArm();
    
    //we place the axis at the end of the small arm
    glTranslated(20,200,0);
    
    //we cancel the rotations
    glRotated(-angle1-angle2,0,0,1);
    
    drawCraneCable();
    
    glFlush();
    SDL_GL_SwapBuffers();
    
}

int myCrane()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_OPENGL);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    
//     gluPerspective(70,(double)SCREEN_WIDTH/SCREEN_HEIGHT,1,1000);
    
    SDL_WM_SetCaption("My Awesome crane",NULL);
    
    drawCrane();
    
    SDL_Event event;
 
    SDL_EnableKeyRepeat(10,10);
    
     while(SDL_WaitEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
            exit(0);
            break;
            
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                angle1 += 1;
                break;
                
                case SDLK_DOWN:
                angle1 -= 1;
                break;
                
                case SDLK_RIGHT:
                angle2 += 1;
                break;
                
                case SDLK_LEFT:
                angle2 -= 1;
                break;
                
                case SDLK_PAGEUP:
                length += 1;
                break;
                
                case SDLK_PAGEDOWN:
                length -= 1;
                break;
            }
            break;
        }
        drawCrane();
    }
 
    return 0;
}

