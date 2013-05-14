#ifndef LIGHT_H_
# define LIGHT_H_

#include "shader.hh"
#include "types3D.hh"

namespace newin {
    class Light {
	public:
	    explicit Light(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    virtual ~Light();
	private:
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _diff;
	    ShadeProgram* _prgm;
    };
}

#endif /* !LIGHT_H_ */
