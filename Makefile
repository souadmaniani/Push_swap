NAME = checker

SRC = checker.c list.c
	
all : $(NAME)

$(NAME):$(SRC)
	make -C libft
	gcc  $(SRC) libft/libft.a -g -o checker
clean:
	rm -rf checker
fclean:
	rm -rf checker
re: fclean all