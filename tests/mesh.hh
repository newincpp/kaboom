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
	    void render(bool changed = false);
	    void update() const;
	    void setColor(const Vector3D<GLfloat>&);
	private:
	    void toogleWireframe();
	    explicit Mesh();
	    void checkVertex() const;
	    ShadeProgram* _s;
	    bool _wireframe;
	    unsigned int _vertexCount;
	    GLfloat* _verts;
	    GLuint _vboID;
	    Vector3D<GLfloat> _col;
	    GLuint _callList;
	    bool _compiled;
    };
}

#endif /* !MESH_H_ */
