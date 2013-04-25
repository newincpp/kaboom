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
		std::vector<GLvector3f>* toGLvector3f(const std::vector< Vector3D<T> >& in) {
		    std::vector<GLvector3f>* out = new std::vector<GLvector3f>();
		    for (unsigned int i = 0; i < in.size() ; ++i) {
			out->push_back(in[i].toStruct());
		    }
		    return out;
		}
		void normalize() {
		    float mag = sqrt(_x*_x + _y*_y + _z*_z);
		    _x /= mag;
		    _y /= mag;
		    _z /= mag;
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
/*
    void setIdentityMatrix(float *mat, int size) {
	// fill matrix with 0s
	for (int i = 0; i < size * size; ++i)
	    mat[i] = 0.0f;
	// fill diagonal with 1s
	for (int i = 0; i < size; ++i)
	    mat[i + i * size] = 1.0f;
    }

    void setTranslationMatrix(float *mat, float x, float y, float z) {
	setIdentityMatrix(mat,4);
	mat[12] = x;
	mat[13] = y;
	mat[14] = z;
    }

    void multMatrix(float *a, float *b) {
	float res[16];
	for (int i = 0; i < 4; ++i) {
	    for (int j = 0; j < 4; ++j) {
		res[j*4 + i] = 0.0f;
		for (int k = 0; k < 4; ++k) {
		    res[j*4 + i] += a[k*4 + i] * b[j*4 + k];
		}
	    }
	}
	for (unsigned int i = 16 * sizeof(float); i != 0 ; --i) {
	   a[i] = res[i];
	}
	//memcpy(a, res, 16 * sizeof(float));
    }*/
}

#endif /* !TYPES3D_H_ */
