NAME = printf.a

SRCS = ft_printf.c print_char.c print_digit.c print_str.c print_pointer.c print_hex.c

OBJS = $(addprefix objPrintf/, $(SRCS:.c=.o))

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


objPrintf/%.o: %.c
	@mkdir -p objPrintf
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)
	$(RM) -rf objPrintf


fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
