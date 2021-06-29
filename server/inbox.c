/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inbox.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 19:06:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/29 20:26:48 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <limits.h>
#include <stdlib.h>

void	free_inbox(t_inbox *inbox)
{
	if (inbox->str)
		free(inbox->str);
	free(inbox);
}

t_inbox	*new_inbox(void)
{
	t_inbox		*new;

	new = (t_inbox *)malloc(sizeof(t_inbox));
	if (!new)
		return (NULL);
	new->c = '\0';
	new->str = NULL;
	return (new);
}
