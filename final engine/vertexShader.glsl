#version 120

attribute vec3 position;
varying vec3 colr;
attribute vec3 color;

void main()
{
   
   gl_Position=vec4(position,1.0);
   colr = color;
}
