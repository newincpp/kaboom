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
    //float intensity = 0.2;
    //vec4 amb = vec4(lightDiff, 1.0f) * intensity;
    vec4 L = normalize(vec4(lightPos,1) - V.TVertex);
    float DiffuseFactor = dot(L, -vec4(lightDir,1));
    //outputColour = vec4(DiffuseFactor, DiffuseFactor, DiffuseFactor, 1) * intensity * inputColour;
    outputColour = inputColour * intensity *  DiffuseFactor;
    //outputColour = vec4(normalize(lightColour), 1);
}
