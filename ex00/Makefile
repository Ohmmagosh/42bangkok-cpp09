# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 16:18:08 by psuanpro          #+#    #+#              #
#    Updated: 2023/06/17 23:08:56 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=BitcoinExchange
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		BitcoinExchange.cpp

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

$(NAME): $(OBJS)
	@$
