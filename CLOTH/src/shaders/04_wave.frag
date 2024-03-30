/*

04_wave.frag : Fragment shader, equal to 03_normal2color.frag

author: Davide Gadia

Real-Time Graphics Programming - a.a. 2022/2023
Master degree in Computer Science
Universita' degli Studi di Milano

*/

#version 410 core

// output shader variable
out vec4 colorFrag;

// the transformed normal has been calculated per-vertex in the vertex shader
in vec3 N;


void main(){
	// we use the normal as a color
	colorFrag = vec4(normalize(N),1.0);
}