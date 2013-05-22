#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;

out vec3 TNormal;
out vec4 TVertex;

void main()
{
    // Transforming The Vertex
    gl_Position = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1);

    // Transforming The Normal To ModelView-Space
    TNormal = /*gl_NormalMatrix */ vertexNormal; 

    // Transforming The Vertex Position To ModelView-Space
    TVertex = modelViewMatrix * vec4(vertexPosition, 1);
}
