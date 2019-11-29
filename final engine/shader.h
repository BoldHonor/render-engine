#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED
#include<string.h>
#include<GL/glew.h>

using namespace std;


GLuint CreateShader(const string& text, unsigned int type);

string LoadShader(const string& fileName);
void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

void prepraingShader();
void nowDelete();

#endif // SHADER_H_INCLUDED
