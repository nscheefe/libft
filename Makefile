NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ./libft/ft_toupper.c ./libft/ft_strlen.c ./libft/ft_isalnum.c ./libft/ft_isascii.c ./libft/ft_isprint.c \
        ./libft/ft_isdigit.c ./libft/ft_isalpha.c ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_tolower.c \
        ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_memchr.c \
        ./libft/ft_memcpy.c ./libft/ft_memcmp.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_atoi.c \
        ./libft/ft_calloc.c ./libft/ft_strdup.c ./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c \
		./libft/ft_split.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c \
		./libft/ft_putnbr_fd.c ./libft/ft_itoa.c ./libft/ft_striteri.c ./libft/ft_strmapi.c ./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_util.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line_bonus.c ./get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS) ./libft/libft.h ./get_next_line/get_next_line.h ./get_next_line/get_next_line_bonus.h ./ft_printf/ft_printf.h

clean:
	rm -rf $(OBJS)
fclean: clean
	@rm -f ./libft/$(NAME) ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
