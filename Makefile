# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/08 19:45:43 by mahkilic      #+#    #+#                  #
#    Updated: 2024/10/18 17:57:01 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft/libft.a

SRCS		=	src/main.c src/algorithm.c src/utils.c \
				operations/push_operations.c operations/swap_operations.c \
				operations/rotate_operations.c operations/reverse_rotate_operations.c

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I include -I libft/include -fsanitize=address

all:		$(LIBFT) $(NAME)

$(LIBFT):
			make -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C libft clean
			$(RM) $(OBJS)

fclean:		clean
			make -C libft fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re