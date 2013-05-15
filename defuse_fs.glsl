#version 330

in vec4 TNormal;
in vec4 TVertex;
uniform vec4 lightPos;
uniform vec3 lightDiff;
uniform vec4 inputColour;

out vec4 outputColour;

void main ()
{
    vec4 amb = vec4(0.3,0.3,0.3, 0);
    vec4 ld = vec4(lightDiff, 0);
    vec4 L = normalize(lightPos - TVertex);
    vec4 Idiff = ld * max(dot(TNormal,L), 0.0);
    outputColour = (amb - Idiff ) * inputColour;
}
