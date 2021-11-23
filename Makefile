# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 09:14:24 by vl-hotel          #+#    #+#              #
#    Updated: 2021/10/31 14:56:37 by vl-hotel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_display_xmaj.c \
ft_display_int.c \
ft_display_s.c \
ft_display_x.c \
ft_display_c.c \
ft_display_p.c \
ft_display_u.c \
ft_printf.c \
ft_display_pourc.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re