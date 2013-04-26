#ifndef CAMERA_H_
# define CAMERA_H_

#include "types3D.hh"

namespace newin {
    class Camera {
	public:
	    explicit Camera(Vector3D<GLfloat>, Vector3D<GLfloat>);
	    virtual ~Camera();
	private:
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _rot;
	    mat4<GLfloat> projMatrix;
	    mat4<GLfloat> viewMatrix;
	    //float projMatrix[16];
	    //float viewMatrix[16];
    };
}

#endif /* !CAMERA_H_ */
