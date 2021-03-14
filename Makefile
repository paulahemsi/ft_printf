# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/14 10:27:26 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libraries/libft/
SRC = ./source/
PRINT = ./source/parsing_identifiers/print_

FILES = $(SRC)ft_printf.c $(SRC)flags_parser.c $(PRINT)char.c $(PRINT)string.c $(PRINT)integer.c $(PRINT)hex.c $(LIBFT)ft_strdup.c $(LIBFT)ft_strchr.c $(LIBFT)ft_strjoin.c $(LIBFT)ft_substr.c $(LIBFT)ft_itoa.c $(LIBFT)ft_putstr.c $(LIBFT)ft_strlen.c $(LIBFT)ft_putchar.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_atoi.c $(LIBFT)ft_isalpha.c $(LIBFT)ft_putnbr.c $(LIBFT)ft_memset.c $(LIBFT)ft_numlen.c $(LIBFT)ft_countdigit.c $(LIBFT)ft_itoa_hex.c $(LIBFT)ft_putnbr_unsigned.c
OBJECTS = ft_printf.o flags_parser.o print_char.o print_string.o print_integer.o print_hex.o ft_strdup.o ft_strchr.o ft_strjoin.o ft_substr.o ft_itoa.o ft_putstr.o ft_strlen.o ft_putchar.o ft_isdigit.o ft_atoi.o ft_isalpha.o ft_putnbr.o ft_memset.o ft_numlen.o ft_countdigit.o ft_itoa_hex.o ft_putnbr_unsigned.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo making library....
	@ar -rcs $(NAME) $(OBJECTS)
	@echo done!
		
$(OBJECTS): $(FILES)
	@echo making objects....
	@$(CC) $(FLAGS) -c $(FILES)
	@echo done!
	
test:
	@echo -----------------------------------
	@echo making test........			
	@echo cross your fingers, girl!	
	@echo -----------------------------------
	@$(CC) $(FLAGS) -fsanitize=leak $(FILES) ./tests/test.c && ./a.out

flags:
	@echo understanding printf flags
	@$(CC) $(CFLAGS) ./tests/understanding_printf_flags.c && ./a.out

clean:
	$(RM) $(OBJECTS)

fclean: clean
	@echo cleaning!
	$(RM) $(NAME)
	@echo done!
	
re: fclean all 

.PHONY: all clean fclean re 
