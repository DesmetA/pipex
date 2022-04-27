# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 15:41:46 by user42            #+#    #+#              #
#    Updated: 2022/04/27 12:22:16 by adesmet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= pipex

SRC		= srcs/pipex.c srcs/utils.c srcs/notLibft.c srcs/notLibft2.c srcs/notLibft3.c
OBJS	= ${SRC:.c=.o}
HEADERS = includes/pipex.h
CC		= gcc
CFLAG	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}:    ${OBJS}
			$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -I./includes -o $@ -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
		
.PHONY : all clean fclean re