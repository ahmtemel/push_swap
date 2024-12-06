NAME = push_swap
NAME_C = checker
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
		error_string.c \
		atoi_max.c \
		stack_func.c \
		allocate_mem.c \
		stack_func_ro.c \
		sorting.c \
		calculate_func.c \
		calculate_func_man.c \
		sort_stack.c \
		sort_b.c \
		last_sort_a.c \
		char_stack.c \
		find_max_all.c \

SRCS_C = checker.c \
		 check_string_bonus.c \
		 atoi_max_bonus.c \
		 stack_func_ro_bonus.c \
		 stack_func_bonus.c \
		 command_p_bonus.c \
		 get_command_bonus.c \
		 check_sort_a_bonus.c \


SRCS_GET = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ =$(SRCS:.c=.o)

OBJ_C =$(SRCS_C:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C libft/
	@make -C printf/
	@$(CC) $(C_FLAGS) $(OBJ) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)


%.o: %.c
	@$(CC) $(C_FLAGS) -c $< -o $@

bonus: $(OBJ_C)
	@make -C libft/
	@make -C printf/
	@$(CC) $(C_FLAGS) $(OBJ_C) ./libft/libft.a ./printf/libftprintf.a $(SRCS_GET) -o $(NAME_C)

fclean: clean
	@make fclean -C libft/
	@make fclean -C printf/
	@rm -rf $(NAME)
	@rm -rf $(NAME_C)

clean:
	@make clean -C printf/
	@make clean -C libft/
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_C)

re: fclean all
