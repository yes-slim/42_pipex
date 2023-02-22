# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:06:40 by yes-slim          #+#    #+#              #
#    Updated: 2023/02/22 18:09:14 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -c
NAME = pipex
NAME_B = 
DEL = rm -f


SRCS =	$(addsuffix .c, $(addprefix ))\

BSRCS = $(addsuffix .c, $(addprefix )) \

OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ) pipex.c
	@ar -rc pipex.a $(OBJ)
	@cc pipex.c pipex.a -o $(NAME)
	@clear
	@echo "✅\033[0;35m Your \033[0;33mpipex \033[0;35mprogram is created \033[0m"

$(NAME_B) : $(OBJ) $(BOBJ) 
	@echo "✅\033[0;35m Checker program is created\033[0m"

clean :
	@$(DEL) $(OBJ) pipex.a
	@echo "✅ \033[0;32mCleaning done\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(BOBJ) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus