#ifndef MODEL_H_
# define MODEL_H_
#include <iostream>
#include "AObject.hh"
#include "libgdl_gl-2012.4/include/Model.hpp"
#include "libgdl_gl-2012.4/include/GameClock.hpp"

// this thinks is disoptimized and doesn't work with openGL 4

class GDLModel : public AObject {
	public:
	    GDLModel(const std::string&);
	    ~GDLModel(void);
	    void setAnim(const std::string&);
	    void initialize(void);
	    void update(/*gdl::GameClock const &,*/ gdl::Input &);
	    void draw(void);
	private:
	    std::string _curentAnim;
	    gdl::Model _model;
};

#endif /* !MODEL_H_ */
