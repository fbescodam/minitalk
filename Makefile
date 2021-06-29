# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/29 17:30:41 by fbes          #+#    #+#                  #
#    Updated: 2021/06/29 17:32:36 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all:
	make -C client
	make -C server

clean:
	make -C client clean
	make -C server clean

fclean:
	make -C client fclean
	make -C server fclean

re: fclean all

.PHONY: all clean fclean re
