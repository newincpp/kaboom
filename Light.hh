#ifndef LIGHT_H_
# define LIGHT_H_

#include "Shader.hh"
#include "Types3D.hh"

namespace newin {
    class Light {
	public:
	    explicit Light(ShadeProgram* prgm = NULL, const Vector3D<GLfloat>& p = Vector3D<GLfloat>(), const Vector3D<GLfloat>& r = Vector3D<GLfloat>());
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram* p);
	    void update();
	    void setPos(const Vector3D<GLfloat>&);
	    void setDiff(const Vector3D<GLfloat>&);
	    Vector3D<GLfloat> getPos();
	    Vector3D<GLfloat> getDiff();
	    virtual ~Light();
	private:
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _diff;
	    ShadeProgram* _prgm;
    };
}

#endif /* !LIGHT_H_ */
