NAME = ft std
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

test: all ${NAME} diff clean

all:
	$(MAKE) std
	$(MAKE) ft

${NAME}:
	${CC} ${FLAGS} -DTESTED_NAMESPACE=$@ *.cpp -o $@

clean:
	rm -rf $(NAME)
	rm -rf ft.output
	rm -rf std.output

diff:
	time ./ft > ft.output
	time ./std > std.output
	diff ft.output std.output
