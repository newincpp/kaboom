#ifndef MATRIX4_H_
# define MATRIX4_H_

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
		    _prgm->setVariable("modelViewMatrix", _mat);
		}
		void loadProjectionMatrix(float fov = 1.046666640, float aspect = 1.33333f, float znear = 0.5f, float zfar = 1000.f) {
		    float xymax = znear * tan(fov/2);
		    float ymin = -xymax;
		    float xmin = -xymax;
		    float width = xymax - xmin;
		    float height = xymax - ymin;
		    float depth = zfar - znear;
		    float q = -(zfar + znear) / depth;
		    float qn = -2 * (zfar * znear) / depth;
		    float w = 2 * znear / width;
		    w = w / aspect;
		    float h = 2 * znear / height;

		    _mat[0]  = w;
		    _mat[1]  = 0;
		    _mat[2]  = 0;
		    _mat[3]  = 0;
		    _mat[4]  = 0;
		    _mat[5]  = h;
		    _mat[6]  = 0;
		    _mat[7]  = 0;
		    _mat[8]  = 0;
		    _mat[9]  = 0;
		    _mat[10] = q;
		    _mat[11] = -1;
		    _mat[12] = 0;
		    _mat[13] = 0;
		    _mat[14] = qn;
		    _mat[15] = 0;
		    _prgm->setVariable("projectionMatrix", _mat);
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
