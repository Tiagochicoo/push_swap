# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2022/03/22 17:36:25 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP   = push_swap
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

all :
	@make -s -C libft
	@gcc -g $(CFLAGS) ./srcs/*.c libft/libft.a -o $(PUSH_SWAP)
	@printf "\e[38;5;46m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[38;5;46m█▓▒░	     Compiled Libft	    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m█▓▒░   push_swap build successfull  ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m ╚════════════════════════════════════╝\e[0m\n"

100 : all
	@printf "\e[34m█▓▒░	     Testing 100 ARGS	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 50; ++i)) do ./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.first(100).join(' ')"` | wc -l; done

500 : all
	@printf "\e[34m█▓▒░	     Testing 500 ARGS	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 10; ++i)) do ./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.first(500).join(' ')"` | wc -l; done

clean :
	@make -s clean -C libft
	@rm -rf ./srcs/*.o
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Clean complete  	    █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@rm -rf $(PUSH_SWAP)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all