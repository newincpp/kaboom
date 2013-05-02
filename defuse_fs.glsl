#version 330

in vec3 TNormal;
in vec3 TVertex;
//uniform vec3 lightPos;
uniform vec3 lightDiff;
uniform vec4 inputColour;

out vec4 outputColour;

void main ()
{
    vec4 amb = vec4(0.2,0.2,0.2, 0);
    vec3 lightPos = vec3(-0.25, 0.25, 0);
    vec3 lightDiff = vec3(1.0,1.0,1.0);
    vec4 ld = vec4(lightDiff, 0);
    vec3 L = normalize(lightPos - TVertex);
    vec4 Idiff = ld * max(dot(TNormal,L), 0.0);
    outputColour = (amb - Idiff ) * inputColour;
}
