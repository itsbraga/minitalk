# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/12/11 22:18:14 by art3mis          ###   ########.fr        #
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
BONUS_CL	=	client_bonus
BONUS_SRV	=	server_bonus
LIBFT		=	libft
INC		=	-I include/
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
FSANITIZE	=	-fsanitize=address -g3
RM		=	rm -rf


############################## SOURCES ##############################

CLIENT_FILE		=	client
SRV_FILE		=	server
B_CLIENT_FILE	=	client_bonus
B_SRV_FILE		=	server_bonus


################### COMBINE DIRECTORIES AND FILES ###################

SRC_DIR		=	src/

SRC_CL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_FILE)))
SRC_SRV		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRV_FILE)))
SRC_B_CL	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(B_CLIENT_FILE)))
SRC_B_SRV	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(B_SRV_FILE)))


OBJ_DIR		=	obj/

OBJ_CL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILE)))
OBJ_SRV		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRV_FILE)))
OBJ_B_CL	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_CLIENT_FILE)))
OBJ_B_SRV	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRV_FILE)))


############################### RULES ##############################

build:
		@make -C $(LIBFT)
		@cp $(LIBFT)/libft.a .
		@make all

all: 		$(SERVER) $(CLIENT)

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

bonus:
		@make -C $(LIBFT)
		@cp $(LIBFT)/libft.a .
		@make allbonus

allbonus:	$(BONUS_SRV) $(BONUS_CL)

$(BONUS_SRV):	$(OBJ_B_SRV)
				@printf "$(BLUE)[minitalk - BONUS]:\t$(RESET)"
				@$(CC) $(CFLAGS) $(OBJ_B_SRV) $(INC) libft.a -o $(BONUS_SRV)
				@printf "$(BRIGHT_CYAN) server ready to run the bonuses! $(RESET)👌🏼\n\n"

$(BONUS_CL):	$(OBJ_B_CL)
				@printf "$(BLUE)[minitalk - BONUS]:\t$(RESET)"
				@$(CC) $(CFLAGS) $(OBJ_B_CL) $(INC) libft.a -o $(BONUS_CL)
				@printf "$(BRIGHT_CYAN) client ready to run the bonuses! $(RESET)👌🏼\n"

san:		$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@printf "$(BRIGHT_GREEN)[minitalk]: object files $(RESET)$(BOLD)\t=> successfully cleaned! $(RESET)😸\n\n"

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER) $(BONUS_CL) $(BONUS_SRV)
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

.PHONY:		all clean fclean re bonus norm