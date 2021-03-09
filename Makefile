# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/08 22:42:10 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libraries/libft/
SRC = ./source/
PRINT = ./source/parsing_identifiers/

FILES = $(SRC)ft_printf.c $(SRC)flags_parser.c $(PRINT)print_char.c $(PRINT)print_string.c $(PRINT)print_pointer.c $(PRINT)print_integer.c $(LIBFT)ft_strdup.c $(LIBFT)ft_strchr.c $(LIBFT)ft_strjoin.c $(LIBFT)ft_substr.c $(LIBFT)ft_itoa.c $(LIBFT)ft_putstr_bonus.c $(LIBFT)ft_strlen.c $(LIBFT)ft_putchar_bonus.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_atoi.c $(LIBFT)ft_isalpha.c $(LIBFT)ft_putnbr_bonus.c $(LIBFT)ft_memset.c $(LIBFT)ft_numlen.c $(LIBFT)ft_countdigit_bonus.c
OBJECTS = $(FILES:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)
	
$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

test:
	@echo making test........
	@$(CC) $(CFLAGS) -fsanitize=leak $(FILES) && ./a.out

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
