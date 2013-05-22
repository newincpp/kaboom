SRC	= main.cpp \
	  Shader.cpp \
	  Camera.cpp \
	  App.cpp \
	  Mesh.cpp \
	  Loader.cpp \
	  Light.cpp \
	  Model.cpp

NAME	=bombermann

CXXFLAGS= -Wall -Wextra -W -Werror -g

LDFLAGS	= -Wl,-rpath -L./libgdl_gl-2012.4/lib -Wl,./libgdl_gl-2012.4/lib -lgdl_gl -lGLU -lGLEW

OBJ	= $(SRC:.cpp=.o)

RM	= rm -f

CXX	= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

