# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 19:52:46 by phemsi-a          #+#    #+#              #
#    Updated: 2021/02/15 16:23:53 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS = $(FILES:.c=.o)
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_putchar_bonus.c ft_putstr_bonus.c ft_putendl_bonus.c ft_putnbr_bonus.c ft_strequ_bonus.c ft_strnequ_bonus.c ft_strclr_bonus.c ft_isspace_bonus.c ft_isblank_bonus.c ft_isxdigit_bonus.c ft_countdigit_bonus.c ft_isnegative_bonus.c
BONUS_OBJECTS = $(BONUS:.c=.o)
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)
	
$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

bonus: $(BONUS_OBJECTS)
	ar -rcs $(NAME) $(BONUS_OBJECTS)

$(BONUS_OBJECTS): $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
