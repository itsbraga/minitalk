# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/11/24 19:50:53 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################# COLORS #############################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
LIGHT_GRAY	:=	\e[37m
BRIGHT_RED	:=	\e[91m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


############################# BASICS #############################

SRC 		=	utils.c
OBJ		=	$(SRC:.c=.o)

SERVER		=	server
CLIENT		=	client

INC		=	minitalk.h

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
FSANITIZE	=	-fsanitize=address -g3


############################# SOURCES #############################

$(SERVER):	$(OBJ) $(INC)
			@printf "$(PINK)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) server.c $(OBJ) -o $(SERVER)
			@printf "$(BLUE) server ready! 👌🏼$(RESET)\n"

$(CLIENT):	$(OBJ) $(INC)
			@printf "$(PINK)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) client.c $(OBJ) -o $(CLIENT)
			@printf "$(BLUE) client ready! 👌🏼$(RESET)\n"


############################## RULES ###############################

.c.o:
		$(CC) $(CFLAGS) -c $^ -o $@

all: 		$(SERVER) $(CLIENT)

san:		$(FSANITIZE)

clean:
			@rm -rf $(OBJ)
			@printf "$(PINK)[minitalk]:\tobject files : cleaned! $(RESET)🐞\n\n"

fclean:		clean
			@rm -rf $(CLIENT) $(SERVER)
			@find . -name ".DS_Store" -delete
			@printf "$(PURPLE)[minitalk]:\texec files : cleaned! $(RESET)🦋\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC) $(INC)

.PHONY:		all clean fclean re norm