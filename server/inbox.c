/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inbox.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 19:06:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 20:13:12 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

static void	free_inbox(t_inbox *inbox)
{
	if (inbox->str)
		free(inbox->str);
	free(inbox);
}

t_inbox	*new_inbox(t_inbox **lst, pid_t from)
{
	t_inbox		*new;
	t_inbox		*temp;

	new = (t_inbox *)malloc(sizeof(t_inbox));
	if (!new)
		return (NULL);
	new->sender = from;
	new->c = 0;
	new->str = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (new);
}

t_inbox	*get_inbox(t_inbox **lst, pid_t from)
{
	t_inbox		*temp;

	if (!lst)
		return (NULL);
	temp = *lst;
	while (temp)
	{
		if (temp->sender == from)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_inbox	**remove_inbox(t_inbox **lst, pid_t from)
{
	t_inbox		*last;
	t_inbox		*temp;
	t_inbox		**ret;

	temp = *lst;
	last = NULL;
	while (temp)
	{
		if (temp->sender == from)
		{
			if (!last)
				ret = &(temp->next);
			else
			{
				ret = lst;
				last->next = temp->next;
			}
			free_inbox(temp);
			return (ret);
		}
		last = temp;
		temp = temp->next;
	}
	return (lst);
}

void	clear_inboxes(t_inbox **lst)
{
	t_inbox		*temp1;
	t_inbox		*temp2;

	if (lst)
	{
		temp1 = *lst;
		while (temp1)
		{
			temp2 = temp1->next;
			free_inbox(temp1);
			temp1 = temp2;
		}
		*lst = NULL;
	}
}
