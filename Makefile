# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:06:40 by yes-slim          #+#    #+#              #
#    Updated: 2023/06/17 20:39:06 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================variables=========================#
CFLAGS = -Wall -Werror -Wextra -I includes -c
NAME = pipex
NAME_B = pipex_bonus
DEL = rm -f
#=================files=============================#
FT_PRINTF = ft_printf_helpers ft_printf
HELPERS = ft_get_path check_files ft_error childs bonus_childs
LIBFT = ft_split functions ft_strdup ft_strncmp
GNL = get_next_line get_next_line_utils
SRCS =	$(addsuffix .c, $(addprefix Srcs/ft_printf/, $(FT_PRINTF))) \
		$(addsuffix .c, $(addprefix SRCS/helpers/, $(HELPERS))) \
		$(addsuffix .c, $(addprefix SRCS/libft/, $(LIBFT))) \
		$(addsuffix .c, $(addprefix SRCS/GNL/, $(GNL)))
OBJ = $(SRCS:.c=.o)
#=================compile===========================#
%.o : %.c
	@echo $(grey)$(italic)"	~Compiling $<"$(reset)
	@cc $(CFLAGS) $< -o $@
#=================rules=============================#
all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ) pipex.c
	@ar -rc pipex.a $(OBJ)
	@cc pipex.c pipex.a -I includes -o $(NAME)
	@echo $(cyan)$(underline)"pipex is ready to run" $(reset)

$(NAME_B) : $(OBJ) pipex_bonus.c
	@ar -rc pipex.a $(OBJ)
	@cc pipex_bonus.c pipex.a -I includes -o $(NAME_B)
	@echo $(cyan)$(underline)"pipex is ready to run" $(reset)

clean :
	@$(DEL) $(OBJ) philo.a
	@echo $(green)$(italic)$(bold)"	~Deleting files..."$(reset)

fclean : clean
	@$(DEL) $(NAME) $(NAME_B) pipex.a
	@echo $(green)$(italic)$(bold)"	~Deleting pipex..."$(reset)

re : fclean all

.PHONY : all clean fclean re bonus
#================colors=============================#
black = "\033[0;30m"
red = "\033[0;31m"
green = "\033[0;32m"
yellow = "\033[0;33m"
blue = "\033[0;34m"
purple = "\033[0;35m"
cyan = "\033[0;36m"
grey = "\033[0;90m"
#================font===============================#
bold = "\033[1m"
italic= "\033[3m"
underline = "\033[4m"
inverse = "\033[7m"
#===================================================#
reset = "\033[0m"
#===================================================#