# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 21:40:55 by ahbajaou          #+#    #+#              #
#    Updated: 2023/01/29 22:18:41 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_hexad.c 
SERVER_SRC = server.c $(SRC) 
CLIENT_SRC = client.c $(SRC)

all : client server

server : $(SERVER_SRC)
	cc $(CFLAGS) $(SERVER_SRC) -o server

client : $(CLIENT_SRC)
	cc $(CFLAGS) $(CLIENT_SRC) -o client
	
clean : 
	rm -f server client

fclean : clean

re: fclean all