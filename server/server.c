/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:11:41 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/29 20:17:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	write_pid(void)
{
	write(1, "SERVER PID: ", 12);
	write_num((int)getpid());
	write(1, "\n", 1);
}

// comm(-42) below is used to free the inbox

static void	stop_server(int t)
{
	comm(-42);
	write(1, "\nGoodbye\n", 9);
	exit(t);
}

int	main(void)
{
	write_pid();
	signal(SIGTERM, stop_server);
	signal(SIGHUP, stop_server);
	signal(SIGINT, stop_server);
	signal(SIGABRT, stop_server);
	signal(SIGQUIT, stop_server);
	signal(SIGTSTP, stop_server);
	signal(SIGUSR1, comm);
	signal(SIGUSR2, comm);
	while (1)
		pause();
	return (0);
}
