# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/28 17:11:22 by fbes          #+#    #+#                  #
#    Updated: 2021/05/28 21:12:36 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		client

SRCS =		ft_atoi.c client.c

OBJS =		$(SRCS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@echo "Bonus not done yet"

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
