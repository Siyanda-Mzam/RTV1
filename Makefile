# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simzam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/10 09:17:10 by simzam            #+#    #+#              #
#    Updated: 2016/07/17 13:23:47 by simzam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		rtv1

SRCS=		src/main.c		\
			src/computations.c		\
			src/lighting.c		\
			src/shading.c	\
			src/colours.c	\
			src/rotate.c	\
			src/intersections.c	\
			src/draw.c		\
			src/object_ds.c		\
			src/event_handlers.c \
			utils/ft_clamp.c \
			utils/ft_vec.c \
			utils/logger.c \
			utils/ft_vec2.c \
			utils/ft_vec3.c \
			utils/main_helpers.c

OBJS=		$(SRCS:%.c=%.o)

LIXLIB=		-L/usr/lib/X11 -lmlx -lXext -lX11 -lm
MACLIB=		-L/usr/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS=		-Wall -Wextra -Werror -I/usr/X11/include/ -Iincludes

CC=			gcc

RM=			rm -f

all: $(NAME)

$(NAME): $(OBJS)

ifeq ($(shell) uname, Linux)
		@echo "\033[35mCompilation: \033[32m OK! \033[0m"
		@$(CC) -o $(NAME) $(OBJS) $(LIXLIB)
else
		@echo "\033[35mCompilation: \033[32m OK! \033[0m"
		@$(CC) -o $(NAME) $(OBJS) $(MACLIB)
		@echo "\033[31mNow, Ray-tracing\033[0m"
endif

clean:
		@$(RM) $(OBJS)
		@cd src/ rm -rf
		@cd utils/ rm -rf

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
