# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/11/23 01:39:03 by art3mis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################### BASICS #######################

SRC 		= utils.c
OBJ			= $(SRC:.c=.o)

SERVER		= server
CLIENT		= client

INC			= minitalk.h

CFLAGS 		= -Wall -Wextra -Werror
FSANITIZE	= -fsanitize=address -g3


####################### SOURCES #######################

$(SERVER): $(OBJ) $(INC)
			@echo -e -n "$(PINK)[minitalk]:\t$(RESET)"
			@cc $(CFLAGS) server.c $(OBJ) -o $(SERVER)
			@echo -e -n "$(BLUE) server ready! 👌🏼$(RESET)\n"

$(CLIENT): $(OBJ) $(INC)
			@echo -e -n "$(PINK)[minitalk]:\t$(RESET)"
			@cc $(CFLAGS) client.c $(OBJ) -o $(CLIENT)
			@echo -e -n "$(BLUE) client ready! 👌🏼$(RESET)\n"


####################### RULES #######################

.c.o:
			cc $(CFLAGS) -c $^ -o $@

all: 		$(SERVER) $(CLIENT)

clean:
			@rm -rf $(OBJ)
			@echo -e -n "$(PINK)[minitalk]:\tobject files successfully cleaned! $(RESET)🧹\n"

fclean: clean
			@rm -rf $(CLIENT) $(SERVER)
			@find . -name ".DS_Store" -delete
			@echo -e -n "$(PINK)[minitalk]:\texec files successfully cleaned! $(RESET)🧹\n"

re: 	fclean all
			@echo -e -n "$(CYAN)Cleaned and rebuilt everything for$(RESET)$(PINK) [minitalk]$(RESET)! ✨\n"

norm:
			@clear
			@norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm