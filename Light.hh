#ifndef LIGHT_H_
# define LIGHT_H_

#include "Shader.hh"
#include "AObject.hh"
#include "Types3D.hh"

namespace newin {
    class Light : public AObject {
	public:
	    explicit Light(ShadeProgram* prgm = NULL, const Vector3D<GLfloat>& p = Vector3D<GLfloat>(), const Vector3D<GLfloat>& r = Vector3D<GLfloat>());
	    void initialize();
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram* p);
	    void update(/*gdl::GameClock const &, */gdl::Input &);
	    void draw();
	    void setPos(const Vector3D<GLfloat>&);
	    void setDiff(const Vector3D<GLfloat>&);
	    void setSpecular(const newin::Vector3D<GLfloat>&);
	    Vector3D<GLfloat> getPos();
	    Vector3D<GLfloat> getDiff();
	    Vector3D<GLfloat> getSpecular();
	    virtual ~Light();
	private:
	    bool _changed;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _diff;
	    Vector3D<GLfloat> _spec;
	    ShadeProgram* _prgm;
    };
}

#endif /* !LIGHT_H_ */
