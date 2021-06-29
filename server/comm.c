/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comm.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:58:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/29 21:04:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>

static void	output(t_inbox *inbox)
{
	if (inbox->str)
	{
		write(1, inbox->str, ft_strlen(inbox->str));
		free(inbox->str);
		inbox->str = NULL;
	}
	write(1, "\n", 1);
}

static void	next_char(t_inbox *inbox)
{
	int		len;
	char	*temp;

	if (inbox->c == '\0')
		return (output(inbox));
	if (inbox->str)
		len = ft_strlen(inbox->str);
	else
		len = 0;
	len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (stop_server(137));
	temp[len - 1] = inbox->c;
	temp[len] = '\0';
	if (inbox->str)
	{
		ft_strcpy(inbox->str, temp);
		free(inbox->str);
	}
	inbox->str = temp;
	inbox->c = '\0';
	return ;
}

static void	set_bit_pos(t_inbox *inbox, int pos)
{
	char	mask;

	mask = 1 << pos;
	inbox->c = ((inbox->c & ~mask) | (1 << pos));
}

void	comm(int sig)
{
	static t_inbox	*inbox;
	static int		pos = CHAR_BIT - 1;

	if (!inbox)
		inbox = new_inbox();
	if (sig == SIGUSR1)
		set_bit_pos(inbox, pos);
	else if (sig == -42)
		return (free_inbox(inbox));
	if (pos == 0)
	{
		pos = CHAR_BIT - 1;
		next_char(inbox);
	}
	else
		pos--;
}
