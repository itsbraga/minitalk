# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:07:10 by annabrag          #+#    #+#              #
#    Updated: 2023/12/13 20:44:16 by annabrag         ###   ########.fr        #
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
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/
FSANITIZE	=	-fsanitize=address -g3
LIBC		=	ar -rcs
RM		=	rm -rf


############################# SOURCES #############################

FT_FD_DIR	= 	ft_fd/
FT_FD_FILES	= 	ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putstr_color_fd.c

FT_IS_DIR 	= 	ft_is/
FT_IS_FILES	= 	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c

FT_MEM_DIR	=	ft_mem/
FT_MEM_FILES	=	ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c
			
FT_STR_DIR	=	ft_str/
FT_STR_FILES	=	ft_strlen.c \
			ft_bzero.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strisnum.c

FT_TO_DIR	=	ft_to/
FT_TO_FILES	=	ft_tolower.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_atoi.c

FT_LST_DIR	=	ft_lst/
FT_LST_FILES	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

GNL_DIR		=	get_next_line/
GNL_FILES	=	get_next_line.c \
			get_next_line_utils.c

FT_PRINTF_DIR	=	ft_printf/
FT_PRINTF_FILES	=	ft_printf.c \
			ft_print_unsigned_int.c \
			ft_printchar.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printptr.c \
			ft_printstr.c


####################### COMBINE DIRECTORIES AND FILES #######################

SRC_DIR		= src/

SRC_NAMES	= $(addprefix $(FT_FD_DIR), $(FT_FD_FILES)) \
			$(addprefix $(FT_IS_DIR), $(FT_IS_FILES)) \
			$(addprefix $(FT_MEM_DIR), $(FT_MEM_FILES)) \
			$(addprefix $(FT_STR_DIR), $(FT_STR_FILES)) \
			$(addprefix $(FT_TO_DIR), $(FT_TO_FILES)) \
			$(addprefix $(FT_LST_DIR), $(FT_LST_FILES)) \
			$(addprefix $(GNL_DIR), $(GNL_FILES)) \
			$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

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
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# link .o files to the library
$(NAME):	$(OBJ)
			@$(LIBC) $(NAME) $(OBJ)
			@printf "\n$(RESET)$(PINK)[LIBFT]$(RESET), $(BLUE)[GET_NEXT_LINE]$(RESET), $(BRIGHT_PURPLE)[FT_PRINTF]$(RESET) successfully compiled!$(RESET)"

all:		$(NAME)

san:		$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@printf "$(PINK)[LIBFT]: object files $(RESET)$(BOLD)\t=> cleaned! $(RESET)🐞\n\n"

fclean: 	clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@printf "$(PURPLE)[LIBFT]: exec. files $(RESET)$(BOLD)\t=> cleaned! $(RESET)🦋\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
