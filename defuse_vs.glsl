#version 330

uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec3 objTranslation;
//uniform mat4 projectionMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
out vec4 TNormal;
out vec4 TVertex;

void main() {
    vec3 fk = vec3(0.2,0,0);
    TVertex = modelViewMatrix * vec4(fk + vertexPosition + objTranslation, 1.0);
    TNormal = vec4(/*normalMatrix * */vertexNormal, 0);
    gl_Position = modelViewMatrix * vec4(fk + vertexPosition + objTranslation, 1.0);
}
