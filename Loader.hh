#ifndef LOADER_H_
# define LOADER_H_

#include <string>
#include <map>
#include "Mesh.hh"
#include "Vector3D.hh"

namespace newin {
    class Loader {
	public:
	    explicit Loader();
	    explicit Loader(const std::string&);
	    virtual ~Loader();
	    Mesh* genTri();
	    Mesh* genQuad();
	    Mesh* loadOBJ(const std::string&);
	    void loadMTL(Mesh*, const std::string&);
	private:
	    void orderInFaceList(std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*, std::fstream&);
	    std::string _filename;
	    std::map<std::string, Mesh*> _meshdb;
    };
}

#endif /* !LOADER_H_ */
