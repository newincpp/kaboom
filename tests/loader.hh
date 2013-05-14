#ifndef LOADER_H_
# define LOADER_H_

#include <string>
#include "types3D.hh"

namespace newin {
    class Loader {
	public:
	    explicit Loader();
	    explicit Loader(const std::string&);
	    virtual ~Loader();
	    std::vector< Vector3D<GLfloat> >* genMesh();
	    std::vector< Vector3D<GLfloat> >* genTri();
	    std::vector< Vector3D<GLfloat> >* genQuad();
	    std::vector< Vector3D<GLfloat> >* loadOBJ();
	private:
	    std::string _filename;
    };
}

#endif /* !LOADER_H_ */
