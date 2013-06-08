#ifndef APP_H_
# define APP_H_

#include "AObject.hh"
#include "Camera.hh"
#include "Light.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "Shader.hh"

namespace newin {
    class SceneMgr : public gdl::Game {
	public :
	    explicit SceneMgr();
	    virtual ~SceneMgr();
	    std::list<AObject*> getObjectList() const ;
	    newin::Camera* getCam(); // no constness because of pointer (return pointer for future modification from user like remote)
	    void setCamPos(const Vector3D<GLfloat>&); // no constness because of pointer (return pointer for future modification from user like remote)
	    AObject* addModel(const std::string&, const std::string&);
	    void delModel(const std::string&);
	    std::vector<newin::Light> getLights();
	    newin::Light *getLight(unsigned int);
	    unsigned int addLight(newin::Light);
	    virtual void update(void);
	    AObject* getModel(const std::string&);
	private:
	    virtual void	initialize(void);
	    virtual void	draw(void);
	    virtual void	unload(void);
 	    int _height;
	    int _width;
	    float _old_time;
	    newin::Camera _camera;
	    std::vector<newin::Light> _lights;
	    std::list<AObject*> _objects;
	    newin::ShadeProgram* _defaultShader;
	    bool _contextEnabed;
    };
}

#endif /* !APP_H_ */
