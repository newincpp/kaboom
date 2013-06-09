SRC	= main.cpp \
	  Shader.cpp \
	  Camera.cpp \
	  Scene.cpp \
	  Mesh.cpp \
	  Loader.cpp \
	  Light.cpp \
	  Model.cpp \
	  Map.cpp \
	  Player.cpp \
	  Wall.cpp \
	  Bomb.cpp \
	  AudioPlayer.cpp \
	  Wall2.cpp

NAME	=bomberman

CXXFLAGS= -Wall -Wextra -W -g -D__DWIDTH=1024 -D__DHEIGHT=768 -std=c++0x -Wfatal-errors -I/usr/include/AL

LDFLAGS	= -Wl,-rpath -L./libgdl_gl-2012.4/lib -Wl,./libgdl_gl-2012.4/lib -lgdl_gl -lGLU -lGLEW -lopenal -lsndfile

OBJ	= $(SRC:.cpp=.o)

RM	= rm -f

CXX	= g++

all: $(NAME)

extract:
	tar --keep-newer-files -xf libgdl_gl-2012.4.tgz

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
