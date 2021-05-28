/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:11:43 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 22:12:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	err_exit(char *err)
{
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	exit(1);
}

static int	send_char(int server_pid, int c)
{
	int		i;

	i = CHAR_MAX;
	while (i > c)
	{
		if (kill(server_pid, SIGUSR1) < -1)
			return (-1);
		usleep(WAIT_TIME_MS);
		i--;
	}
	if (kill(server_pid, SIGUSR2) < -1)
		return (-1);
	usleep(WAIT_TIME_MS * 4);
	return (0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		len;
	int		i;

	if (argc < 3)
		return (err_exit("Too few arguments, expected 2"));
	else if (argc > 3)
		return (err_exit("Too many arguments, expected 2"));
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (err_exit("Invalid PID"));
	len = ft_strlen(argv[2]);
	i = 0;
	while (i < len)
	{
		if (send_char(server_pid, (int)argv[2][i]) < 0)
			return (err_exit("Failed to send message to server"));
		i++;
	}
	if (kill(server_pid, SIGUSR2) < 0)
		return (err_exit("Failed to send message to server"));
	usleep(WAIT_TIME_MS);
	return (err_exit("Message sent"));
}
