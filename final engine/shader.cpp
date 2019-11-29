#include<string.h>
#include<GL/glew.h>
#include<fstream>
#include<iostream>
#include"shader.h"
using namespace std ;
GLuint vertexShaderID;
   GLuint fragmentShaderID;
   GLuint shaderProgramID;
string LoadShader(const string& fileName)
{
    ifstream file;
    file.open((fileName).c_str());

    string output;
    string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		cerr << "Unable to load shader: " << fileName << endl;
    }

    return output;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        cerr << errorMessage << ": '" << error << "'" << endl;
    }
}

GLuint CreateShader(const string& text, unsigned int type)
{
    GLuint shader = glCreateShader(type);

    if(shader == 0)
		cerr << "Error compiling shader type " << type << endl;

    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();

    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

    return shader;
}



void prepraingShader()
{
    //int colorLocation = glGetAttribLocation(shaderProgramID,"color");
     vertexShaderID = CreateShader(LoadShader("./vertexShader.glsl"),GL_VERTEX_SHADER);
     fragmentShaderID = CreateShader(LoadShader("./fragmentShader.glsl"),GL_FRAGMENT_SHADER);
     shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID,vertexShaderID);
    glAttachShader(shaderProgramID,fragmentShaderID);

    glLinkProgram(shaderProgramID);

    glUseProgram(shaderProgramID);
   // glVertexAttrib3f(colorLocation,0.2,0.3,0.0);



}

void nowDelete()
{
 glDetachShader(shaderProgramID,vertexShaderID);
    glDetachShader(shaderProgramID,fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(shaderProgramID);
}

