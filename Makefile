CC=clang++
FLAGS=-Wall -Wextra -Werror
MAIN=main_full_teste.cpp

all: ft std

ft:
	$(CC) $(FLAGS) -DTESTED_NAMESPACE=ft $(MAIN) -o ft

std:
	$(CC) $(FLAGS) -DTESTED_NAMESPACE=std $(MAIN) -o std

fclean:
	rm -rf ft
	rm -rf std

re: fclean all
