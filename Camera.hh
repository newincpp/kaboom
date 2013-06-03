#ifndef CAMERA_H_
# define CAMERA_H_

#include "libgdl_gl-2012.4/include/Input.hpp"
#include "Shader.hh"
#include "Vector3D.hh"
#include "Matrix4.hh"

namespace newin {
    class Camera {
	public:
	    explicit Camera();
	    explicit Camera(ShadeProgram* p, const Vector3D<GLfloat>& v = Vector3D<GLfloat>(), const Vector3D<GLfloat>& u = Vector3D<GLfloat>());
	    //void initialize();
	    virtual ~Camera();
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void update(/*gdl::GameClock const & gameClock,*/ gdl::Input & input);
	    void renderMode();
	    void endRenderMode();
	    Vector3D<GLfloat> getPos() const;
	    Vector3D<GLfloat> getRot() const;
	    void setPos(const Vector3D<GLfloat>&);
	    void setRot(const Vector3D<GLfloat>&);
	    Mat4<GLfloat> getModelViewMatrix();
	    Mat4<GLfloat> getProjectionMatrix();
	private:
	    bool _changed;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;
	    ShadeProgram* _prgm;
	    Mat4<GLfloat> _modv;
	    Mat4<GLfloat> _projv;
    };
}

#endif /* !CAMERA_H_ */
