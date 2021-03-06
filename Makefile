# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/03/05 21:20:48 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_ft_printf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c
OBJECTS = $(FILES:.c=.o)
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)
	
$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
