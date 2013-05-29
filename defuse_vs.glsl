#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;

out struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

void main() {
    //ShadeCoordV = ShadeCoord;

    V.TVertex = objTransform * vec4(vertexPosition, 1.0);
    V.TNormal = objTransform * vec4(vertexNormal,1.0);

    gl_Position = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1.0);

    //gl_Position = vec4(vertexPosition,1);
}
