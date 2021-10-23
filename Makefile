# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 00:36:11 by mhaman            #+#    #+#              #
#    Updated: 2021/10/23 02:11:32 by mhaman           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC			=	algorythm.c instruction.c list_ptr.c list.c \
				main.c parsing.c simple_sort.c sorting.c

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

SRC_PATH	=	srcs/

HEADER_PATH	=	includes/

OBJ_NAME	=	${SRC:.c=.o}

OBJ_PATH	=	bin/

OBJ		=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

RM			=	rm -rf

CC			=	gcc

LIBFT		=	libft.a

NAME		=	push_swap

FLAG		=	-Wall -Wextra -Werror

C-O				=	$(CC) $(CFLAGS) $(LIBFT_LIB) $(INCLUDES) -c $< -o $@

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C 42_libft/

$(NAME): $(OBJ) $(HEADER_PATH) $(LIBFT)
	gcc $(FLAG) $(OBJ) $(LIBFT) -o $(NAME)
	printf "	\033[2K\r\033[1;38;5;110mlibft\t:\t\033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_PATH)
	@$(CC) $(FLAG) -c $< -o $@

clean:
	@${RM} ${OBJ_PATH}

fclean: clean
	@${RM} ${NAME}
	#make -s -C 42_libft/ fclean

re: fclean all

debug:
	make all DEBUG_FLAGS="-g3 -fsanitize=address"

redebug:
	make re DEBUG_FLAGS="-g3 -fsanitize=address"

norme:
	norminette srcs/

.PHONY: all clean fclean re debug redebug