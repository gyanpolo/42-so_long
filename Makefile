# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 16:09:27 by gpolo             #+#    #+#              #
#    Updated: 2024/09/12 16:09:23 by gpolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBS			= src/so_long.h

LIBSA           = libmlx.a

DLIBSA_MLX		= expansions/minilibx-linux

DLIBSA_PRINTF	= expansions/printf

OBJ_DIR			= obj/

SRC_DIR			= src/

SRCS_FILES		= src/fill_map2 src/BFS src/BFS_utils src/open_img src/clean_all_img2 src/tests src/clean_all_img src/split src/fill_map src/utils2 src/utils src/utils3 src/move src/move2 src/move3 src/create_map src/ft_itoa

SRCS			= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS			= $(shell find src/ -type d)
OBJSDIRS		= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP		= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS			= $(addsuffix .o, $(OBJSTEMP))

MKDIR			= mkdir -p

SANIT           = $(FLAGS) -fsanitize=address

CC				= gcc

FLAGS_MLX		= -L$(DLIBSA_MLX) -lmlx -Imlx_linux -lXext -lX11 -lm -lz

FLAGS			= -Wall -Werror -Wextra -I $(DLIBSA_MLX) -I $(DLIBSA_PRINTF)/src -g

RM				= rm -rf

all :			libs $(NAME)

$(NAME) : 		$(OBJSDIRS) $(OBJS) Makefile $(LIBS)
				$(CC) $(FLAGS) $(OBJS) $(FLAGS_MLX) $(LIBS) $(DLIBSA_PRINTF)/libftprintf.a -o $(NAME)

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c Makefile
				$(CC) $(FLAGS) -c $< $(FLAGS_MLX) -o $@

$(OBJSDIRS):	
				$(MKDIR) $(OBJSDIRS)

clean :
				$(RM) $(OBJECTS)

fclean : 		clean
				$(RM) $(NAME)
				$(RM) $(OBJSDIRS)

re : 			fclean $(NAME)

libs :
				make -C $(DLIBSA_PRINTF)
				make -C $(DLIBSA_MLX)

info:
				$(info $(SRCS_FILES))

normi:
				@norminette $(SRCS)

sanit:			FLAGS += $(SANIT)
				

.PHONY:         all clean fclean re info normi libs
