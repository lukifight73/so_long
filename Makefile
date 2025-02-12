# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 15:05:53 by lbenatar          #+#    #+#              #
#    Updated: 2024/10/09 15:31:20 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET  = $(shell printf "\33[0m")
GREEN  = $(shell printf "\33[32m")

SRC	= src/backtracking.c \
		src/handle_input.c \
		src/liberator.c \
		src/move_poulpy.c \
		src/verif_collectibles.c \
		src/verif_map.c \
		src/get_map.c \
		src/init_data.c \
		src/verif_ber.c \
		src/verif_exit.c \

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Wextra -Werror

NAME = so_long.a

NAME_EXE = so_long

OBJ	= $(SRC:.c=.o)

.c.o	:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME} libft

${NAME} : $(LIBFT) ${OBJ}
		@cp $(LIBFT) $(NAME)
		@ar rcs ${NAME} ${OBJ}
		cc ${CFLAGS} ./src/main.c -L. ${NAME} -lmlx -lXext -lX11 -lm -o ${NAME_EXE}

$(LIBFT):
			@make --silent -C ./libft
			@echo "$(GREEN)LIBFT Successfully compiled $(RESET)"

clean :
		@rm -f ${OBJ}
		@rm -rf ./srcs/*.o
		@make --silent -C ./libft clean
		@echo "$(GREEN) Successfully cleaned $(RESET)"

fclean : clean
		@rm -f ${NAME}
		@rm -f ${NAME_EXE}
		@make --silent -C ./libft fclean
		@echo "$(GREEN) Successfully fcleaned$(RESET)"

re : fclean all

.PHONY:	all clean fclean re libft
