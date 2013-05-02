#ifndef CAMERA_H_
# define CAMERA_H_

#include "Shader.hh"
#include "Types3D.hh"

namespace newin {
    class Camera {
	public:
	    explicit Camera(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void initialize();
	    Vector3D<GLfloat> getPos() const;
	    Vector3D<GLfloat> getRot() const;
	    void setPos(const Vector3D<GLfloat>&);
	    void setRot(const Vector3D<GLfloat>&);
	    virtual ~Camera();
	private:
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;
	    ShadeProgram* _prgm;
    };
}

#endif /* !CAMERA_H_ */
