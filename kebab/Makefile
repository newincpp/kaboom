##
## Makefile for  in /home/bartholomew/Programmation/Cpp/nibbler-2016-strohe_d
##
## Made by bartholomew
## Login   <exabot@gmail.com>
##
## Started on  Tue Mar 19 17:06:41 2013
## Last update Tue Mar 19 18:43:03 2013 theo marchal
##

CXX		?=	g++
CXXFLAGS	+=	-W -Wall -pedantic -ansi -Wextra -O3
LDFLAGS		+=	-ldl

SRC		=	main.cpp	\
			LoadSO.cpp
OBJ		=	$(SRC:.cpp=.o)
NAME		=	loader
DEBUG		=	-g

all: libs $(NAME)

libs:
	@(cd ./IA && $(MAKE))

$(NAME):$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@(cd ./IA && $(MAKE) clean)
	$(RM) $(OBJ)

fclean: clean
	@(cd ./IA && $(MAKE) fclean)
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += $(DEBUG)
debug: re
