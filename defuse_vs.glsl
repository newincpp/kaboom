#version 330

uniform vec4 transCam;
//uniform vec4  rotCam;

in vec3 vertexPosition;
out vec3 TNormal;
out vec3 TVertex;

void main() {
    TVertex = vec3(transCam.x, transCam.y, transCam.z) - vertexPosition; 
    TNormal = normalize(vertexPosition);
    gl_Position = vec4(vertexPosition, 1.0) - transCam;
}
