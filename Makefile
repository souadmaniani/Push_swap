CH_NAME = checker
PS_NAME = push_swap


CH_SRC = checker.c list.c list_utils1.c instructions.c get_next_line/get_next_line.c push_swap_utils.c 

PS_SRC = push_swap.c list.c list_utils1.c list_utils2.c instructions.c get_next_line/get_next_line.c \
			push_swap_utils.c quiq_sort.c push_swap_utils2.c

all : $(CH_NAME) $(PS_NAME)

$(CH_NAME):$(CH_SRC)
	@make -C libft
	@gcc $(CH_SRC) libft/libft.a -g -o $(CH_NAME) -fsanitize=address

$(PS_NAME):$(PS_SRC)
	@gcc  $(PS_SRC) libft/libft.a -g -o $(PS_NAME) -fsanitize=address
	
clean:
	@rm -rf checker.dSYM
	@rm -rf push_swap.dSYM

fclean: clean
	@rm -f checker
	@rm -f push_swap

re: fclean all
