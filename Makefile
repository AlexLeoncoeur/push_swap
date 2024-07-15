CFILES = push_swap.c push_swap_utils.c stack_management.c error.c leaks.c \
check_argv.c algorithm.c stack_check.c execute_moves.c ./order_cmd/push.c \
./order_cmd/reverse_rotate.c ./order_cmd/rotate.c ./order_cmd/swap.c

BONUS_CFILES = 

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

CC = clang
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

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

py3:	re
		python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
py5:	re
		python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
py10:	re
		python3 pyviz.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
py100:	re
		python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
py500:	re
		python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re bonus libft $(LIBFT_LIB_PATH) py3 py5 py10 py100 py500