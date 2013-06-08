#version 330

struct Light {
    vec3 lightPos;
    vec3 lightColour;
    int lightDiff;
    float intensity;
};

uniform int numlight;
uniform Light L0;
uniform Light L1;

uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    vec4 tmpOut;

    float cosTheta = clamp(dot(V.TNormal, vec4(L0.lightPos, 1)), 0, 1);
    float dist = distance(vec4(L0.lightPos, 0.0), V.TVertex);
    vec4 tmpColour = inputColour + vec4(L0.lightColour, 0) / 2;
    tmpOut += tmpColour * L0.intensity * cosTheta / (max(((dist * dist) / L0.lightDiff), .1));

    cosTheta = clamp(dot(V.TNormal, vec4(L1.lightPos, 1)), 0, 1);
    dist = distance(vec4(L1.lightPos, 0.0), V.TVertex);
    tmpColour = inputColour + vec4(L1.lightColour, 0) / 2;
    tmpOut += tmpColour * L1.intensity * cosTheta / (max(((dist * dist) / L1.lightDiff), .1));

    outputColour = tmpOut;
}
