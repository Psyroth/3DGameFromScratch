
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

int cubeForm()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("OpenGL test",NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
 
    bool continuer = true;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
        }
 
         glClear(GL_COLOR_BUFFER_BIT);
 
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
 
        glFlush();
        SDL_GL_SwapBuffers();
    }
 
    SDL_Quit();
    return 0;
}    
