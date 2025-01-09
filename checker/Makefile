# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/30 19:03:14 by mahkilic      #+#    #+#                  #
#    Updated: 2025/01/02 09:23:06 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
ALGDIR = src/algorithm
INSDIR = src/instructions
STCDIR = src/stack
GNLDIR = gnl
OBJDIR = objects
INCDIR = include
LIBFTDIR = ../libft
LIBFT = $(LIBFTDIR)/libft.a

# Source files and object files
SRCS =		$(SRCDIR)/main.c \
			$(SRCDIR)/error_free.c \
			$(SRCDIR)/utils.c \
			$(ALGDIR)/push_swap.c \
			$(ALGDIR)/init_nodes_a.c \
			$(ALGDIR)/init_nodes_b.c \
			$(ALGDIR)/large_sort.c \
			$(ALGDIR)/tiny_sort.c \
			$(INSDIR)/push.c \
			$(INSDIR)/rotate.c \
			$(INSDIR)/rrotate.c \
			$(INSDIR)/swap.c \
			$(STCDIR)/stack_init.c \
			$(STCDIR)/stack_utils.c \
			$(GNLDIR)/get_next_line.c \
			$(GNLDIR)/get_next_line_utils.c
		 
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
NAME = push_swap

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re