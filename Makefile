# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/11/20 18:58:46 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= utils.c

OBJ		= $(SRC:.c=.o)

SERVER		= server

CLIENT		= client

INC		= minitalk.h

CFLAGS 		= -Wall -Wextra -Werror

FSANITIZE	= -fsanitize=address -g3


##################### COLORS #####################
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED		=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
PINK		=	\033[38;2;255;182;193m
WHITE		=	\033[0;97m
###################################################


$(SERVER): $(OBJ) $(INC)
		@echo -en "$(PINK)[minitalk]:\t$(DEF_COLOR)"
		cc $(CFLAGS) server.c $(OBJ) -o $(SERVER)
		@echo -en "$(BLUE) server ready! 👌🏼$(DEF_COLOR)\n"

$(CLIENT): $(OBJ) $(INC)
		@echo -en "$(PINK)[minitalk]:\t$(DEF_COLOR)"
		cc $(CFLAGS) client.c $(OBJ) -o $(CLIENT)
		@echo -en "$(BLUE) client ready! 👌🏼$(DEF_COLOR)\n"


.c.o:
		cc $(CFLAGS) -c $^ -o $@

all: 		$(SERVER) $(CLIENT)

norm:
		@clear
		norminette $(SRC)

clean:
		rm -rf $(OBJ)
		@echo -en "$(PINK)[minitalk]:\tobject files$(DEF_COLOR)$(CYAN) successfully cleaned! $(DEF_COLOR)🧹\n"

fclean: clean
		rm -rf $(CLIENT) $(SERVER)
		@find . -name ".DS_Store" -delete
		@echo -en "$(PINK)[minitalk]:\texec files$(DEF_COLOR)$(CYAN) successfully cleaned! $(DEF_COLOR)🧹\n"

re: 	fclean all
		@echo -en "$(CYAN)Cleaned and rebuilt everything for$(DEF_COLOR)$(PINK)[minitalk]$(DEF_COLOR)! ✨\n"

.PHONY:	all clean fclean re norm