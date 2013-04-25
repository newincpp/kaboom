#version 150

uniform mat4 viewMatrix, projMatrix;

in vec3 vertexPosition_local;

void main() {
    gl_Position = projMatrix * viewMatrix * vec4(vertexPosition_local, 1);
}
