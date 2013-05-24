#ifndef LIGHT_H_
# define LIGHT_H_

#include "Loader.hh"
#include "Mesh.hh"
#include "Shader.hh"
#include "AObject.hh"
#include "Types3D.hh"

namespace newin {
    class Light : public AObject {
	public:
	    explicit Light(ShadeProgram* prgm = NULL, const Vector3D<GLfloat>& p = Vector3D<GLfloat>(), const Vector3D<GLfloat>& lookat = Vector3D<GLfloat>(), const Vector3D<GLfloat>& r = Vector3D<GLfloat>());
	    void initialize();
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram* p);
	    void update(/*gdl::GameClock const &, */gdl::Input &);
	    void draw();
	    void setPos(const Vector3D<GLfloat>&);
	    void setRot(const Vector3D<GLfloat>&);
	    void setColor(const Vector3D<GLfloat>&);
	    void setIntensity(const float);
	    Vector3D<GLfloat> getPos() const;
	    Vector3D<GLfloat> getColor() const;
	    float getIntensity() const;
	    virtual ~Light();
	private:
	    Vector3D<GLfloat> getRot() const;
	    bool _changed;
	    Vector3D<GLfloat> _pos;
	    Vector3D<GLfloat> _lookat;
	    Vector3D<GLfloat> _color;
	    float _intensity;
	    ShadeProgram* _prgm;
    };
}

#endif /* !LIGHT_H_ */
