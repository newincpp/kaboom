#version 330

   uniform vec3 lightPos;
   uniform vec3 lightColour;
   uniform int lightDiff;
   uniform float intensity;

/*
uniform struct Light {
    vec3 lightPos;
    vec3 lightColour;
    int lightDiff;
    float intensity;
} L ;
*/

uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;


void main () {
    float cosTheta = clamp(dot(V.TNormal, vec4(lightPos, 1)), 0, 1);
    float dist = distance(vec4(lightPos, 0.0), V.TVertex);
    vec4 tmpColour = inputColour + vec4(lightColour, 0) / 2;
    outputColour = tmpColour * intensity * cosTheta / (max(((dist * dist) / lightDiff), .1));
}

/*
void main () {
    float cosTheta = clamp(dot(V.TNormal, vec4(L.lightPos, 1)), 0, 1);
    float dist = distance(vec4(L.lightPos, 0.0), V.TVertex);
    vec4 tmpColour = inputColour + vec4(L.lightColour, 0) / 2;
    outputColour = tmpColour * L.intensity * cosTheta / (max(((dist * dist) / L.lightDiff), .1));
}*/
