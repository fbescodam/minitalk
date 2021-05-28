/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comm.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:58:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 22:14:52 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

static void	comm_done_end(t_inbox *inbox)
{
	if (inbox->str)
	{
		write(1, inbox->str, ft_strlen(inbox->str));
		free(inbox->str);
		inbox->str = NULL;
	}
	write(1, "\n", 1);
}

static void	comm_receive(t_inbox *inbox)
{
	(inbox->c)--;
}

static void	comm_done_next(t_inbox *inbox)
{
	int			len;
	char		*temp;

	if (inbox->c == CHAR_MAX)
		return (comm_done_end(inbox));
	if (inbox->str)
		len = ft_strlen(inbox->str);
	else
		len = 0;
	len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	temp[len - 1] = inbox->c;
	inbox->c = CHAR_MAX;
	temp[len] = '\0';
	if (inbox->str)
	{
		ft_strcpy(inbox->str, temp);
		free(inbox->str);
	}
	inbox->str = temp;
	return ;
}

void	comm(int sig)
{
	static t_inbox	*inbox;

	if (!inbox)
		inbox = new_inbox();
	if (sig == SIGUSR1)
		comm_receive(inbox);
	else if (sig == SIGUSR2)
		comm_done_next(inbox);
	else if (sig == -42)
		free_inbox(inbox);
}
