#version 330

uniform vec4 lightPos;
uniform vec3 lightDiff;
uniform vec4 lightLookAt;
uniform vec4 inputColour;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    vec4 lightDir = lightLookAt - lightPos;
    float intensity = 1;
    vec4 amb = vec4(lightDiff, 1.0f) * intensity;
    vec4 L = normalize(lightPos - V.TVertex);
    float DiffuseFactor = dot(L, -lightLookAt);
    vec4 DiffuseColor;

    DiffuseColor = intensity * inputColour;
    outputColour = DiffuseFactor.xxxx;
}
