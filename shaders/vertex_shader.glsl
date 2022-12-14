#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec3 in_normal;

uniform mat4 camMatrix = mat4(1.0);
uniform mat4 pr_matrix; 				// projection matrix
uniform mat4 vw_matrix = mat4(1.0); 	// view matrix
uniform mat4 ml_matrix = mat4(1.0); 	// model matrix

out vec4 frag_color;

void main() {
	gl_Position =  	pr_matrix * ml_matrix * vw_matrix * position;
	frag_color = 	in_color;
}