# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2023/11/09 18:07:57 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= minitalk_utils.c

OBJ	= $(SRC:.c=.o)

CLIENT	= client

SERVER	= server

INC	= minitalk.h

CFLAGS = -Wall -Wextra -Werror


##################### COLORS #####################
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]
###################################################


$(CLIENT): $(OBJ) $(INC)
	cc $(CFLAGS) client.c $(OBJ) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"

$(SERVER): $(OBJ) $(INC)
	cc $(CFLAGS) server.c $(OBJ) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

.c.o:
	cc $(CFLAGS) -c $^ -o $@

all: $(CLIENT) $(SERVER)

norm:
	norminette $(SRC)

clean:
	rm -rf $(OBJ)
	@printf "$(_INFO) client successfully removed.\n"
	@printf "$(_INFO) server successfully removed.\n"

fclean: clean
	rm -rf $(CLIENT)
	@printf "$(_INFO) client successfully removed.\n"
	@rm -rf $(SERVER)
	@printf "$(_INFO) server successfully removed.\n"

re: fclean all

.PHONY: all clean fclean norm re