#ifndef SHADER_H_
# define SHADER_H_
#include <fstream>
#include <string>
#include <exception>
#include <map>
#include "glinclude.h"
#include "Vector3D.hh"

namespace newin {
    class Shader {
	public:
	    Shader(const std::string&, GLenum);
	    ~Shader();
	    void compile();
	    GLuint getID() const;
	private:
	    GLuint _shaderID;
	    char* source;
    };

    class ShadeProgram {
	public:
	    ShadeProgram(const Shader&, const Shader&);
	    ~ShadeProgram();
	    void setVariable(const std::string&, const GLfloat*);
	    void setVariable(const std::string&, const Vector3D<GLfloat>&);
	    void setVariable(const std::string&, const float, const float, const float, const float);
	    void setVariable(const std::string&, const float, const float, const float);
	    void setVariable(const std::string&, const int);
	    void setVariable(const std::string&, const float);
	    GLint getVariableLocation(const std::string&);
	    void enable();
	    void disenable();
	    GLuint getID() const;
	private:
	    GLuint _vID;
	    GLuint _fID;
	    GLuint _gID;
	    GLuint _prgmID;
	    GLboolean _enabled;
	    std::map<std::string, GLint> _vardb;
    };

    class ShaderException : public std::exception {
	public:
	    explicit ShaderException(const std::string&) throw();
	    virtual ~ShaderException() throw();
	    virtual const char* what() const throw();
	private:
	    ShaderException();
	    std::string _msg;
    };

}

#endif /* !SHADER_H_ */
