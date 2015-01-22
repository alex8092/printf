CC = gcc
LD = ar

CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -Ilibft/include

LDFLAGS = rc

LDFLAGS_TEST = -Llibft -lft -L. -lftprintf

NAME = libftprintf.a

SRCS = $(shell find src -name "*.c")

OBJS = $(SRCS:.c=.o)

all: make_lib $(NAME)

make_lib:
	(cd libft && $(MAKE))

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^
	ranlib $@

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

clean_lib:
	(cd libft && $(MAKE) clean)

fclean: clean
	rm -f $(NAME)

fclean_lib:
	(cd libft && $(MAKE) fclean)

re: fclean all

test: $(NAME) tests/main.o
	$(CC) -o $@ tests/main.o $(LDFLAGS_TEST)

.PHONY: all clean fclean re