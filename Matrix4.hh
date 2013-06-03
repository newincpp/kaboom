#ifndef MATRIX4_H_
# define MATRIX4_H_
#include <iostream>

namespace newin {
    template <typename T>
	class mat4 {
	    public:
		explicit mat4(ShadeProgram* p = NULL) : _prgm(p) {}
		virtual ~mat4() {}
		void setIdentityMatrix() {
		    glMatrixMode(GL_MODELVIEW);
		    glLoadIdentity();
		}
		void setTrans(const Vector3D<GLfloat>& pos) {
		    glTranslatef(- pos.getX(), - pos.getY(), - pos.getZ());
		}
		void setRot(const Vector3D<GLfloat>& rot) {
		    glRotatef(rot.getZ(), 0, 0, 1);
		    glRotatef(rot.getY(), 0, 1, 0);
		    glRotatef(rot.getX(), 1, 0, 0);
		}
		void genModelView(const Vector3D<GLfloat>& pos, const Vector3D<GLfloat>& rot) {
		    glMatrixMode(GL_MODELVIEW);
		    glLoadIdentity();
		    glRotatef(rot.getZ(), 0, 0, 1);
		    glRotatef(rot.getY(), 0, 1, 0);
		    glRotatef(rot.getX(), 1, 0, 0);
		    glTranslatef(- pos.getX(), - pos.getY(), - pos.getZ());
		    glGetFloatv(GL_MODELVIEW_MATRIX, _mat);
		    if (_prgm) {
			_prgm->setVariable("modelViewMatrix", _mat);
		    } else {
			std::cout << "WARNING shader is not set, 'uniform modelViewMatrix' will not set" << std::endl;
		    }
		}
		void loadProjectionMatrix(T fov = 60, T width = __DWIDTH, T height = __DHEIGHT, T znear = 1, T zfar = 1000) {
		    glMatrixMode(GL_PROJECTION);
		    glLoadIdentity();
		    gluPerspective (fov, width / height, znear, zfar);
		    glGetFloatv(GL_PROJECTION_MATRIX, _mat);
		    if (_prgm) {
			_prgm->setVariable("projectionMatrix", _mat);
		    } else {
			std::cout << "WARNING shader is not set, 'uniform projectionMatrix' will not set" << std::endl;
		    }
		}
		void upload(const std::string& name) {
		    _prgm->setVariable(name.c_str(), _mat);
		}
		void setShader(ShadeProgram* p) {
		    _prgm = p;
		}
	    private:
		ShadeProgram* _prgm;
		T _mat[16];
	};
}

#endif /* !MATRIX4_H_ */
