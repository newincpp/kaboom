#ifndef MESH_H_
# define MESH_H_

#include <vector>
#include "AObject.hh"
#include "libgdl_gl-2012.4/include/Image.hpp"
#include "Shader.hh"
#include "Vector3D.hh"
#include "Camera.hh"

namespace newin {
    class Mesh : public AObject {
	public:
	    explicit Mesh(std::vector<Vector3D<GLfloat> >*, std::vector<Vector3D<GLfloat> >*);
	    explicit Mesh(const Mesh&);
	    virtual ~Mesh();
	    void setShader(ShadeProgram*);
	    void render();
	    void toogleWireframe();
	    void update() const;
	    // for gdl.......
	    void initialize();
	    void update(/*gdl::GameClock const &,*/ gdl::Input &);
	    void draw(void);
	private:
	    explicit Mesh();
	    void checkVertex() const;
	    unsigned int _vertexCount;
	    unsigned int _normalCount;
	    GLfloat* _verts;
	    GLfloat* _normal;
	    ShadeProgram* _s;
	    bool _wireframe;
	    GLuint _vboID;
	    GLuint _nboID;
	    // matrix
	    GLfloat _matrixTransform[16];
	    void transform();
	    bool _buffered;
    };
}

#endif /* !MESH_H_ */
