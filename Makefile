CFILES = push_swap.c order_cmd.c push_swap_utils.c stack_management.c

BONUS_CFILES = 

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

CC = clang
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)
$(NAME): $(OFILES)
	@ $(CC) $(CFLAGS) $(OFILES) libft/libft.a -o $(NAME)

bonus: libft $(NAME)_bonus
$(NAME)_bonus: $(BONUS_OFILES)
	@ $(CC) $(CFLAGS) $(BONUS_OFILES) libft/libft.a -o $(NAME)_bonus

libft:
	@ make -C libft/ bonus

clean:
	@ rm -f $(OFILES) $(BONUS_OFILES)
	@ make -C libft/ clean

fclean: clean
	@ rm -f $(NAME) $(NAME)_bonus
	@ make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus libft