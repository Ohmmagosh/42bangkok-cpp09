# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 21:43:01 by psuanpro          #+#    #+#              #
#    Updated: 2023/07/12 12:44:20 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PmergeMe
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		PmergeMe.cpp

OBJS = ${SRCS:.cpp=.o}

BRED =\033[1;31m
BGRN =\033[1;32m
BYEL =\033[1;33m
RES = \033[0m

COMPILE = echo "$(BGRN)$(NAME) compiled....$(RES)"
CLEAN = echo "$(BYEL)$(NAME) clean....$(RES)"
FCLEAN = echo "$(BRED)$(NAME) fclean....$(RES)"

.cpp.o:
	@$(CC) -g $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS)
		@$(CC) -g $(CFLAGS) $(OBJS) -o $@
		@$(COMPILE)

t:
	@$(CC) main.cpp -o test
	@sleep 1
	@./PmergeMe `jot -r 10 1 15 | tr '\n' ' '`

clean:
		@rm -rf $(OBJS)
		@$(FCLEAN)

fclean: clean
		@rm -rf $(NAME)
		@$(FCLEAN)

re: fclean all
.PHONY: all re clean fclean
