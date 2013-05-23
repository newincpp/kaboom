CC		?=	gcc
CFLAGS	+=	-W -Wall -pedantic -ansi -Wextra -O3 -fPIC

SRC		=	ia.c

OBJ		=	$(SRC:.c=.o)
NAME		=	ia.so
DEBUG		=	-g

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += $(DEBUG)
debug: re
