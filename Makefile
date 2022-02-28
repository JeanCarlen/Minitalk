# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:19:15 by jcarlen           #+#    #+#              #
#    Updated: 2022/02/28 15:16:30 by jcarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SERVER = server
SERVER_SRC = server.o

CLIENT = client
CLIENT_SRC = client.o

LIBFT = ./libft/

all : libft $(SERVER) $(CLIENT)

libft:
		@ $(MAKE) bonus -C $(LIBFT)

$(SERVER) : $(SERVER_SRC)
		$(CC) $(SERVER_SRC) -L$(LIBFT) -lft -o $(SERVER)

$(CLIENT) : $(CLIENT_SRC)
		$(CC) $(CLIENT_SRC) -L$(LIBFT) -lft  -o $(CLIENT)

%.o : %.c
		$(CC) $(FLAGS) $< -c

clean :
		rm -f server.o client.o

fclean : clean
		rm -f $(SERVER) $(CLIENT)

reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft reset