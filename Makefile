# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 15:41:46 by user42            #+#    #+#              #
#    Updated: 2022/04/26 17:20:30 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= pipex

SRC		= srcs/pipex.c srcs/utils.c
OBJS	= ${SRC:.c=.o}
LIBFT	= libft/libft.a
HEADERS = libft/libft.h includes/pipex.h
CC		= gcc
CFLAG	= -Wall -Wextra -Werror



all: ${NAME}

${NAME}:	${LIBFT} ${OBJS}
			$(CC) $(CFLAGS) -o ${NAME} ${OBJS} ${LIBFT}

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -I./includes -o $@ -c $<

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) clean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f $(LIBFT)
	rm -f ${NAME}

re: fclean all
		
.PHONY : all clean fclean re