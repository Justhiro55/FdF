# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:10:25 by hhagiwar          #+#    #+#              #
#    Updated: 2023/08/24 17:34:46 by hhagiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
SRC = src/main.c \
	src/read_file.c \
	src/func.c \
	src/error.c \
	src/draw.c \
	src/affine.c\
	src/event.c \
	src/free.c 


OBJ = ${SRC:.c=.o}
LIBFTDIR	=	libft
LIBFT		=	func/$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

PRINTFDIR = ft_printf
PRINTF = func/$(PRINTFDIR)/libftprintf.a
PRINT = $(PRINTF)

GNLDIR = get_next_line
GNL_SRC = func/$(GNLDIR)/get_next_line.c func/$(GNLDIR)/get_next_line_utils.c
GNL = ${GNL_SRC}


$(NAME): $(OBJ)
	make -C func/${LIBFTDIR}
	$(CC) ${LIB} ${PRINT} ${GNL} $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "\e[38;5;226m./$@ builed success\e[0m\n"
	@printf "Please pass...🙏🙏🙏\e[0m\n"

all: $(NAME)

clean:
	${RM} ${RMFLAGS} func/ft_printf/*.o func/libft/*.o func/get_next_line/*.o src/*.o
    
fclean: clean
	${RM} ${NAME}
	@printf "\e[38;5;226m./$@ successfully deleted\e[0m\n"

re: fclean all

.PHONY: bonus all clean fclean re
