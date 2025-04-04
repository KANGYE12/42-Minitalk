# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanye <kanye@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 17:09:29 by kanye             #+#    #+#              #
#    Updated: 2025/04/01 16:04:22 by kanye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client

SERVER_SRC 		= server.c
CLIENT_SRC 		= client.c

SERVER_OBJS 	= $(SERVER_SRC:%.c=objMinitalk/%.o)
CLIENT_OBJS 	= $(CLIENT_SRC:%.c=objMinitalk/%.o)

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

PRINTF_DIR		= printf
PRINTF			= $(PRINTF_DIR)/printf.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.

RM				= rm -f

all:			$(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
				$(MAKE) -C $(PRINTF_DIR) 

objMinitalk/%.o: %.c
				@mkdir -p objMinitalk
				$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(LIBFT) $(PRINTF) $(SERVER_OBJS)
				$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(PRINTF) $(LIBFT)

$(CLIENT): $(LIBFT) $(PRINTF) $(CLIENT_OBJS)
				$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(PRINTF) $(LIBFT)

clean:
				$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
				@rm -rf objMinitalk
				-$(MAKE) clean -C $(LIBFT_DIR) 
				-$(MAKE) clean -C $(PRINTF_DIR) 

fclean:			clean
				$(RM) $(SERVER) $(CLIENT)
				-$(MAKE) fclean -C $(LIBFT_DIR) 
				-$(MAKE) fclean -C $(PRINTF_DIR) 

re:				fclean all

.PHONY: all clean fclean re
