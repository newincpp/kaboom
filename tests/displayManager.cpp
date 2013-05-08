#include <iostream>
#include <fstream>
#include "glinclude.h"
#include <GL/glfw.h>
#include "camera.hh"
#include "light.hh"
#include "displayManager.hh"
#include "loader.hh"

#ifndef GL_ARB_multitexture
#error "openGL need an update =/"
#endif
#include "mesh.hh"

newin::Display::Display(const int w, const int h) : _w(w), _h(h) , _depth(0) {
    if (glfwInit() != GL_TRUE)
	throw DisplayEx();
    /* Create a windowed mode window and its OpenGL context */
    //glfwOpenWindow(w, h, red, green, blue, alpha, deph, stencil, mode)
    if (glfwOpenWindow(w, h, 8, 8, 8, 0, _depth, 0, GLFW_WINDOW) != GL_TRUE)
	throw DisplayEx();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //float aspect_ratio = ((float)_w) / _h;
    //glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 50);
    GLenum err = glewInit();
    if (err != GLEW_OK)
	throw DisplayEx();
    const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString (GL_VERSION); // version as a string
    std::cout << "render device : " << renderer << std::endl;
    std::cout << "openGL version : " << version << std::endl;

    int major, minor, rev;
    glfwGetGLVersion(&major, &minor, &rev);
    std::cout << "glfw version : " << major << "."<< minor << "-r" << rev << std::endl;

    glfwSetWindowTitle("demo");
}

//
//int glfwGetJoystickParam( int joy, int param )
//int glfwGetJoystickPos( int joy, float *pos, int numaxes )
//
// float position[ 2 ];
// glfwGetJoystickPos( GLFW_JOYSTICK_1, position, 2 );
//
//int glfwGetJoystickButtons( int joy, unsigned char *buttons,
//int numbuttons )
//
//
//
//double glfwGetTime( void )
//void glfwSetTime( double time )
//void glfwSleep( double time )
//
//
//void glfwSetKeyCallback( GLFWkeyfun cbfun )
//

void newin::Display::run() {
    int esc_pressed = glfwGetKey( GLFW_KEY_ESC );
    bool runing = true;

    Mesh m(Loader().genQuad());
    Shader v(new std::fstream("defuse_vs.glsl"), GL_VERTEX_SHADER);
    v.compile();
    Shader f(new std::fstream("defuse_fs.glsl"), GL_FRAGMENT_SHADER);
    f.compile();
    ShadeProgram* prgm = new ShadeProgram(v, f);
    m.setShader(prgm);
    m.setColor(Vector3D<GLfloat>(0.0, 0.4, 0.25, 1.0));

    Light l(prgm, Vector3D<GLfloat>(0.25,0,0,0), Vector3D<GLfloat>(1,1,1,0));
    Camera c(prgm, Vector3D<GLfloat>(0,0,0), Vector3D<GLfloat>(0,0,0));
    float x = 0;
    float y = 0;
    float z = 0;
    c.setPos(Vector3D<GLfloat>(0,0,0));
    bool toggled = false;
    bool wiretoogle = false;
    while (runing) {
	esc_pressed = glfwGetKey(GLFW_KEY_ESC);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.01, 0.1, 1.0f); // dark blue
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing is to use a "less than" function
	glEnable(GL_CULL_FACE); // enable culling of faces
	glCullFace(GL_BACK); // do not waste time drawing faces that are on the "back" side with respect to the view direction
	glFrontFace(GL_CCW); // define faces created counter-clockwise with respect to the view direction as being on the "front" side

	m.render();
	if ((!glfwGetWindowParam(GLFW_OPENED)) || (esc_pressed == true)) {
	    runing = false;
	}
	wiretoogle = glfwGetKey(GLFW_KEY_SPACE);
	if (wiretoogle != toggled){
	    toggled = wiretoogle;
	    //m.toogleWireframe(true);
	}

	if (glfwGetKey('W')) {
	    y += 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	} if (glfwGetKey('S')) {
	    y -= 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	} if (glfwGetKey('A')) {
	    x += 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	} if (glfwGetKey('D')) {
	    x -= 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	} if (glfwGetKey('Q')) {
	    z -= 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	} if (glfwGetKey('E')) {
	    z += 0.25;
	    c.setPos(Vector3D<GLfloat>(x,y,z));
	}
	glfwSwapBuffers();
    }
}

int newin::Display::getDepth() const {
    return _depth;
}

int newin::Display::getWidth() const {
    return _w;
}

int newin::Display::getHeight() const {
    return _h;
}

inline int newin::Display::lenAlloc() const {
    return _w * _h * (_depth / 8);
}

newin::Display::~Display() {
    glfwTerminate();
}

void newin::Display::operator=(const char* n) {
    for (int i = 0; i < lenAlloc();++i)
	_fb[i] = n[i];
}

//void newin::Display::operator>>(char* &to) {
//    (void)to;
//}
//
//void newin::Display::operator<<(char* n) {
//    (void)n;
//}


//
//int glfwLoadTexture2D( const char *name, int flags )
//
//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//GL_LINEAR_MIPMAP_LINEAR );
//
//// Use bilinear interpolation for magnification
//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
//GL_LINEAR );
//
//
//// Enable texturing
//glEnable( GL_TEXTURE_2D );
//
//
//int glfwReadImage( const char *name, GLFWimage *img, int flags )
//
//  typedef struct {
//	int Width, Height; // Image dimensions
//  	int Format; // OpenGL pixel format
//  	int BytesPerPixel; // Number of bytes per pixel
//  	unsigned char *Data;// Pointer to pixel data
//  } GLFWimage;
//
//void glfwFreeImage( GLFWimage *img )
//
