#version 330

struct Light {
    vec3 Pos;
    vec3 Colour;
    int Diff;
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
    vec4 tmpOut = vec4(0,0,0,0);

    for (int i = 0; i <= numlight + 1; ++i) {
	float cosTheta = clamp(dot(V.TNormal, vec4(L[i].Pos, 1)), 0, 1);
	float dist = distance(vec4(L[i].Pos, 0.0), V.TVertex);
	vec4 tmpColour = inputColour + vec4(L[i].Colour, 0) / 2;
	tmpOut += tmpColour * L[i].intensity * cosTheta / (max(((dist * dist) / L[i].Diff), .1));
    }
    //outputColour = inputColour + vec4(L[1].lightColour, 0) / 2;
    outputColour = tmpOut;
}
