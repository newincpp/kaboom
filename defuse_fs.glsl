#version 330

in vec4 TNormal;
in vec4 TVertex;
uniform vec4 lightPos;
uniform vec3 lightDiff;
uniform vec4 specular;// = vec4(0.1,0.1,0.1,0.1);
uniform vec4 inputColour;

out vec4 outputColour;

void main ()
{
    //vec4 ld = vec4(lightDiff, 0);
    //vec4 L = normalize(lightPos - TVertex);
    //vec4 Idiff = ld * max(dot(TNormal,L), 0.0);
    //outputColour = (amb - Idiff ) * inputColour;

    vec4 amb = vec4(0.2,0.2,0.2, 0);
    float shininess = 12;

    vec4 L = normalize(lightPos - TVertex);   
    vec4 E = normalize(-TVertex); // we are in Eye Coordinates, so EyePos is (0,0,0)  
    vec4 R = normalize(-reflect(L,TNormal));

    //calculate Ambient Term:  
    vec4 Iamb = amb;

    //calculate Diffuse Term:  
    vec4 Idiff = vec4(lightDiff, 1.0)* max(dot(TNormal,L), 0.0);
    Idiff = clamp(Idiff, 0.0, 1.0);

    // calculate Specular Term:
    vec4 Ispec = specular * pow(max(dot(R,E),0.0),0.3 * shininess);
    Ispec = clamp(Ispec, 0.0, 1.0); 

    // write Total Color:  
    //gl_FragColor = gl_FrontLightModelProduct.sceneColor + Iamb + Idiff + Ispec; 
    outputColour = Iamb + Idiff + Ispec + inputColour;
}
