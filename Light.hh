#ifndef LIGHT_H_
# define LIGHT_H_

#include "Loader.hh"
#include "Mesh.hh"
#include "Shader.hh"
#include "AObject.hh"
#include "Vector3D.hh"
#include "Matrix4.hh"

namespace newin {
    class Light : public ::AObject {
	public:
	    explicit Light(ShadeProgram* prgm = NULL, const Vector3D<GLfloat>& p = Vector3D<GLfloat>(), const Vector3D<GLfloat>& r = Vector3D<GLfloat>(), const Vector3D<GLfloat>& c = Vector3D<GLfloat>());
	    void initialize();
	    void initialize(ShadeProgram*, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&, const Vector3D<GLfloat>&);
	    void setShader(ShadeProgram* p);
	    void update(/*gdl::GameClock const &, */gdl::Input &);
	    void draw();
	    void setDiff(const int);
	    void setIntensity(const float);
	    float getIntensity() const;
	    void shadowMap();
	    virtual ~Light();
	private:
	    void internalUpdate();
	    bool _changed;
	    int _diff;
	    float _intensity;
	    ShadeProgram* _prgm;
	    std::list<AObject*>* _shadowModelList;

	    void initShadowTex();
	    GLuint FramebufferName;
	    GLuint depthTexture;
	    ShadeProgram* _shad;
	    mat4<GLfloat> _proj;
	    mat4<GLfloat> _modv;

    };
}

#endif /* !LIGHT_H_ */
