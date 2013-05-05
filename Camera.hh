#ifndef CAMERA_H_
# define CAMERA_H_

#include "libgdl_gl-2012.4/include/Input.hpp"
#include "Shader.hh"
#include "Types3D.hh"

namespace newin {
    class Camera {
	public:
	    explicit Camera();
	    explicit Camera(ShadeProgram* p, const Vector3D<GLfloat>& v = Vector3D<GLfloat>(), const Vector3D<GLfloat>& u = Vector3D<GLfloat>());
	    //void initialize();
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void update(/*gdl::GameClock const & gameClock,*/ gdl::Input & input);
	    Vector3D<GLfloat> getPos() const;
	    Vector3D<GLfloat> getRot() const;
	    void setPos(const Vector3D<GLfloat>&);
	    void setRot(const Vector3D<GLfloat>&);
	    virtual ~Camera();
	private:
	    bool _changed;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;
	    ShadeProgram* _prgm;
	    GLfloat _modelView[16];
    };
}

#endif /* !CAMERA_H_ */
