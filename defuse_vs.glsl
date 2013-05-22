#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;
//uniform mat3 normalMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
out vec4 TNormal;
out vec4 TVertex;

void main() {
    mat3 NormalMatrix = transpose( inverse( mat3( modelViewMatrix)));

    TVertex = objTransform * vec4(vertexPosition, 1.0);
    TNormal = vec4(normalize(NormalMatrix * vertexNormal), 1);
    gl_Position = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1.0);
}
