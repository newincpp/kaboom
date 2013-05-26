#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;

void main(void) {
    for (int i = 0;i < gl_in.length(); ++i) {
	gl_Position = gl_in[i].gl_Position;
	EmitVertex();
    }
    EndPrimitive();
}

/*
#version 120
#extension GL_EXT_geometry_shader4 : enable

void main(void)
{
mat4x4 bezierBasis=mat4x4( 1, -3, 3, -1, 0, 3, -6, 3 , 0, 0, 3, -3 , 0, 0, 0, 1);
for(int i=0; i<64; i++)
{
float t = i / (64.0-1.0);
vec4 tvec= vec4(1, t, t*t, t*t*t);
vec4 b =tvec*bezierBasis;
vec4 p = gl_PositionIn[0]*b.x+ gl_PositionIn[1]*b.y+ gl_PositionIn[2]*b.z+ gl_PositionIn[3]*b.w;
gl_Position =p;
EmitVertex();
}
EndPrimitive();

}*/
