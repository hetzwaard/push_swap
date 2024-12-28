# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/28 16:24:04 by mahkilic      #+#    #+#                  #
#    Updated: 2024/12/28 23:51:25 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = includes
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

# Source files and object files
SRCS =	$(SRCDIR)/main.c \
			$(SRCDIR)/input.c \
			$(SRCDIR)/utils.c \
			$(SRCDIR)/validation.c \
			$(SRCDIR)/push.c \
			$(SRCDIR)/swap.c \
			$(SRCDIR)/rotate.c \
			$(SRCDIR)/rrotate.c \
			$(SRCDIR)/sort_five.c \
			$(SRCDIR)/sort_three.c
		 
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Output executable
NAME = push_swap

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
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