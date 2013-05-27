#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;

// Input vertex data, different for all executions of this shader.
in vec3 vertexin;

void main() {
    gl_Position =  projectionMatrix * modelViewMatrix * objTransform * vec4(vertexin, 1);
}