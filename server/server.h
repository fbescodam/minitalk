/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:50:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 19:58:59 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>

typedef struct s_inbox
{
	pid_t			sender;
	char			*str;
	char			c;
	struct s_inbox	*next;
}					t_inbox;

int					ft_strlen(char *str);
void				write_num(int num);
t_inbox				*new_inbox(t_inbox **lst, pid_t from);
t_inbox				*get_inbox(t_inbox **lst, pid_t from);
t_inbox				**remove_inbox(t_inbox **lst, pid_t from);
void				clear_inboxes(t_inbox **lst);
void				comm_receive(int sig, siginfo_t *info, void *uctx);
void				comm_done_next(int sig, siginfo_t *info, void *uctx);

#endif
