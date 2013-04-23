SRC	=main.cpp

NAME	=bomberman

UNPACK	= tar

PFLAGS	= -kxvzf

CXXFLAG	= -Wall -Wextra -W -Werror

LDFLAGS	= #-lgdl_gl

OBJ	= $(SRC:.cpp=.o)

RM	= rm -f

CXX	= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(UNPACK) $(PFLAGS) ./libgdl_gl-2012.4.tgz
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

