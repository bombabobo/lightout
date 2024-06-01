##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

LIBRARY_NAME = libmy.a

HEADER_NAME = my.h

LIB_DIR = lib/my

NAME = lightout

CFILES	=	src/lightout.c \
		src/event.c \
		src/update.c \
		src/create_struct.c \

OFILES = $(CFILES:.c=.o)

CFLAGS = $(BASE_FLAGS) $(CSFML_FLAGS)

CSFML_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

BASE_FLAGS = -g3 -Wall -Wextra -lm

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -o $(NAME) $(CFILES) $(CFLAGS)

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME) vgcore.*

re: fclean all

reclean: fclean all
	@rm -rf $(OFILES)
