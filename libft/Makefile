# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 18:25:40 by rloulizi          #+#    #+#              #
#    Updated: 2018/02/11 14:32:46 by rloulizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

.PHONY: all, clean, fclean, re

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc $(CFLAGS)

SRC_PATH = srcs
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	   ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	   ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	   ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	   ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_word_number.c ft_is_prime.c \
	   ft_power.c ft_range.c ft_strrev.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c  ft_lstmap.c \
	   ft_lstnew.c get_next_line.c\

S_PRINTF_PATH = $(SRC_PATH)/printf
S_PRINTF_NAME = ft_atoi2.c ft_conv.c ft_conv2.c ft_conv3.c ft_conv4.c ft_conv5.c ft_espace.c\
			   	ft_espace2.c ft_itoa_base.c ft_min_wi.c ft_mod.c ft_mod2.c ft_prec.c ft_printf.c\
				ft_static_esp.c ft_static_esp2.c ft_static_sharp.c ft_upp.c ft_wchar.c\


OBJ_PATH = objs
INC_PATH = includes

OBJ_NAME = $(SRC_NAME:.c=.o)
O_PRINTF_NAME = $(S_PRINTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
S_PRINTF = $(addprefix $(S_PRINTF_PATH)/,$(S_PRINTF_NAME))
O_PRINTF = $(addprefix $(OBJ_PATH)/,$(O_PRINTF_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(O_PRINTF)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo $(CCGREEN) libft OK $(CCEND)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH) -o $@ -c $<

$(OBJ_PATH)/%.o : $(S_PRINTF_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -f $(O_PRINTF)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(O_PRINTF_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(S_PRINTF)
	norminette $(SRC)
	norminette $(INC_PATH)*.h
