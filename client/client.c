/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:11:43 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 20:11:50 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdlib.h>
#include <unistd.h>
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

static void	write_num(int num)
{
	if (num != 0)
	{
		write_num(num / 10);
		write(1, &"0123456789"[num % 10], 1);
	}
}

static void	write_pid(void)
{
	write(1, "CLIENT PID: ", 12);
	write_num((int)getpid());
	write(1, "\n", 1);
}

static int	send_char(int server_pid, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		if (kill(server_pid, SIGUSR1) < -1)
			return (-1);
		write(1, "sent rece cmd\n", 14);
		i++;
	}
	if (kill(server_pid, SIGUSR2) < -1)
		return (-1);
	write(1, "sent next cmd\n", 14);
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
	write_pid();
	len = ft_strlen(argv[1]);
	i = 0;
	while (i < len)
	{
		if (send_char(server_pid, (int)argv[1][i]) < 0)
			return (err_exit("Failed to send message to server"));
		i++;
	}
	if (kill(server_pid, SIGUSR2) < 0)
		return (err_exit("Failed to send message to server"));
	write(1, "sent next cmd\n", 14);
	return (err_exit("Message sent"));
}
