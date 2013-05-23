#version 330

in vec4 TNormal;
in vec4 TVertex;
in vec4 ShadeCoordV;

uniform vec4 lightPos;
uniform vec3 lightDiff;
uniform vec4 lightLookAt;
uniform vec4 inputColour;

uniform sampler2D shademap;

out vec4 outputColour;

void main ()
{
    vec4 lightDir = lightLookAt - lightPos;
    float intensity = 1;
    vec4 amb = vec4(lightDiff, 1.0f) * intensity;
    vec4 L = normalize(lightPos - TVertex);
    float DiffuseFactor = dot(L, -lightDir);
    vec4 DiffuseColor;

    DiffuseColor = DiffuseColor;
    if (DiffuseFactor > 0) {
	DiffuseColor = vec4(lightDiff, 1.0f) * intensity * DiffuseFactor;
    }
    else {
	DiffuseColor = vec4(0, 0, 0, 0);
    }
    outputColour = vec4(DiffuseFactor, DiffuseFactor, DiffuseFactor, 1);
}
