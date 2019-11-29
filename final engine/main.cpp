#include<iostream>
#include<SDL2/SDL.h>
#include<GL/glew.h>
#include"draw.h"
#include"shader.h"


using namespace std;

SDL_Window *window;
SDL_GLContext context;

bool isClosed;

void initFunction(){

SDL_Init(SDL_INIT_EVERYTHING);
SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
 window=SDL_CreateWindow("c for opengl",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_OPENGL);
 context=SDL_GL_CreateContext(window);



 GLenum status = glewInit();
 if (status != GLEW_OK);
 {
    printf("failed");
 }
  isClosed = false;


}

void update()
{
SDL_GL_SwapWindow(window);
SDL_Event event;
while(SDL_PollEvent(&event))
{
if(event.type == SDL_QUIT) isClosed= true;

}
}

bool IsClosed()
{
return isClosed;
}


int main()
{

   // printf("Hello world!\n");
    initFunction();
//uniform();
  glEnable(GL_DEPTH_TEST);


    drawOnScreen();

    prepraingShader();
     nowDelete();
    while(!IsClosed())
    {
    glViewport(0,0,800,600);
    glClearColor(0.0f,0.6f,0.2f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
     glClear(GL_DEPTH_BUFFER_BIT);

   // glClearDepth(1.0);

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

   // glDrawArrays(GL_TRIANGLES,0,6);
    update();

    }
    return 0;
}

