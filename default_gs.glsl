#version 330

layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;

out vec3 vertexNormal;

void main(void) {
    for (int i=0;i < gl_in.length(); i +=3 ) {
	vertexNormal = cross(normalize( gl_in[ i + 2].gl_Position.xyz - gl_in[ i ].gl_Position.xyz),
		normalize( gl_in[ i + 1].gl_Position.xyz - gl_in[i + 2].gl_Position.xyz));
	gl_Position = gl_in[ i ].gl_Position;
	EmitVertex();
	gl_Position = gl_in[i + 1].gl_Position;
	EmitVertex();
	gl_Position = gl_in[i + 2].gl_Position;
	EmitVertex();
    }
    EndPrimitive();
}

