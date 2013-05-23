#version 330

uniform mat4 modelViewMatrix;
uniform mat4 objTransform;
uniform mat4 projectionMatrix;
//uniform mat3 normalMatrix;

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec4 ShadeCoord;

out vec4 TNormal;
out vec4 TVertex;
out vec4 ShadeCoordV;

void main() {
    ShadeCoordV = ShadeCoord;
    mat3 NormalMatrix = transpose(inverse(mat3(modelViewMatrix)));

    TVertex = objTransform * vec4(vertexPosition, 1.0);
    //TNormal = vec4(normalize(NormalMatrix * vertexNormal), 1);
    //TNormal = projectionMatrix * modelViewMatrix * vec4(vertexNormal, 0.0);
    TNormal = normalize(vec4(vertexNormal,1));
    gl_Position = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1.0);
}
