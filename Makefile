# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:19:15 by jcarlen           #+#    #+#              #
#    Updated: 2022/03/01 11:31:13 by jcarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SERVER = server
SERVER_SRC = server.o

SERVER_BONUS = server_bonus
SERVER_SRC_BONUS = server_bonus.o

CLIENT = client
CLIENT_SRC = client.o

CLIENT_BONUS = client_bonus
CLIENT_SRC_BONUS = client_bonus.o

LIBFT = ./libft/

all : libft $(SERVER) $(CLIENT)

bonus : libft $(SERVER_BONUS) $(CLIENT_BONUS)

libft:
		@ $(MAKE) bonus -C $(LIBFT)

$(SERVER) : $(SERVER_SRC)
		$(CC) $(SERVER_SRC) -L$(LIBFT) -lft -o $(SERVER)

$(CLIENT) : $(CLIENT_SRC)
		$(CC) $(CLIENT_SRC) -L$(LIBFT) -lft  -o $(CLIENT)

$(SERVER_BONUS) : $(SERVER_SRC_BONUS)
		$(CC) $(SERVER_SRC_BONUS) -L$(LIBFT) -lft -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CLIENT_SRC_BONUS)
		$(CC) $(CLIENT_SRC_BONUS) -L$(LIBFT) -lft  -o $(CLIENT_BONUS)

%.o : %.c
		$(CC) $(FLAGS) $< -c

clean :
		rm -f server.o client.o server_bonus.o client_bonus.o

fclean : clean
		rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft reset bonus