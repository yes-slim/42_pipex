# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:06:40 by yes-slim          #+#    #+#              #
#    Updated: 2023/05/20 13:47:39 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -I includes -c
NAME = pipex
NAME_B = pipex_bonus
DEL = rm -f

FT_PRINTF = ft_printf_helpers ft_printf
HELPERS = ft_get_path check_files ft_error ft_helpers childs
LIBFT = ft_split functions ft_strdup ft_strncmp
GNL = get_next_line get_next_line_utils
SRCS =	$(addsuffix .c, $(addprefix Srcs/ft_printf/, $(FT_PRINTF))) \
		$(addsuffix .c, $(addprefix SRCS/helpers/, $(HELPERS))) \
		$(addsuffix .c, $(addprefix SRCS/libft/, $(LIBFT))) \
		$(addsuffix .c, $(addprefix SRCS/GNL/, $(GNL))) \
		$(addsuffix .c, $(addprefix /, $())) \

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@cc $(CFLAGS) $< -o $@

all : $(NAME)

bonus : $(NAME_B)


$(NAME) : $(OBJ) pipex.c
	@ar -rc pipex.a $(OBJ)
	@cc pipex.c pipex.a -I includes -o $(NAME)
	@echo "\033[0;35m Your \033[0;33mpipex \033[0;35mprogram is created \033[0m"

$(NAME_B) : $(OBJ)
	@ar -rc pipex.a $(OBJ)
	@cc pipex_bonus.c pipex.a -I includes -o $(NAME_B)
	@echo "\033[0;35m Your \033[0;33mpipex_bonus \033[0;35mprogram is created \033[0m"

clean :
	@$(DEL) $(OBJ) pipex.a
	@echo "\033[0;32mCleaning\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(NAME) $(NAME_B)

re : fclean all
rebonus : fclean bonus

.PHONY : all clean fclean r-I includess