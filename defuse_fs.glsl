#version 330

struct Light {
    vec3 lightPos;
    vec3 lightColour;
    int lightDiff;
    float intensity;
};

uniform int numlight;
#define MAXLIGHT 20
uniform Light L[MAXLIGHT];

uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    vec4 tmpOut;
    for (int i = 0; i < numlight + 1 ; i++) {
	float cosTheta = clamp(dot(V.TNormal, vec4(L[i].lightPos, 1)), 0, 1);
	float dist = distance(vec4(L[i].lightPos, 0.0), V.TVertex);
	vec4 tmpColour = inputColour + vec4(L[i].lightColour, 0) / 2;
	tmpOut += tmpColour * L[i].intensity * cosTheta / (max(((dist * dist) / L[i].lightDiff), .1));
    }
    outputColour = tmpOut;
}
