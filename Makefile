# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2022/03/28 17:44:00 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP   = push_swap
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
100ARG		= `ruby -e "puts (-1000..1000).to_a.shuffle.first(100).join(' ')"`
500ARG		= `ruby -e "puts (-1000..1000).to_a.shuffle.first(500).join(' ')"`
#ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"; ./push_swap $ARG | ./checker_Mac $ARG

all :
	@make -s -C libft
	@gcc -g $(CFLAGS) ./srcs/*.c libft/libft.a -o $(PUSH_SWAP)
	@printf "\e[38;5;46m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[38;5;46m█▓▒░	     Compiled Libft	    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m█▓▒░   push_swap build successfull  ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m ╚════════════════════════════════════╝\e[0m\n"

c100 :
	@printf "\e[34m█▓▒░	     100 ARGS - checker_Mac	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 10; ++i)) do ARG=$(100ARG); ./push_swap $(ARG) | ./checker_Mac $(ARG); done

c500 :
	@printf "\e[34m█▓▒░	     500 ARGS - checker_Mac	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 10; ++i)) do ARG="$(500ARG)"; ./push_swap $(ARG) | ./checker_Mac $(ARG); done

100 : all	
	@printf "\e[34m█▓▒░	     Testing 100 ARGS	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 50; ++i)) do ./push_swap $(100ARG) | wc -l; done

500 : all
	@printf "\e[34m█▓▒░	     Testing 500 ARGS	    ░▒▓█ \e[0m\n"
	@for ((i=1; i <= 10; ++i)) do ./push_swap $(500ARG) | wc -l; done

clean :
	@make -s clean -C libft
	@rm -rf ./srcs/*.o
	@sleep 1;
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Clean complete  	    █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@rm -rf $(PUSH_SWAP)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all