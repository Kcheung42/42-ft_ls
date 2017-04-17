# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcheung <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 11:10:05 by kcheung           #+#    #+#              #
#    Updated: 2017/04/07 18:14:22 by kcheung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGs = -Wall -Wextra -Werror

#Libft Library
LIB_DIR = ./libft/
LIB_INC_DIR = ./libft/includes
LIB = $(LIB_DIR)/libft.a
LIB_LINK = -L $(LIB_DIR) -lft

SRC_DIR = ./srcs/
SRC_NAME =	main.c \
			parse_dir.c \
			parse_flg.c \
			sort_rules.c \
			sort_directions.c \
			sort_directions2.c \
			sort_helpers.c \
			sortdir.c \
			setup_content.c \
			handle_recursion.c \
			set_flags.c \
			handle_inputs.c

SRC_DIR_PRINT = $(SRC_DIR)print/
SRC_NAME_PRINT = 	print.c \
					print2.c \
					print3.c \
					print_helpers.c \
					print_helpers2.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
SRCS += $(addprefix $(SRC_DIR_PRINT), $(SRC_NAME_PRINT))

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_NAME:%.c=%.o))
OBJS += $(addprefix $(OBJ_DIR), $(SRC_NAME_PRINT:%.c=%.o))

INC_DIR = ./includes/
INC = -I$(LIB_INC_DIR) -I$(INC_DIR)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: obj $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)%.o: $(SRC_DIR_PRINT)%.c $(INC_DIR)*.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)
	@chmod 755 $@

$(LIB):
	@make -C $(LIB_DIR)

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo "Cleaning" [$(NAME)] "..." $(OK)
	@echo "Cleaning" [$(NAME_C)] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_C)
	@make -C $(LIB_DIR) fclean
	@echo "Delete" [$(NAME)] "..." $(OK)
	@echo "Delete" [$(NAME_C)] "..." $(OK)
re: fclean all

.PHONY: all, clean, fclean, re
