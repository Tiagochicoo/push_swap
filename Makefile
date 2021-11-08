# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2021/11/08 20:01:16 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP   = push_swap
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

all :
	@make -s -C libft
	@gcc -g  ./srcs/*.c libft/libft.a -o $(PUSH_SWAP)
	@printf "\e[38;5;46m✅      Compiled Libft	    ✅ \e[0m\n"
	@printf "\e[38;5;46m✅   push_swap build successfull  ✅ \e[0m\n"

yes : all
	./push_swap 1 2 3 4 5

no : all
	./push_swap 5 4 3 2 1

clean :
	@make -s clean -C libft
	@rm -rf ./srcs/*.o
	@printf "\e[31;5;200m🚮️ 	Clean complete      🚮️\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@rm -rf $(PUSH_SWAP)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all