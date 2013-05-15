#version 330

uniform mat4 modelViewMatrix;
uniform vec3 objTranslation;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
out vec4 TNormal;
out vec4 TVertex;

void main() {
    TVertex = projectionMatrix * modelViewMatrix * (vec4(vertexPosition, 1.0) + vec4(objTranslation, 1.0));
    TNormal = vec4(/*normalMatrix * */vertexNormal, 0);
    gl_Position = /*projectionMatrix */ modelViewMatrix * (vec4(vertexPosition, 1.0) + vec4(objTranslation, 1.0));
}
