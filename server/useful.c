/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   useful.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 19:57:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 21:52:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>

void	write_num(int num)
{
	if (num > 0)
	{
		write_num(num / 10);
		write(1, &"0123456789"[num % 10], 1);
	}
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *src, char *dst)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
}
