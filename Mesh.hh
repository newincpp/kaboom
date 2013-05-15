#ifndef MESH_H_
# define MESH_H_

#include <vector>
#include "AObject.hh"
#include "Shader.hh"
#include "Types3D.hh"

namespace newin {
    class Mesh : public AObject {
	public:
	    explicit Mesh(const std::vector<Vector3D<GLfloat> >*, ShadeProgram*);
	    virtual ~Mesh();
	    void addVertex(const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram*);
	    void render();
	    void toogleWireframe();
	    void update() const;
	    void setColor(const Vector3D<GLfloat>&);
	    void setPos(const Vector3D<GLfloat>&);
	    // for gdl.......
	    void initialize();
	    void update(/*gdl::GameClock const &,*/ gdl::Input &);
	    void draw(void);
	private:
	    void transform();
	    explicit Mesh();
	    void checkVertex() const;
	    ShadeProgram* _s;
	    bool _wireframe;
	    unsigned int _vertexCount;
	    GLfloat* _verts;
	    GLuint _vboID;
	    Vector3D<GLfloat> _col;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;
	    GLfloat _matrixTransform[16];
	    GLuint _callList;
	    bool _compiled;
    };
}

#endif /* !MESH_H_ */
