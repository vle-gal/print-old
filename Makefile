# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 08:32:21 by agrumbac          #+#    #+#              #
#    Updated: 2018/01/18 09:47:47 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBSRC = ft_atoi.c ft_bzero.c\
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
ft_toupper.c

SRC = ft_flags.c ft_flags_sec.c ft_printf_long.c ft_printf_u.c \
ft_printf_d.c ft_printf_p.c ft_printf_x_flags.c \
ft_printf_c.c ft_printf_o.c ft_printf_u_flags.c \
ft_printf_d_flags.c ft_printf_s.c ft_printfl.c \
ft_printf_conversion.c ft_printf_o_flags.c ft_printf_x.c

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:.c=.o)

SRCDIR = ./srcs/

LIBOBJDIR = ./libft/objs/

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all:${NAME}

${NAME}:
	make -C libft/
	${CC} -Ilibft/doth/ -I. -c $(addprefix ${SRCDIR}, ${SRC}) ${CFLAGS}
	ar rc ${NAME} ${OBJ} $(addprefix ${LIBOBJDIR}, ${LIBOBJ})
	ranlib ${NAME}

clean:
	rm -f ${OBJ}
	#make -C libft/ clean

fclean: clean
	rm -f ${NAME}
	#make -C libft/ fclean

re: fclean all

build:
	@${CC} -Ilibft/doth/ -I. -c $(addprefix ${SRCDIR}, ${SRC})
	@ar rcs ${NAME} ${OBJ} $(addprefix ${LIBOBJDIR}, ${LIBOBJ})
	@${CC} printf_main.c ${NAME} -o test
	./test

test:
	@rm -f test
	@rm -f a.out
	@${CC} printf_main.c ${NAME} -o test
	./test

.PHONY: clean fclean test build

#make build && make test && ./test
