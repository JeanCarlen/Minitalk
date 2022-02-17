# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:19:15 by jcarlen           #+#    #+#              #
#    Updated: 2022/02/17 14:02:31 by jcarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SERVER = server
SERVER_SRC = server.o

CLIENT = client
CLIENT_SRC = client.o

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_SRC)
		$(CC) $(SERVER_SRC) -o $(SERVER)

$(CLIENT) : $(CLIENT_SRC)
		$(CC) $(CLIENT_SRC) -o $(CLIENT)

%.o : %.c
		$(CC) $(FLAGS) $< -c

clean :
		rm -f server.o client.o

fclean :
		rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re