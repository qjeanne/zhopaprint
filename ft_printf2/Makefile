# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:48:19 by tjohnnie          #+#    #+#              #
#    Updated: 2021/01/21 15:48:24 by tjohnnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=			src/ft_printf.c \
                    src/ft_parsing.c \
                    src/ft_print_s.c \
                    src/ft_print_c.c \
                    src/ft_print_p.c \
                    src/ft_print_prcnt.c \
                    src/ft_print_i.c \
                    src/ft_print_x.c \
                    src/ft_print_u.c

OBJS	=			${SRCS:.c=.o}

NAME	=			libftprintf.a

CC		=			gcc

CFLAGS	=			-Wall -Wextra -Werror -I ft_printf.h

.c.o	=			${CC} ${CFLAGS} $< -o ${<:.c-.o}

$(NAME):			${OBJS}
					cd libft && make
					cp ./libft/libft.a $(NAME)
					ar rc ${NAME} ${OBJS}

all:				${NAME}

clean:
					rm -f ${OBJS}
					cd libft && make clean

fclean:				clean
					rm -f ${NAME}
					cd libft && make fclean

re:					fclean all

.PHONY:				all re fclean clean
