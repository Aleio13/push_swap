# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 15:46:42 by almatsch          #+#    #+#              #
#    Updated: 2025/02/02 15:46:42 by almatsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -I./utils -I.

LIBSRC = utils/ft_split.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_lst_size.c operations/swap.c operations/push.c operations/reverse.c operations/rotate.c args_checks.c parser.c sorting/hard_sort.c sorting/sort_helpers.c sorting/create_index.c sorting/radix_sort.c
LIBOBJ = $(LIBSRC:.c=.o)
LIBRARY = utils/libft.a

SRC = main.c
OBJ = $(SRC:.c=.o)

EXEC = push_swap

$(EXEC): $(OBJ) $(LIBRARY)
	$(CC) $(OBJ) $(LIBRARY) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(LIBOBJ)
	ar rcs $(LIBRARY) $(LIBOBJ)

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(EXEC) $(LIBRARY)

re: fclean $(EXEC)

.PHONY: clean fclean re
