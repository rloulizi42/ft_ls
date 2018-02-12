# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 13:28:14 by rloulizi          #+#    #+#              #
#    Updated: 2018/02/12 15:39:57 by rloulizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

.PHONY: all, clean, fclean, re

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror
CC = gcc $(CFLAGS)

SRC_PATH = srcs/
SRC_NAME =  ft_ls.c ft_opt.c ft_stat.c \

OBJ_PATH = objs/
INC_PATH = includes/

LIB_PATH = libft/
LIB = $(LIB_PATH)libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(LIB):
	@make all -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $@
	@echo $(CCGREEN) ft_ls OK $(CCEND)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(LIB_PATH)$(INC_PATH) -I $(INC_PATH)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
