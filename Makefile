CFILES = push_swap.c push_swap_utils.c stack_management.c error.c \
leaks.c check_argv.c algorithm.c stack_check.c execute_moves.c

ORDER_CFILES = push.c reverse_rotate.c rotate.c swap.c

BONUS_CFILES = push_swap_bonus.c push_swap_utils_bonus.c stack_management_bonus.c error_bonus.c \
leaks_bonus.c check_argv_bonus.c algorithm_bonus.c stack_check_bonus.c execute_moves_bonus.c

BONUS_ORDER_CFILES = push_bonus.c reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c

BONUS_OFILES = $(BONUS_CFILES:.c=.o)
BONUS_ORDER_OFILES = $(BONUS_ORDER_CFILES:.c=.o)

CC = clang
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
ORDER_SRC_DIR = src/order_cmd/
OBJ_DIR = objs/

BONUS_SRC_DIR = bonus/
BONUS_ORDER_SRC_DIR = bonus/order_cmd/
BONUS_OBJ_DIR = bonus/objs/

OFILES = $(addprefix $(OBJ_DIR), $(CFILES:.c=.o))
ORDER_OFILES = $(addprefix $(OBJ_DIR)order_cmd/, $(ORDER_CFILES:.c=.o))

BONUS_OFILES = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_CFILES:.c=.o))
BONUS_ORDER_OFILES = $(addprefix $(BONUS_OBJ_DIR)order_cmd/, $(BONUS_ORDER_CFILES:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)order_cmd/%.o: $(ORDER_SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/order_cmd/
	@$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)
$(NAME): $(OFILES) $(ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(OFILES) $(ORDER_OFILES) include/libft/libft.a -o $(NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)order_cmd/%.o: $(BONUS_ORDER_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)/order_cmd/
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: libft $(NAME)_bonus
$(NAME)_bonus: $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(BONUS_OFILES) $(BONUS_ORDER_OFILES) include/libft/libft.a -o $(NAME)_bonus

libft:
	@ make -C  include/libft/ bonus

clean:
	@ rm -f $(OFILES) $(ORDER_OFILES) $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ rm -d $(OBJ_DIR)order_cmd/ $(OBJ_DIR) $(BONUS_OBJ_DIR)order_cmd/ $(BONUS_OBJ_DIR)
	@ make -C include/libft/ clean

fclean: clean
	@ rm -f $(NAME) $(NAME)_bonus
	@ make -C include/libft/ fclean

re: fclean all

py3:	all
		python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
py5:	all
		python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
py10:	all
		python3 pyviz.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
py100:	all
		python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` 
py500:	all
		python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re bonus libft $(LIBFT_LIB_PATH) py3 py5 py10 py100 py500