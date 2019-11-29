#include"draw.h"
#include<GL/glew.h>



GLfloat ztriangle1 = -0.23,ztriangle2=0.9;


GLfloat verti[]={
1.0f,0.2f,ztriangle1,//verte
0.0,0.0,1.0,
0.3f,0.9f,ztriangle1,//verte
0.2,0.6,0.9,
-0.4f,-0.8f,ztriangle1,//verte
0.6,0.2,0.1,
0.3f,-0.4f,ztriangle2,//verte
0.1,0.1,0.1,
-0.6f,0.7f,-0.9,//verte
0.7,0.6,0.2
};

GLuint indexArray[]={0,1,2,0,3,4};

void drawOnScreen(){

GLuint vertexPosBufferID;
glGenBuffers(1,&vertexPosBufferID);
glBindBuffer(GL_ARRAY_BUFFER,vertexPosBufferID);
glBufferData(GL_ARRAY_BUFFER,sizeof(verti),verti,GL_STATIC_DRAW);
glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,0);
glEnableVertexAttribArray(0);
glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,(char*)(sizeof(float)*3));
glEnableVertexAttribArray(1);

GLuint vertexIndexBufferID;
glGenBuffers(1,&vertexIndexBufferID);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vertexIndexBufferID);
glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexArray),indexArray,GL_STATIC_DRAW);


}
