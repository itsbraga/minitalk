# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:07:10 by annabrag          #+#    #+#              #
#    Updated: 2023/11/24 19:39:23 by annabrag         ###   ########.fr        #
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

NAME		=	libft.a
INC		=	include/
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
FSANITIZE	=	-fsanitize=address -g3
LIBC		=	ar -rcs
RM		=	rm -rf


############################# SOURCES #############################

FT_FD_DIR	= 	ft_fd/
FT_FD_FILES	= 	ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd

FT_IS_DIR 	= 	ft_is/
FT_IS_FILES	= 	ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint

FT_MEM_DIR	=	ft_mem/
FT_MEM_FILES	=	ft_memset \
			ft_memcpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp
			
FT_STR_DIR	=	ft_str/
FT_STR_FILES	=	ft_strlen \
			ft_bzero \
			ft_strlcpy \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_strnstr \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_strmapi \
			ft_striteri

FT_TO_DIR	=	ft_to/
FT_TO_FILES	=	ft_tolower \
			ft_toupper \
			ft_itoa \
			ft_atoi

FT_LST_DIR	=	ft_lst/
FT_LST_FILES	=	ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap

GNL_DIR		=	get_next_line/
GNL_FILES	=	get_next_line \
			get_next_line_utils

FT_PRINTF_DIR	=	ft_printf/
FT_PRINTF_FILES	=	ft_printf \
			ft_print_unsigned_int \
			ft_printchar \
			ft_printhex \
			ft_printnbr \
			ft_printptr \
			ft_printstr


####################### COMBINE DIRECTORIES AND FILES #######################

SRC_DIR		= src/

SRC_NAMES	= $(addprefix $(FT_FD_DIR), $(addsuffix .c, $(FT_FD_FILES))) \
			$(addprefix $(FT_IS_DIR), $(addsuffix .c, $(FT_IS_FILES))) \
			$(addprefix $(FT_MEM_DIR), $(addsuffix .c, $(FT_MEM_FILES))) \
			$(addprefix $(FT_STR_DIR), $(addsuffix .c, $(FT_STR_FILES))) \
			$(addprefix $(FT_TO_DIR), $(addsuffix .c, $(FT_TO_FILES))) \
			$(addprefix $(FT_LST_DIR), $(addsuffix .c, $(FT_LST_FILES))) \
			$(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES))) \
			$(addprefix $(FT_PRINTF_DIR), $(addsuffix .c, $(FT_PRINTF_FILES)))

OBJ_DIR		= obj/

OBJ_NAMES	= $(SRC_NAMES:.c=.o)

OBJ_FOLDERS	= $(addprefix $(OBJ_DIR), $(FT_FD_DIR) \
                	$(FT_IS_DIR) \
			$(FT_MEM_DIR) \
			$(FT_STR_DIR) \
                        $(FT_TO_DIR) \
			$(FT_LST_DIR) \
                	$(GNL_DIR) \
			$(FT_PRINTF_DIR))


OBJ		= $(addprefix $(OBJ_DIR), $(OBJ_NAMES))


################################### RULES ###################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(ORANGE)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

# link .o files to the library
$(NAME):	$(OBJ)
			@$(LIBC) $(NAME) $(OBJ)
			@printf "\n$(RESET)$(PINK)[LIBFT]$(RESET), $(BLUE)[GET_NEXT_LINE]$(RESET), $(BRIGHT_PURPLE)[FT_PRINTF]$(RESET) successfully compiled!$(RESET)"

all:		$(NAME)

san:		$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@printf "$(PINK)[LIBFT]:\tobject files : cleaned! $(RESET)🐞\n\n"

fclean: 	clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@printf "$(PURPLE)[LIBFT]:\texec files : cleaned! $(RESET)🦋\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC) $(INC)

.PHONY:		all clean fclean re norm
