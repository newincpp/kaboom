#ifndef MESH_H_
# define MESH_H_

#include <vector>
#include "shader.hh"
#include "types3D.hh"

namespace newin {
    class Mesh {
	public:
	    explicit Mesh(const std::vector<Vector3D<GLfloat> >&);
	    virtual ~Mesh();
	    void setShader(ShadeProgram*);
	    void render();
	    void toogleWireframe();
	private:
	    ShadeProgram* _s;
	    bool _wireframe;
	    unsigned int _vertexCount;
	    GLfloat* _verts;
	    GLuint _vboID;
	    GLuint _vaoID;
    };
}

#endif /* !MESH_H_ */
