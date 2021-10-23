# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 00:36:11 by mhaman            #+#    #+#              #
#    Updated: 2021/10/23 02:40:11 by mhaman           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC			=	algorithm.c instruction.c list_ptr.c list.c \
				main.c parsing.c simple_sort.c sorting.c

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

SRC_PATH	=	srcs/

OBJ_NAME	=	${SRC:.c=.o}

OBJ_PATH	=	bin/

OBJ		=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIBFT_PATH	=	42_libft/

LIBFT_NAME	=	libft.a

LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

NAME		=	push_swap

RM			=	rm -rf

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror

all: $(LIBFT) $(OBJ_PATH) $(NAME)

$(LIBFT):
	@make -s -C 42_libft/

$(NAME): $(OBJ) 
	@gcc $(FLAG) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "	\033[2K\r\033[1;38;5;110mPushswap:\t\033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"
	@$(CC) $(FLAG) -c $< -o $@ 


clean:
	@${RM} ${OBJ_PATH}
	@make -s -C 42_libft/ clean


fclean: clean
	@${RM} ${NAME}
	@make -s -C 42_libft/ fclean

re: fclean all

norme:
	norminette srcs/
	@make -s -C 42_libft/ norme
	

.PHONY: all clean fclean re