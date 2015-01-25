CC = gcc
LD = ar

CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -I../LibC/include

LDFLAGS = rc

LDFLAGS_TEST = -L../LibC -L. -lftprintf -lft 

NAME = libftprintf.a

SRCS = $(shell find src -name "*.c")

OBJS = $(SRCS:.c=.o)

all: make_lib $(NAME)

make_lib:
	(cd ../LibC && $(MAKE))

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^
	ranlib $@

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

clean_lib:
	(cd ../LibC && $(MAKE) clean)

fclean: clean
	rm -f $(NAME)

fclean_lib:
	(cd ../LibC && $(MAKE) fclean)

re: fclean all

test: all tests/main.o
	$(CC) -o $@ tests/main.o $(LDFLAGS_TEST)

.PHONY: all clean fclean re
