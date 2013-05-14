#version 330

uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
//uniform mat4 projectionMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
out vec4 TNormal;
out vec4 TVertex;

void main() {
    TVertex = modelViewMatrix * vec4(vertexPosition, 1.0);
    TNormal = vec4(/*normalMatrix * */vertexNormal, 0);
    gl_Position = modelViewMatrix * vec4(vertexPosition, 1.0);
}
