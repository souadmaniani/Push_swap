CH_NAME = checker
PS_NAME = push_swap


CH_SRC = checker.c list.c list_utils1.c instructions.c get_next_line/get_next_line.c push_swap_utils1.c 

PS_SRC = push_swap.c list.c list_utils1.c list_utils2.c instructions.c get_next_line/get_next_line.c \
			quiq_sort.c push_swap_utils1.c  push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c

all : $(PS_NAME) $(CH_SRC)

$(PS_NAME):$(PS_SRC)
	make -C libft
	gcc  -Wall -Wextra -Werror $(PS_SRC) libft/libft.a  -o $(PS_NAME)

bonus: $(CH_SRC)
	make -C libft
	gcc -Wall -Wextra -Werror $(CH_SRC) libft/libft.a  -o $(CH_NAME) 
	
clean:
	rm -rf checker.dSYM
	rm -rf push_swap.dSYM
	rm -rf libft/*.o

fclean: clean
	rm -f checker
	rm -f push_swap
	rm -f libft/libft.a
re: fclean all

.PHONY: all bonus clean fclean re
