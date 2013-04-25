SRC		= main.cpp \
		  displayManager.cpp \
		  shader.cpp \
		  mesh.cpp \
		  camera.cpp

RASM		= start.o
ASM		= #$(RASM)

NAME		= opgl

OPFLAGS		=-DOPTIMIZER
CXXFLAGS	= -Wall -Wextra -W -g

OPLDFLAGS	=-nostartfiles /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/libstdc++.so
LDFLAGS		= -lglfw -lGL -lGLEW

OBJ		= $(SRC:.cpp=.o)

RM		= rm -f

CXX		= g++

LD		= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(OBJ) $(ASM) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re:
	make -B

.PHONY: all clean fclean re

