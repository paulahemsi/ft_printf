# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/16 08:56:32 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

SRC = ./source/
PRINT = ./source/parsing_identifiers/print_
LIBFT_PATH = ./libraries/libft/

FILES = $(SRC)ft_printf.c $(SRC)flags_parser.c $(PRINT)char.c $(PRINT)string.c $(PRINT)integer.c $(PRINT)hex.c
OBJECTS = ft_printf.o flags_parser.o print_char.o print_string.o print_integer.o print_hex.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_PATH)
	@echo making library....
	@make -C $(LIBFT_PATH) $(LIBFT)
	@cp $(LIBFT_PATH)$(LIBFT) .
	@mv $(LIBFT) $(NAME)
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
	@$(CC) $(FLAGS) $(LIBFT_PATH)ft_strdup.c $(LIBFT_PATH)ft_strchr.c $(LIBFT_PATH)ft_strjoin.c $(LIBFT_PATH)ft_substr.c $(LIBFT_PATH)ft_itoa.c $(LIBFT_PATH)ft_putstr.c $(LIBFT_PATH)ft_strlen.c $(LIBFT_PATH)ft_putchar.c $(LIBFT_PATH)ft_isdigit.c $(LIBFT_PATH)ft_atoi.c $(LIBFT_PATH)ft_isalpha.c $(LIBFT_PATH)ft_putnbr.c $(LIBFT_PATH)ft_memset.c $(LIBFT_PATH)ft_numlen.c $(LIBFT_PATH)ft_countdigit.c $(LIBFT_PATH)ft_itoa_hex.c $(LIBFT_PATH)ft_putnbr_unsigned.c -fsanitize=leak $(FILES) ./tests/test.c && ./a.out

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
