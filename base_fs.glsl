#version 330

uniform vec4 lightPos;
uniform vec4 lightDiff;
uniform vec4 specular;// = vec4(0.1,0.1,0.1,0.1);
uniform vec4 inputColour;

in vec3 TNormal;
in vec4 TVertex;

out vec4 outputColour;

void main()
{
    // Defining The Material Colors
    const vec4 AmbientColor = vec4(0.1, 0.0, 0.0, 1.0);
    //const vec4 DiffuseColor = vec4(1.0, 0.0, 0.0, 1.0);

    // Scaling The Input Vector To Length 1
    vec3 normalized_normal = normalize(TNormal);
    vec3 vertex_to_light_vector = vec3(lightPos - TVertex);
    vec3 normalized_vertex_to_light_vector = normalize(vertex_to_light_vector);

    // Calculating The Diffuse Term And Clamping It To [0;1]
    float DiffuseTerm = clamp(dot(TNormal, vertex_to_light_vector), 0.0, 1.0);

    // Calculating The Final Color
    outputColour = AmbientColor + inputColour + lightDiff * DiffuseTerm;
}
