# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/10 22:51:51 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libraries/libft/
SRC = ./source/
PRINT = ./source/parsing_identifiers/print_

FILES = $(SRC)ft_printf.c $(SRC)flags_parser.c $(PRINT)char.c $(PRINT)string.c $(PRINT)pointer.c $(PRINT)integer.c $(PRINT)unsigned_int.c $(LIBFT)ft_strdup.c $(LIBFT)ft_strchr.c $(LIBFT)ft_strjoin.c $(LIBFT)ft_substr.c $(LIBFT)ft_itoa.c $(LIBFT)ft_putstr_bonus.c $(LIBFT)ft_strlen.c $(LIBFT)ft_putchar_bonus.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_atoi.c $(LIBFT)ft_isalpha.c $(LIBFT)ft_putnbr_bonus.c $(LIBFT)ft_memset.c $(LIBFT)ft_numlen.c $(LIBFT)ft_countdigit_bonus.c
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
	@echo -----------------------------------
	@echo making test........			
	@echo cross your fingers, girl!	
	@echo -----------------------------------
	@$(CC) $(CFLAGS) -fsanitize=leak $(FILES) && ./a.out

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
