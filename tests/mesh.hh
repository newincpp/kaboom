#ifndef MESH_H_
# define MESH_H_

#include <vector>
#include "shader.hh"
#include "types3D.hh"

namespace newin {
    class Mesh {
	public:
	    explicit Mesh(const std::vector<Vector3D<GLfloat> >*);
	    virtual ~Mesh();
	    void addVertex(const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram*);
	    void render();
	    void toogleWireframe();
	    void update() const;
	    void setColor(const Vector3D<GLfloat>&);
	private:
	    explicit Mesh();
	    void checkVertex() const;
	    ShadeProgram* _s;
	    bool _wireframe;
	    unsigned int _vertexCount;
	    GLfloat* _verts;
	    GLuint _vboID;
	    Vector3D<GLfloat> _col;
    };
}

#endif /* !MESH_H_ */
