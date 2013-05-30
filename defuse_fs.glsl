#version 330

uniform vec3 lightPos;
uniform vec3 lightColour;
uniform float intensity;
uniform vec4 inputColour;

uniform sampler2D renderedTexture;

in struct vertex {
    vec4 TVertex;
    vec4 TNormal;
} V;

out vec4 outputColour;

void main () {
    float cosTheta = clamp(dot(V.TNormal, vec4(lightPos, 1)), 0, 1);
    float dist = distance(vec4(lightPos, 1.0), V.TVertex);
    outputColour = inputColour * vec4(lightColour, 1) * intensity * cosTheta / (dist * dist);
    //outputColour = V.TNormal;
}
