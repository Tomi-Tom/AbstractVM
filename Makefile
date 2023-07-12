##
## EPITECH PROJECT, 2023
## AbstractVM
## File description:
## Makefile
##

NAME		=	abstractVM

all:
	cmake -S . -B build
	cmake --build build
	cp build/abstractVM .

clean:
	$(RM) -r build
	$(RM) -r cmake-build-debug

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re