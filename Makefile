# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 09:01:59 by hkalia            #+#    #+#              #
#    Updated: 2017/02/11 17:23:31 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libarr.a
CC			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
LDFLAGS		+=	-L . $(subst .a,,$(subst lib,-l,$(NAME)))
TEST		:=	test.c
FILES		:=	arr_append arr_insert arr_main arr_other arr_qsort_r	\
				arr_qsort arr_removem arr_reverse

SRC			:=	$(addprefix srcs/, $(addsuffix .c, $(FILES)))
OBJ			:=	$(SRC:.c=.o)

# MATH

MAX			:=	$(words $(OBJ))
n			:=	x
increment	=	$1 x
COUNTER		=	$(words $n)$(eval n := $(call increment,$n))

# RULES

.PHONY: all clean

all: $(NAME)

$(OBJ): %.o: %.c
	@printf "\r\e[31mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking and indexing... \e[0m"
	@ar rcs $(NAME) $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"

clean:
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@printf "\e[31mDeleting %s... \e[0m" $(NAME)
	@rm -f $(NAME)
	@printf "\e[32m[DONE]\e[0m\n"

re: fclean all

test: re
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"
	@printf "\e[32mCompiling %s with %s... \e[0m" $(TEST) $(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(TEST) -o test
	@printf "\e[32m[DONE]\e[0m\n"
