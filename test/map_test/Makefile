NAME = std ft
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
OUTPUT = $(NAME:=.output)

all: $(NAME) diff clean

${NAME}:
	${CC} ${FLAGS} -DTESTED_NAMESPACE=$@ *.cpp -o $@
	time ./$@ > $@.output

diff:
	diff ft.output std.output

clean:
	rm -rf $(NAME) $(OUTPUT)

.PHONY: all $(NAME) diff clean
