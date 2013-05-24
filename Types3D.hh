#ifndef __TYPES3D_H_
# define __TYPES3D_H_
#include <vector>
#include "glinclude.h"

namespace newin {

    struct GLvector3f {
	GLfloat x;
	GLfloat y;
	GLfloat z;
    };

    template <typename T>
	class Vector3D {
	    public:
		explicit Vector3D(const T& x = 0, const T& y = 0, const T& z = 0, const T& w = 0) : _x(x), _y(y), _z(z), _w(w) {}
		virtual ~Vector3D() {}
		Vector3D& operator+(const Vector3D& in) {_x += in._x; _y += in._y; _z += in._z; _w += in._w; return *this; }
		Vector3D& operator-(const Vector3D& in) {_x -= in._x; _y -= in._y; _z -= in._z; _w -= in._w; return *this; }
		Vector3D& operator*(const Vector3D& in) {_x *= in._x; _y *= in._y; _z *= in._z; _w *= in._w; return *this; }
		Vector3D& operator/(const Vector3D& in) {_x /= in._x; _y /= in._y; _z /= in._z; _w /= in._w; return *this; }
		GLvector3f toStruct() const { GLvector3f x; x.x = _x; x.y = _y; x.z = _z; return x; }
		void normalize() {
		    float mag = sqrt(_x*_x + _y*_y + _z*_z);
		    _x /= mag;
		    _y /= mag;
		    _z /= mag;
		}

		static std::vector<GLvector3f>* toGLvector3f(const std::vector< Vector3D<T> >& in) {
		    std::vector<GLvector3f>* out = new std::vector<GLvector3f>();
		    for (unsigned int i = 0; i < in.size() ; ++i) {
			out->push_back(in[i].toStruct());
		    }
		    return out;
		}

		static GLfloat* toGLfloatArray(const std::vector< Vector3D<T> >& in) {
		    GLfloat* out = new float [in.size() * 3];
		    int j = 0;
		    for (int i = in.size() -1; i != -1 ; --i) {
			out[j + 0] = in.at(i).getX();
			out[j + 1] = in.at(i).getY();
			out[j + 2] = in.at(i).getZ();
			j += 3;
		    }
		    return out;
		}

		T getX() const { return _x; }
		T getY() const { return _y; }
		T getZ() const { return _z; }
		T getW() const { return _w; }

		void setX(const T& v) { _x = v; }
		void setY(const T& v) { _y = v; }
		void setZ(const T& v) { _z = v; }
		void setW(const T& v) { _w = v; }
	    private:
		T _x;
		T _y;
		T _z;
		T _w;
	};

    template <typename T>
    class mat4 {
	public:
	    explicit mat4() {}
	    virtual ~mat4() {}
	    void setIdentityMatrix() {
		// fill matrix with 0s
		for (int i = 0; i < 4 * 4 ; ++i)
		    mat[i] = 0.0f;
		// fill diagonal with 1s
		for (int i = 0; i < 4 ; ++i)
		    mat[i + i * 4] = 1.0f;
	    }

	    void setTranslationMatrix(/*float x, float y, float z,*/ Vector3D<T> v) {
		setIdentityMatrix();
		mat[12] = v.getX();//x;
		mat[13] = v.getY();//y;
		mat[14] = v.getZ();//z;
	    }

	    //void multMatrix(float *a, float *b) {
	    mat4& operator*(mat4& in){
		T res[16];
		for (int i = 0; i < 4; ++i) {
		    for (int j = 0; j < 4; ++j) {
			res[j*4 + i] = 0.0f;
			for (int k = 0; k < 4; ++k) {
			    res[j*4 + i] += mat[k*4 + i] * in[j*4 + k];
			}
		    }
		}
		for (unsigned int i = 16 * sizeof(float); i != 0 ; --i) {
		    mat[i] = res[i];
		}
		return *this;
	    }
	private:
	    T mat[16];
    };
}

#endif /* !TYPES3D_H_ */
