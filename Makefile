##
## EPITECH PROJECT, 2022
## Project name
## File description:
## Project description
##

SRC	=	$(shell find m_rect -name '*.c')		\
		$(shell find m_circle -name '*.c')		\
		$(shell find m_vertex -name '*.c')		\
		$(shell find m_text -name '*.c')		\
		$(shell find m_button -name '*.c')		\
		$(shell find m_fshader -name '*.c')		\
		$(shell find m_rtex -name '*.c')		\
		$(shell find m_object -name '*.c')		\
		$(shell find m_transform -name '*.c')	\
		$(shell find m_init -name '*.c')		\
		$(shell find m_render -name '*.c')		\
		$(shell find m_utils -name '*.c')		\
		$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	app

CSFML = -lcsfml-window -lcsfml-graphics -lcsfml-system -lm

all:	$(NAME)

library:
	make -C lib/my

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g $(CSFML) lib/libmy.a

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all

.PHONY: all clean fclean re
