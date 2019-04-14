CC=gcc
FLAG=-Wall -Wextra -Werror
LIB_DIR=./libft
LIB=./libft/libft.a
EXEC=ft_printf
SRC=srcs/main.c\
	srcs/ft_printf.c\
	srcs/check.c\
	srcs/handle_int.c\

all:$(EXEC)

$(EXEC) :$(SRC)
		@(cd $(LIB_DIR) && $(MAKE))
		$(CC) $(SRC) $(LIB) -o $(EXEC)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
		@(cd $(LIB_DIR) && $(MAKE) $@)
		rm -rf $(EXEC)

re: fclean all

.PHONY : all, clean, fclean, re
