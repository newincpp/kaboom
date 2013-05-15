#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
out vec4 TNormal;
out vec4 TVertex;

void main() {
    TVertex = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1.0);
    TNormal = vec4(/*normalMatrix * */vertexNormal, 0);
    gl_Position = /*projectionMatrix */ modelViewMatrix * objTransform vec4(vertexPosition, 1.0);
}
