#ifndef MESH_H_
# define MESH_H_

#include <vector>
#include "AObject.hh"
#include "libgdl_gl-2012.4/include/Image.hpp"
#include "Shader.hh"
#include "Types3D.hh"
#include "Camera.hh"

namespace newin {
    class Mesh : public AObject {
	public:
	    explicit Mesh(std::vector<Vector3D<GLfloat> >*, ShadeProgram*);
	    virtual ~Mesh();
	    void addVertex(const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram*);
	    void render();
	    void toogleWireframe();
	    void update() const;
	    void setColor(const Vector3D<GLfloat>&);
	    void setPos(const Vector3D<GLfloat>&);
	    void setRot(const Vector3D<GLfloat>&);
	    Vector3D<GLfloat> getPos() const;
	    Vector3D<GLfloat> getRot() const;
	    void setTex(const std::string&);
	    void setWorlCam(Camera*);
	    // for gdl.......
	    void initialize();
	    void update(/*gdl::GameClock const &,*/ gdl::Input &);
	    void draw(void);
	private:
	    explicit Mesh();
	    void checkVertex() const;
	    gdl::Image _tex;
	    GLboolean _tset;
	    ShadeProgram* _s;
	    bool _wireframe;
	    unsigned int _vertexCount;
	    GLfloat* _verts;
	    GLuint _vboID;
	    Vector3D<GLfloat> _col;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;

	    Camera* _cam;

	    // matrix
	    GLfloat _matrixTransform[16];
	    void transform();
    };
}

#endif /* !MESH_H_ */
