# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlima <vlima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 12:06:13 by vlima             #+#    #+#              #
#    Updated: 2023/09/25 11:49:55 by vlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SERVER_NAME = server
CLIENT_NAME = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

all: $(SERVER_NAME) $(CLIENT_NAME) $(PRINTF)

$(SERVER_NAME) $(CLIENT_NAME):
	@$(CC) $(CFLAGS) -g $@.c -o $@ ft_printf.c


clean:
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)

fclean: clean

re: fclean all