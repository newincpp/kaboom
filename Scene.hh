#ifndef APP_H_
# define APP_H_

#include "AObject.hh"
#include "Camera.hh"
#include "Light.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "Shader.hh"

class SceneMgr : public gdl::Game {
    public :
	explicit SceneMgr();
	virtual ~SceneMgr();
	std::list<AObject*> getObjectList() const ;
	newin::Camera* getCam(); // no constness because of pointer (return pointer for future modification from user like remote)
	AObject* getLight(); // like cam
	void addModel(AObject*, const std::string&);
    private:
	virtual void	initialize(void);
	virtual void	update(void);
	virtual void	draw(void);
	virtual void	unload(void);
	float _old_time;
	newin::Camera _camera;
	newin::Light _defaultLight;
	std::list<AObject*> _objects;
	newin::ShadeProgram* _defaultShader;
};

#endif /* !APP_H_ */