#ifndef APP_H_
# define APP_H_

#include "AObject.hh"
#include "Camera.hh"
#include "Light.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "Shader.hh"

class App : public gdl::Game {
    public :
	explicit App();
	virtual ~App();
	virtual void	initialize(void);
	virtual void	update(void);
	virtual void	draw(void);
	virtual void	unload(void);
    private:
	float _old_time;
	newin::Camera _camera;
	newin::Light _defaultLight;
	std::list<AObject*> _objects;
	newin::ShadeProgram* _defaultShader;
	AObject* _testLightMesh;
};

#endif /* !APP_H_ */
