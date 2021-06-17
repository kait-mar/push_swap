# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 17:15:38 by molabhai          #+#    #+#              #
#    Updated: 2021/06/07 12:41:13 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= push_swap

CC= gcc

FLAGS= -Wall -Wextra -Werror

SRCS=  main.c

OBJ = $(SRCS:.c=.o)

HEADERS= push_swap.h

DELETEOBJ= rm -rf *.o

DELETENAME= rm -rf $(NAME)

MAKINGLIBFT= cd Libft && make -f Makefile

all: $(NAME)
$(NAME):
	$(MAKINGLIBFT)
	$(CC) $(FLAGS) $(SRCS)  Libft/libft.a -o push_swap
clean:
	$(DELETEOBJ) $(DELETENAME)
	cd Libft && make fclean -f Makefile

fclean : clean
	rm -rf $(NAME)

re: clean all
