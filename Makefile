# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/06 10:03:05 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libraries/libft/
SRC = ./source/

FILES = $(SRC)ft_printf.c, $(LIBFT)ft_strdup.c, $(LIBFT)ft_strchr.c, $(LIBFT)ft_strjoin.c, $(LIBFT)ft_substr.c, $(LIBFT)ft_itoa.c, $(LIBFT)ft_putstr_bonus.c, $(LIBFT)ft_strlen.c, $(LIBFT)ft_putchar_bonus.c

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
	$(CC) $(CFLAGS) $(FILES) && ./a.out

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
