#include <iostream>
#include <fstream>
#include "Shader.hh"
#include "Types3D.hh"

////////////////////////////////////////////////////////////////////////////////
//				    SHADER
////////////////////////////////////////////////////////////////////////////////

newin::Shader::Shader(std::fstream* s, GLenum TYPE) : _shaderID(glCreateShader(TYPE)) {
    size_t size;

    s->seekg(0, std::ios::end);
    size = s->tellg();
    source = new char[size];
    s->seekg(0, std::ios::beg);
    s->read(source, size);
    source[size-1] = 0;
    s->close();
    delete s;
    glShaderSource(_shaderID, 1, (const char**)&source, NULL);
}

void newin::Shader::compile() {
    glCompileShader(_shaderID);
    int result;
    glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
	if (result == GL_INVALID_VALUE )
	    std::cout << "GL_INVALID_VALUE" << std::endl;
	else if (result == GL_INVALID_OPERATION)
	    std::cout << "GL_INVALID_OPERATION" << std::endl;
	else
	    std::cout << "GL_INVALID_VALUE :" << result << std::endl;
	std::cerr << "\033[1;31mERROR while compiling shader\033[0m" << std::endl;
	int length;
	glGetShaderiv(_shaderID, GL_INFO_LOG_LENGTH, &length);
	if (length > 0) {
	    // create a log of error messages
	    char* errorLog = new char[length];
	    int written;
	    glGetShaderInfoLog(_shaderID, length, &written, errorLog);
	    errorLog[written] = 0;
	    std::cerr << "Shader error log;" << std::endl << "\"" << errorLog << "\"" << std::endl;
	    throw ShaderException(errorLog);
	    delete [] errorLog;
	}
    } else {
	std::cout << "\033[1;32m" << "shader compiled !" << "\033[0m" << std::endl;
    }
}

newin::Shader::~Shader() {
    glDeleteShader(_shaderID);
}

GLuint newin::Shader::getID() const {
    return _shaderID;
}

/////////////////////////////////////////////////////////////////////////////
//  				    PROGRAM
/////////////////////////////////////////////////////////////////////////////

newin::ShadeProgram::ShadeProgram(const Shader& vertex, const Shader& fragment) : _vID(vertex.getID()), _fID(fragment.getID()), _enabled(false) {
    _prgmID = glCreateProgram();
    glAttachShader(_prgmID, vertex.getID());
    glAttachShader(_prgmID, fragment.getID());
    glLinkProgram(_prgmID);
    GLint status;
    glGetProgramiv(_prgmID, GL_LINK_STATUS, &status);
    if (GL_FALSE == status) {
//	std::cout << "ERROR: failed to link shader programme" << std::endl;
	throw ShaderException("ERROR: failed to link shader programme");
    }
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const GLfloat* v) {
    enable();
    GLint loc = glGetUniformLocation(_prgmID, variableName.c_str());
    if (loc < 0) {
	std::cout << "ERROR getting variable named '" << variableName << "' from shader" << std::endl;
	return ;
    }
    glUniformMatrix4fv(loc, 1, false, v);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const Vector3D<float>& v) {
    setVariable(variableName, v.getX(), v.getY(), v.getZ(), v.getW());
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const float x, const float y, const float z, const float w) {
    enable();
    GLint loc = glGetUniformLocation(_prgmID, variableName.c_str());
    if (loc < 0) {
	std::cout << "ERROR getting variable named '" << variableName << "' from shader" << std::endl;
	return ;
    }
    glUniform4f(loc, x, y, z, w);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const float x, const float y, const float z) {
    enable();
    GLint loc = glGetUniformLocation(_prgmID, variableName.c_str());
    if (loc < 0) {
	std::cout << "ERROR getting variable named '" << variableName << "' from shader" << std::endl;
	return ;
    }
    glUniform3f(loc, x, y, z);
}

void newin::ShadeProgram::enable() {
    if (!_enabled) {
	glUseProgram(_prgmID);
	_enabled = true;
    }
}

void newin::ShadeProgram::disenable() {
    _enabled = false;
    glUseProgram(0);
}

GLuint newin::ShadeProgram::getID () const {
    return _prgmID;
}

newin::ShadeProgram::~ShadeProgram() {
    glDetachShader(_prgmID, _vID);
    glDetachShader(_prgmID, _fID);
    glDeleteProgram(_prgmID);
}

/////////////////////////////////////////////////////////////////////////////
//  				    EXCEPTION
/////////////////////////////////////////////////////////////////////////////

newin::ShaderException::ShaderException(const std::string& m) throw() {
    _msg = m;
}

newin::ShaderException::~ShaderException() throw() {
}

const char* newin::ShaderException::what() const throw() {
    return _msg.c_str();
}
