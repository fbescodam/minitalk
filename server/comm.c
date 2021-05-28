/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comm.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:58:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 20:10:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static t_inbox	**get_inbox_list(void)
{
	static t_inbox	*inboxes;

	return (&inboxes);
}

void	comm_receive(int sig, siginfo_t *info, void *uctx)
{
	t_inbox		*inbox;

	write(1, "received rece cmd\n", 18);
	inbox = get_inbox(get_inbox_list(), info->si_pid);
	if (!inbox)
		inbox = new_inbox(get_inbox_list(), info->si_pid);
	if (!inbox)
		return ;
	(inbox->c)++;
}

static void	comm_done_end(t_inbox *inbox)
{
	write(1, "[", 1);
	write_num((int)(inbox->sender));
	write(1, "]", 1);
	write(1, inbox->str, ft_strlen(inbox->str));
	write(1, "\n", 1);
	remove_inbox(get_inbox_list(), inbox->sender);
}

void	comm_done_next(int sig, siginfo_t *info, void *uctx)
{
	t_inbox		*inbox;
	int			len;
	char		*temp;

	write(1, "received next cmd\n", 18);
	inbox = get_inbox(get_inbox_list(), info->si_pid);
	if (!inbox)
		inbox = new_inbox(get_inbox_list(), info->si_pid);
	if (!inbox)
		return ;
	if (inbox->c == 0)
		return (comm_done_end(inbox));
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
		free(inbox->str);
	inbox->str = temp;
	return ;
}
