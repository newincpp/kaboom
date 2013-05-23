SRC	= BFactory.cpp \
	  Bombe.cpp \
	  Fire.cpp \
	  Heart.cpp \
	  Roller.cpp \
	  Skate.cpp \
	  Wall.cpp \

NAME	= bombermann

CXXFLAGS= -Wall -Wextra -W -Werror -g

LDFLAGS	= -lGL -lGLU -Wl,-rpath -L./libgdl_gl-2012.4/lib -Wl,./libgdl_gl-2012.4/lib -lgdl_gl

OBJ	= $(SRC:.cpp=.o)

RM	= rm -f

CXX	= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

