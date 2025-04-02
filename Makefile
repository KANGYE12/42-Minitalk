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

NAME			= prueba

SRCS			= server.c client.c

OBJS			= $(SRCS:%.c=objMinitalk/%.o)

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

PRINTF_DIR		= printf
PRINTF			= $(PRINTF_DIR)/printf.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.

RM				= rm -f

all:			$(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
				$(MAKE) -C $(PRINTF_DIR) --no-print-directory

objMinitalk/%.o: %.c
				@mkdir -p objMinitalk
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT)

clean:
				$(RM) $(OBJS)
				@rm -rf objMinitalk
				-$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
				-$(MAKE) clean -C $(PRINTF_DIR) --no-print-directory

fclean:			clean
				$(RM) $(NAME)
				-$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
				-$(MAKE) fclean -C $(PRINTF_DIR) --no-print-directory

re:				fclean all

.PHONY: all clean fclean re
