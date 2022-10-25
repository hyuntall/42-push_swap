# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:12:08 by hyuncpar          #+#    #+#              #
#    Updated: 2022/10/25 18:13:31 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BNAME	=	checker

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS	=	main.c parse.c list_utils.c utils.c push.c swap.c rotate.c reverse_rotate.c \
			stack_sort.c make_tri.c make_arr.c merge.c print_error.c ft_split.c ft_strdup.c \
			ft_strjoin.c ft_strlen.c command_list.c ft_strcmp.c

BSRCS	=	./bonus/main.c ./bonus/parse.c ./bonus/list_utils.c ./bonus/utils.c \
			./bonus/push.c ./bonus/swap.c ./bonus/rotate.c ./bonus/reverse_rotate.c \
			./bonus/ft_split.c ./bonus/ft_strcmp.c ./bonus/print_error.c \
			./bonus/get_next_line.c ./bonus/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

BOBJS	= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BNAME) : $(BOBJS)
	@$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)

bonus : $(BNAME)
	
all : $(NAME) $(BNAME)

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME) $(BNAME)

re : fclean
	$(MAKE)

.PHONY : all clean fclean re bonus