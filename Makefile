CH_NAME = checker
PS_NAME = push_swap


CH_SRC = checker.c srcs/list.c srcs/list_utils1.c srcs/instructions.c srcs/get_next_line/get_next_line.c push_swap_utils.c 

PS_SRC = push_swap.c srcs/list.c srcs/list_utils1.c srcs/list_utils2.c srcs/instructions.c srcs/get_next_line/get_next_line.c push_swap_utils.c quiq_sort.c

all : $(CH_NAME) $(PS_NAME)

$(CH_NAME):$(CH_SRC)
	@make -C srcs/libft
	@gcc $(CH_SRC) srcs/libft/libft.a -g -o $(CH_NAME)

$(PS_NAME):$(PS_SRC)
	@gcc $(PS_SRC) srcs/libft/libft.a -g -o $(PS_NAME)
	
clean:
	@rm -rf checker.dSYM
	@rm -rf push_swap.dSYM

fclean: clean
	@rm -f checker
	@rm -f push_swap

re: fclean all