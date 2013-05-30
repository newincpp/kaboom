#include <iostream>
#include <fstream>
#include "Shader.hh"

////////////////////////////////////////////////////////////////////////////////
//				    SHADER
////////////////////////////////////////////////////////////////////////////////

newin::Shader::Shader(const std::string& name, GLenum TYPE) : _shaderID(glCreateShader(TYPE)) {
    size_t size;

    std::fstream s(name.c_str());
    if (!s.is_open()) {
	std::cerr << "\033[1;31m" << "failed to open shader file" << "\033[0m" << std::endl;
    } else {
	s.seekg(0, std::ios::end);
	size = s.tellg();
	source = new char[size];
	s.seekg(0, std::ios::beg);
	s.read(source, size);
	source[size-1] = 0;
	s.close();
	glShaderSource(_shaderID, 1, (const char**)&source, NULL);
    }
    compile();
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

newin::ShadeProgram::ShadeProgram(const Shader& vertex, const Shader& fragment, const Shader& geometry) : _vID(vertex.getID()), _fID(fragment.getID()), _gID(geometry.getID()), _enabled(false) {
    _prgmID = glCreateProgram();
    //glAttachShader(_prgmID, _gID);
    glAttachShader(_prgmID, _vID);
    glAttachShader(_prgmID, _fID);
    glLinkProgram(_prgmID);
    GLint status;
    glGetProgramiv(_prgmID, GL_LINK_STATUS, &status);
    if (GL_FALSE == status) {
	throw ShaderException("ERROR: failed to link shader programme");
    }
}

inline GLint newin::ShadeProgram::getVariableLocation(const std::string& variableName) {
    enable();
    std::map<std::string,GLint>::iterator uniform = _vardb.find(variableName);
    if (uniform == _vardb.end()) {
	GLint loc = glGetUniformLocation(_prgmID, variableName.c_str());
	if (loc < 0) {
	    std::cout << "ERROR getting variable named '" << variableName << "' from shader" << std::endl;
	    return -1;
	}
	_vardb[variableName] = loc;
	return loc;
    } else {
	return uniform->second;
    }
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const GLfloat* v) {
    glUniformMatrix4fv(getVariableLocation(variableName), 1, false, v);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const Vector3D<float>& v) {
    setVariable(variableName, v.getX(), v.getY(), v.getZ(), v.getW());
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const float x, const float y, const float z, const float w) {
    glUniform4f(getVariableLocation(variableName), x, y, z, w);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const float x, const float y, const float z) {
    glUniform3f(getVariableLocation(variableName), x, y, z);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const int i) {
    glUniform1i(getVariableLocation(variableName), i);
}

void newin::ShadeProgram::setVariable(const std::string& variableName, const float i) {
    glUniform1f(getVariableLocation(variableName), i);
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
