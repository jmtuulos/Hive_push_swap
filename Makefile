# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/04/07 16:54:36 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHK = checker
NAME_SWP = push_swap
FLAGS = -g

INCL = -Iincludes/ -I$(LIB_DIR)/includes

SRCS_CHK =	checker.c\
			ft_atoi_long.c\
			helper.c\
			validation.c\
			stack_manipulation.c\
			stack_shuffle.c\
			commands_ext.c\
			positioning.c\
			get_next_line_mod.c

SRCS_SWP =	solve_stack.c\
			push_to_stack.c\
			solver_helper.c\
			verifying_stack.c\
			over_5_solver.c\
			helper.c\
			commands.c\
			positioning.c\
			pushswap.c\
			validation.c\
			ft_atoi_long.c\
			stack_manipulation.c\
			calculations.c\
			stack_shuffle.c\
			commands_ext.c\

OBJ_NAME_CHK = $(SRCS_CHK:.c=.o)
OBJ_NAME_SWP = $(SRCS_SWP:.c=.o)

OBJ_CHK = $(addprefix $(OBJ_DIR),$(OBJ_NAME_CHK))
OBJ_SWP = $(addprefix $(OBJ_DIR),$(OBJ_NAME_SWP))
SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

all: $(NAME_CHK) $(NAME_SWP)

$(NAME_SWP): $(OBJ_SWP)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME_SWP) $(OBJ_SWP) -L $(LIB_DIR) -lft
	@echo "Compiled PushSwap"

$(NAME_CHK): $(OBJ_CHK)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME_CHK) $(OBJ_CHK) -L $(LIB_DIR) -lft
	@echo "Compiled Checker"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INCL)

clean:
	@rm -f $(OBJ_CHK)
	@rm -f $(OBJ_SWP)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_SWP)
	@echo "Removed executables"

re: fclean all

.PHONY: all clean fclean re
