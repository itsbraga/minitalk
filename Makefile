# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/11/27 18:00:45 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## COLORS ##############################

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


############################## BASICS ##############################

SERVER		=	server
CLIENT		=	client
LIBFT		=	libft
INC		=	-I include/
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
FSANITIZE	=	-fsanitize=address -g3
RM		=	rm -rf


############################## SOURCES ##############################

SRC_DIR		=	src/
CLIENT_FILE	=	client
SRV_FILE	=	server
OBJ_DIR		=	obj/


################### COMBINE DIRECTORIES AND FILES ###################

SRC_CL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_FILE)))
OBJ_CL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILE)))

SRC_SRV		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRV_FILE)))
OBJ_SRV		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRV_FILE)))


############################### RULES ##############################

$(SERVER):	$(OBJ_SRV)
			@printf "$(BLUE)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(OBJ_SRV) $(INC) libft.a -o $(SERVER)
			@printf "$(BRIGHT_CYAN) server ready! $(RESET)👌🏼\n\n"

$(CLIENT):	$(OBJ_CLIENT)
			@printf "$(BLUE)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(INC) libft.a -o $(CLIENT)
			@printf "$(BRIGHT_CYAN) client ready! $(RESET)👌🏼\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
		@make -C $(LIBFT)
		@cp $(LIBFT)/libft.a .
		@make all

all: 		$(SERVER) $(CLIENT)

san:		$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@$(RM) $(LIBFT)/obj/
			@printf "$(BRIGHT_GREEN)[minitalk]: object files $(RESET)$(BOLD)\t=> successfully cleaned! $(RESET)😸\n\n"

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(PURPLE)[LIBFT]: exec. files $(RESET)$(BOLD)\t\t=> successfully cleaned! $(RESET)🦋\n\n"
			@printf "$(BLUE)[minitalk]: exec. files $(RESET)$(BOLD)\t=> successfully cleaned! $(RESET)🥸\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC) $(INC) $(LIBFT)

.PHONY:		all clean fclean re norm