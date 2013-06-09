#version 330

struct Light {
    vec3 lightPos;
    vec3 lightColour;
    int lightDiff;
    float intensity;
};

uniform int numlight;
#define MAXLIGHT 2
uniform Light L[MAXLIGHT];

uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {

    float cosTheta = clamp(dot(V.TNormal, vec4(L[1].lightPos, 1)), 0, 1);
    float dist = distance(vec4(L[1].lightPos, 0.0), V.TVertex);
    vec4 tmpColour = inputColour + vec4(L[1].lightColour, 0) / 2;
    vec4 tmpOut = tmpColour * L[1].intensity * cosTheta / (max(((dist * dist) / L[1].lightDiff), .1));


    cosTheta = clamp(dot(V.TNormal, vec4(L[0].lightPos, 1)), 0, 1);
    dist = distance(vec4(L[0].lightPos, 0.0), V.TVertex);
    tmpColour = inputColour + vec4(L[0].lightColour, 0) / 2;
    tmpOut += tmpColour * L[0].intensity * cosTheta / (max(((dist * dist) / L[0].lightDiff), .1));

    //outputColour = vec4(L[0].lightDiff, L[0].lightDiff, L[0].lightDiff, L[0].lightDiff);
    outputColour = tmpOut;
}
