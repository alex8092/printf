# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 07:07:14 by amerle            #+#    #+#              #
#    Updated: 2015/01/28 07:09:38 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LD = ar

CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -Ilibft/include

LDFLAGS = rc

LDFLAGS_TEST = -Llibft -L. -lftprintf -lft

NAME = libftprintf.a

SRCS =	src/ft_printf.c \
		src/ft_printf_add_hexa.c \
		src/ft_printf_add_number.c \
		src/ft_printf_add_unumber.c \
		src/ft_printf_dispatch_arg.c \
		src/ft_printf_get_flags.c \
		src/ft_printf_get_precision.c \
		src/ft_printf_get_size.c \
		src/ft_printf_get_typemodifiers.c \
		src/ft_printf_instance.c \
		src/ft_printf_next.c \
		src/ft_printf_parse_char.c \
		src/ft_printf_parse_hexa.c \
		src/ft_printf_parse_int.c \
		src/ft_printf_parse_intmax.c \
		src/ft_printf_parse_intmaxoctal.c \
		src/ft_printf_parse_longhexa.c \
		src/ft_printf_parse_longint.c \
		src/ft_printf_parse_longlong.c \
		src/ft_printf_parse_longlonghexa.c \
		src/ft_printf_parse_longlongoctal.c \
		src/ft_printf_parse_longoctal.c \
		src/ft_printf_parse_longunsigned.c \
		src/ft_printf_parse_octal.c \
		src/ft_printf_parse_pointer.c \
		src/ft_printf_parse_sizet.c \
		src/ft_printf_parse_sizethexa.c \
		src/ft_printf_parse_sizetoctal.c \
		src/ft_printf_parse_string.c \
		src/ft_printf_parse_uintmax.c \
		src/ft_printf_parse_uintmax_hexa.c \
		src/ft_printf_parse_ulonglong.c \
		src/ft_printf_parse_unsigned.c \
		src/ft_printf_parse_upperhexa.c \
		src/ft_printf_parse_upperintmaxhexa.c \
		src/ft_printf_parse_upperlhexa.c \
		src/ft_printf_parse_upperllhexa.c \
		src/ft_printf_parse_uppersizethexa.c \
		src/ft_printf_parse_usizet.c \
		src/ft_printf_parse_wchar.c \
		src/ft_printf_parse_wstring.c

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
	(cd ../LibC && $(MAKE) clean)

fclean: clean
	rm -f $(NAME)

fclean_lib:
	(cd ../LibC && $(MAKE) fclean)

re: fclean all

test: all tests/main.o
	$(CC) -o $@ tests/main.o $(LDFLAGS_TEST)

.PHONY: all clean fclean re
