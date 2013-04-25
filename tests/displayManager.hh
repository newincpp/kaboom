#ifndef DISPLAYMANAGER_H_
# define DISPLAYMANAGER_H_
#include <exception>
#include <string>

namespace newin {
    class DisplayEx : std::exception {
	virtual const char* what() const throw() {
	    return "something wrong happened while creating window";
	}
    };
    class Display {
	public:
	    Display(const int w = 1024, const int h = 768);
	    void run();
	    void operator=(const char*);
	    int lenAlloc() const;
	    int getDepth() const;
	    int getWidth() const;
	    int getHeight() const;
	    ~Display();
	private:
	    char* _fb;
	    int _w;
	    int _h;
	    int _depth;
    };
}


#endif /* !DISPLAYMANAGER_H_ */
