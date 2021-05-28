# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/28 17:06:54 by fbes          #+#    #+#                  #
#    Updated: 2021/05/28 20:07:45 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		server

SRCS =		useful.c inbox.c store.c comm.c server.c

OBJS =		$(SRCS:.c=.o)

CFLAGS =

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -fsanitize=address

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
