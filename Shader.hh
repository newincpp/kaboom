#ifndef SHADER_H_
# define SHADER_H_
#include <fstream>
#include "glinclude.h"
#include "Types3D.hh"

namespace newin {
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
	    void setVariable(const std::string&, const Vector3D<GLfloat>&);
	    void setVariable(const std::string&, const float, const float, const float, const float);
	    void setVariable(const std::string&, const float, const float, const float);
	    void enable();
	    void disenable();
	    GLuint getID() const;
	private:
	    GLuint _prgmID;
	    GLboolean _enabled;
    };
}

#endif /* !SHADER_H_ */
