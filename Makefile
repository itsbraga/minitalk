# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2024/03/06 00:45:58 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################################################
#																				#
#				      				COLORS										#
#																				#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED			:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE		:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN		:=	\e[96m


#################################################################################
#																				#
#				    				BASICS										#
#																				#
#################################################################################

SERVER		=	server
CLIENT		=	client

BONUS_CL	=	client_bonus
BONUS_SRV	=	server_bonus

LIBFT_PATH	=	libft

CC			=	cc

MAKEFLAGS	+=	--no-print-directory
DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror -I
INC			=	include/

FSANITIZE	=	-fsanitize=address -g3
RM			=	rm -rf


#################################################################################
#																				#
#				    				SOURCES										#
#																				#
#################################################################################

CLIENT_FILE		=	client
SRV_FILE		=	server

B_CLIENT_FILE	=	client_bonus
B_SRV_FILE		=	server_bonus


#################################################################################
#																				#
#								COMBINE FILES									#
#				    				and											#
#								DIRECTORIES										#
#									  											#
#################################################################################

SRC_DIR		=	src/

SRC_CL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_FILE)))
SRC_SRV		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRV_FILE)))
SRCS		=	$(SRC_CL) $(SRC_SRV)

SRC_B_CL	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(B_CLIENT_FILE)))
SRC_B_SRV	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(B_SRV_FILE)))
B_SRCS		=	$(SRC_B_CL) $(SRC_B_SRV)


OBJ_DIR		=	obj/

OBJ_CL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILE)))
OBJ_SRV		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRV_FILE)))

OBJ_B_CL	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_CLIENT_FILE)))
OBJ_B_SRV	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRV_FILE)))


#################################################################################
#																				#
#								DEPENDENCIES									#
#																				#
#################################################################################

DEP_NAMES	=	$(SRCS:.c=.d)

DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


#################################################################################
#																				#
#				     				RULES										#
#																				#
#################################################################################

build:
			@make $(MAKEFLAGS) -sC $(LIBFT_PATH)
			@cp $(LIBFT_PATH)/libft.a .
			@make all

$(SERVER): $(OBJ_SRV)
			@printf "$(RESET)$(BOLD)$(CYAN)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ_SRV) libft.a -o $(SERVER)
			@printf "$(PINK) ./SERVER ready to launch! $(RESET)🦝\n\n"

$(CLIENT): $(OBJ_CL)
			@printf "$(RESET)$(BOLD)$(CYAN)[minitalk]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ_CL) libft.a -o $(CLIENT)
			@printf "$(PINK) ./CLIENT ready to launch! $(RESET)🦙\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(ITAL)$(YELLOW)Compiling: $(RESET)$(ITAL)$<\n"
				@$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@
-include $(DEPS)

all:	$(SERVER) $(CLIENT)

san:	$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_PATH)
			@printf "$(RESET)$(BOLD)$(CYAN)[minitalk]: $(RESET)$(CYAN)object files $(RESET)\t=> CLEANED! 😸\n\n"

fclean: clean
			@$(RM) $(SERVER) $(CLIENT) $(BONUS_SRV) $(BONUS_CL)
			@$(RM) $(LIBFT_PATH)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PURPLE)[LIBFT]: $(RESET)$(PURPLE)exec. files $(RESET)\t\t=> CLEANED! 🦋\n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[minitalk]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! 🌸\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


#################################################################################
#																				#
#				     				BONUS										#
#																				#
#################################################################################

$(BONUS_SRV): $(OBJ_B_SRV)
				@printf "$(RESET)$(BOLD)$(CYAN)[minitalk_bonus]:\t$(RESET)"
				@$(CC) $(CFLAGS) $(INC) $(OBJ_B_SRV) libft.a -o $(BONUS_SRV)
				@printf "$(PINK) ./SERVER_BONUS ready to launch! $(RESET)🌚\n\n"

$(BONUS_CL): $(OBJ_B_CL)
				@printf "$(RESET)$(BOLD)$(CYAN)[minitalk_bonus]:\t$(RESET)"
				@$(CC) $(CFLAGS) $(INC) $(OBJ_B_CL) libft.a -o $(BONUS_CL)
				@printf "$(PINK) ./CLIENT_BONUS ready to launch! $(RESET)🌝\n\n"

bonus:
		@make $(MAKEFLAGS) -sC $(LIBFT_PATH)
		@cp $(LIBFT_PATH)/libft.a .
		@make allbonus

allbonus:	$(BONUS_SRV) $(BONUS_CL)


.PHONY:		build all clean fclean re bonus norm