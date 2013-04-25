#ifndef SHADER_H_
# define SHADER_H_
#include <fstream>
#include "glinclude.h"
#include "types3D.hh"

namespace newin {
    // TODO
    class uniform {};

    class Shader {
	public:
	    Shader(std::fstream*, GLenum);
	    void compile();
	    GLuint getID() const;
	private:
	    GLuint _shaderID;
	    char* source;
    };

    class ShadeProgram {
	public:
	    ShadeProgram(const Shader& vertex, const Shader& fragment);
	    void setVariable(const std::string&, const Vector3D<float>&);
	    void setVariable(const std::string&, const float, const float, const float, const float) ;
	    //void updateUniformVariable(std::string, const GLfloat, const GLfloat, const GLfloat, const GLfloat) ;
	    //void updateUniformVariable(std::string, const Vector3D<GLfloat>&) ;
	    void enabed();
	    GLuint getID() const;
	private:
	    GLuint _prgmID;
    };
}

#endif /* !SHADER_H_ */
