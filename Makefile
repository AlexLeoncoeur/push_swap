#---------- BASE ----------#

# FILES 
CFILES = push_swap.c push_swap_utils.c stack_management.c error.c \
leaks.c check_argv.c algorithm.c stack_check.c execute_moves.c

ORDER_CFILES = push.c reverse_rotate.c rotate.c swap.c

# DIRECTORIES 
SRC_DIR = src/
ORDER_SRC_DIR = src/order_cmd/
OBJ_DIR = objs/

# OBJECTS
OFILES = $(addprefix $(OBJ_DIR), $(CFILES:.c=.o))
ORDER_OFILES = $(addprefix $(OBJ_DIR)order_cmd/, $(ORDER_CFILES:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)order_cmd/%.o: $(ORDER_SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/order_cmd/
	$(CC) $(CFLAGS) -c $< -o $@

#---------- BONUS ----------#

# FILES 
BONUS_CFILES = checker_bonus.c push_swap_utils_bonus.c error_bonus.c \
leaks_bonus.c check_argv_bonus.c stack_check_bonus.c stack_management_bonus.c

BONUS_ORDER_CFILES = push_bonus.c reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c

# DIRECTORIES
BONUS_SRC_DIR = bonus/
BONUS_ORDER_SRC_DIR = bonus/order_cmd/
BONUS_OBJ_DIR = bonus/objs/

# OBJECTS
BONUS_OFILES = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_CFILES:.c=.o))
BONUS_ORDER_OFILES = $(addprefix $(BONUS_OBJ_DIR)order_cmd/, $(BONUS_ORDER_CFILES:.c=.o))

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)order_cmd/%.o: $(BONUS_ORDER_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)/order_cmd/
	$(CC) $(CFLAGS) -c $< -o $@


#---------- FLAGS & COMPILATION ----------#

CC = clang
NAME = push_swap
BONUS_NAME = checker_bonus
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

all: libft $(NAME)
$(NAME): $(OFILES) $(ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(OFILES) $(ORDER_OFILES) include/libft/libft.a -o $(NAME)

bonus: all $(BONUS_NAME)
$(BONUS_NAME): $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(BONUS_OFILES) $(BONUS_ORDER_OFILES) include/libft/libft.a -o $(BONUS_NAME)

#---------- LIBFT & CLEAN ----------#

libft:
	@ make -C  include/libft/ bonus

clean:
	@ rm -f $(OFILES) $(ORDER_OFILES) $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ rm -rf $(OBJ_DIR)order_cmd/ $(OBJ_DIR) $(BONUS_OBJ_DIR)order_cmd/ $(BONUS_OBJ_DIR)
	@ make -C include/libft/ clean

fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)
	@ make -C include/libft/ fclean

re: fclean all

#---------- PYTHON VISUALIZER ----------#

py3:	all
		python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
py5:	all
		python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
py10:	all
		python3 pyviz.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
py100:	all
		python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` 

.PHONY: all clean fclean re bonus libft $(LIBFT_LIB_PATH) py3 py5 py10 py100 py500

#! BROKEN IN LINUX !
py500:	all 
		python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
