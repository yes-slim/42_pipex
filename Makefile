# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:06:40 by yes-slim          #+#    #+#              #
#    Updated: 2023/02/23 19:21:27 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = -I includes
CFLAGS = -Wall -Werror -Wextra $(INC) -c
NAME = pipex
NAME_B = 
DEL = rm -f

FT_PRINTF = ft_printf_helpers ft_printf
HELPERS = check_args

SRCS =	$(addsuffix .c, $(addprefix Srcs/ft_printf/, $(FT_PRINTF))) \
		$(addsuffix .c, $(addprefix SRCS/helpers/, $(HELPERS))) \
		$(addsuffix .c, $(addprefix /, $())) \

BSRCS = $(addsuffix .c, $(addprefix /, $())) \
		$(addsuffix .c, $(addprefix /, $())) \

OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ) pipex.c
	@ar -rc pipex.a $(OBJ)
	@cc pipex.c pipex.a $(INC) -o $(NAME)
	@clear
	@echo "✅\033[0;35m Your \033[0;33mpipex \033[0;35mprogram is created \033[0m"

$(NAME_B) : $(OBJ) $(BOBJ)
	@echo "✅\033[0;35m Checker program is created\033[0m"

clean :
	@$(DEL) $(OBJ) pipex.a
	@echo "✅ \033[0;32mCleaning done\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(BOBJ) $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re bonus