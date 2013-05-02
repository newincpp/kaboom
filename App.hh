#ifndef APP_H_
# define APP_H_

#include "AObject.hh"
#include "Camera.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"

class App : public gdl::Game {
    public :
	explicit App();
	virtual ~App();
	virtual void	initialize(void);
	virtual void	update(void);
	virtual void	draw(void);
	virtual void	unload(void);
    private:
	newin::Camera camera_;
	std::list<AObject*> objects_;
};

#endif /* !APP_H_ */
