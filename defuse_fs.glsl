#version 330

uniform vec3 lightPos;
uniform vec3 lightColour;
uniform vec3 lightRot;
uniform float intensity;
uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    vec4 L = normalize(vec4(lightPos,1) - V.TVertex);
    float DiffuseFactor = dot(L, -vec4(-lightPos,1));
    outputColour = (vec4(lightColour, 1) + inputColour) * intensity *  DiffuseFactor;
    //outputColour = texture(renderedTexture, vec2(10.0, 10.0));
}
