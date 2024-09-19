# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 11:26:21 by gpolo             #+#    #+#              #
#    Updated: 2024/08/13 11:49:38 by gpolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME							:= libftprintf.a

LIBS							:= src/libftprintf.h

SOURCES							:= src/ft_printf.c src/ft_putnbr.c src/ft_putunbr.c src/ft_putchar.c src/ft_putstr.c src/ft_putxnbr.c src/ft_puthex.c src/ft_putstring_printf.c src/ft_putXnbr.c

OBJECTS							:= obj/ft_printf.o obj/ft_putnbr.o obj/ft_putunbr.o obj/ft_putchar.o obj/ft_putstr.o obj/ft_putxnbr.o obj/ft_puthex.o obj/ft_putstring_printf.o obj/ft_putXnbr.o

OBJ_DIR							:= obj/

SRC_DIR							:= src/

MKDIR							:= mkdir -p

CC								:= gcc

FLAGS							:= -Wall -Werror -Wextra

AR								:= ar rcs

RAN								:= ranlib

RM								:= rm -f

all :							$(NAME)

$(NAME) : 						$(OBJ_DIR) $(OBJECTS) $(LIBS) Makefile
								$(AR) $(NAME) $(OBJECTS)
								$(RAN) $(NAME)

$(OBJ_DIR) :
								$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c	$(LIBS) Makefile
								$(CC) $(FLAGS) -c $< -o $@
clean :
								$(RM) $(OBJECTS)

fclean : 						clean
								$(RM) $(NAME)
		
re : 							fclean all

info:
								$(info $(SRCS_FILES))
								$(info $(SRCDIRS))

.PHONY: all clean fclean re bonus rebonus
