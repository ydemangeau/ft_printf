CC=clang 
AR=ar rc
FLAG= -Wall -Wextra -Werror
LIB_DIR=../
LIB=../libft.a
EXEC=ft_printf
SRC=srcs/ft_printf.c\
	srcs/check.c\
	srcs/main.c\
	srcs/handle_int.c\
	srcs/handle_uint.c\
	srcs/handle_octal.c\
	srcs/handle_hexa.c\
	srcs/handle_string.c\
	srcs/handle_char.c\
	srcs/handle_ptr.c\
	srcs/handle_float.c\
	srcs/utils.c\

OBJECTS=$(SRC:.c=.o)

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
