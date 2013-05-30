#ifndef LOADER_H_
# define LOADER_H_

#include <string>
#include "Mesh.hh"
#include "Vector3D.hh"

namespace newin {
    class Loader {
	public:
	    explicit Loader();
	    explicit Loader(const std::string&);
	    virtual ~Loader();
	    Mesh* genTri(ShadeProgram*);
	    Mesh* genQuad(ShadeProgram*);
	    Mesh* loadOBJ(ShadeProgram*, const std::string&);
	    void loadMTL(Mesh*, const std::string&);
	    Mesh* loadDAE(ShadeProgram* p, const std::string& fName);
	private:
	    void orderInFaceList(std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*,std::vector< Vector3D<GLfloat> >*, std::fstream&);
	    std::string _filename;
    };
}

#endif /* !LOADER_H_ */
