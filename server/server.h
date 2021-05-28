/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:50:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 22:14:38 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_inbox
{
	char			*str;
	char			c;
	struct s_inbox	*next;
}					t_inbox;

int					ft_strlen(char *str);
void				write_num(int num);
void				ft_strcpy(char *src, char *dst);
t_inbox				*new_inbox(void);
void				free_inbox(t_inbox *inbox);
void				comm(int sig);

#endif
