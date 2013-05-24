#version 330

// layout (location = x)
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
    //mat3 NormalMatrix = transpose(inverse(mat3(modelViewMatrix)));

    V.TVertex = objTransform * vec4(vertexPosition, 1.0);
    ////TNormal = vec4(normalize(NormalMatrix * vertexNormal), 1);
    ////TNormal = projectionMatrix * modelViewMatrix * vec4(vertexNormal, 0.0);
    //TNormal = vec4(vertexNormal,1);
    //V.TNormal = vec4(vertexPosition, 1.0);

    gl_Position = projectionMatrix * modelViewMatrix * objTransform * vec4(vertexPosition, 1.0);

    //gl_Position = vec4(vertexPosition,1);
}
