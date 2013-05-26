#version 330

uniform vec3 lightPos;
uniform vec3 lightColour;
uniform vec3 lightLookAt;
uniform float intensity;
uniform vec4 inputColour;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    vec3 lightDir = lightLookAt - lightPos;
    vec4 L = normalize(vec4(lightPos,1) - V.TVertex);
    float DiffuseFactor = dot(L, -vec4(lightDir,1));
    outputColour = (vec4(lightColour, 1) + inputColour) * intensity *  DiffuseFactor;
}
