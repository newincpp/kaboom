#version 330

uniform vec4 transCam;
uniform vec4 Rotcam;
in vec3 vertexPosition_local;

void main() {
    gl_Position = transCam + vec4(vertexPosition_local , 1);
}
