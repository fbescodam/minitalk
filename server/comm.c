/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comm.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:58:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 20:50:28 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static t_inbox	**get_inbox_list(void)
{
	static t_inbox	*inboxes;

	return (&inboxes);
}

void	comm_receive(int sig, siginfo_t *info, void *uctx)
{
	t_inbox		*inbox;

	write(1, "si_pid: ", 8);
	write_num((int)6789);
	if (6789 == 0)
		write(1, "AAAAAA\n", 7);
	write(1, "-received rece cmd (", 20);
	inbox = get_inbox(get_inbox_list(), 6789);
	if (!inbox)
		inbox = new_inbox(get_inbox_list(), 6789);
	if (!inbox)
	{
		write(1, "Could not create new inbox\n", 27);
		return ;
	}
	(inbox->c)++;
	//kill(6789, SIGUSR1);
	if (inbox->c >= 32 && inbox->c <= 126)
		write(1, &inbox->c, 1);
	else
		write(1, "unprintable", 11);
	write(1, ")\n", 2);
}

static void	comm_done_end(t_inbox *inbox, pid_t from)
{
	write(1, "[", 1);
	write_num((int)(inbox->sender));
	write(1, "]", 1);
	write(1, inbox->str, ft_strlen(inbox->str));
	write(1, "\n", 1);
	remove_inbox(get_inbox_list(), inbox->sender);
	//if (kill(from, SIGUSR2) < 0)
	//	write(1, "WARNING\n", 8);
}

void	comm_done_next(int sig, siginfo_t *info, void *uctx)
{
	t_inbox		*inbox;
	int			len;
	char		*temp;

	write(1, "received next cmd\n", 18);
	inbox = get_inbox(get_inbox_list(), 6789);
	if (!inbox)
		inbox = new_inbox(get_inbox_list(), 6789);
	if (!inbox)
	{
		write(1, "Could not create new inbox\n", 27);
		return ;
	}
	if (inbox->c == 0)
		return (comm_done_end(inbox, 6789));
	if (inbox->str)
		len = ft_strlen(inbox->str);
	else
		len = 0;
	len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	temp[len - 1] = inbox->c;
	inbox->c = 0;
	temp[len] = '\0';
	if (inbox->str)
	{
		ft_strcpy(inbox->str, temp);
		free(inbox->str);
	}
	inbox->str = temp;
	//if (kill(6789, SIGUSR2) < 0)
	//	write(1, "WARNING\n", 8);
	return ;
}
