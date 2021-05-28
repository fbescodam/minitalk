/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:11:41 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/28 20:18:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static void	write_pid(void)
{
	write(1, "SERVER PID: ", 12);
	write_num((int)getpid());
	write(1, "\n", 1);
}

static void	stop_server(int t)
{
	write(1, "\nGoodbye\n", 9);
	exit(t);
}

int	main(void)
{
	struct sigaction	comm_r;
	struct sigaction	comm_d_n;

	comm_r.sa_sigaction = comm_receive;
	sigemptyset(&comm_r.sa_mask);
	comm_r.sa_flags = SA_SIGINFO;
	comm_d_n.sa_sigaction = comm_done_next;
	sigemptyset(&comm_d_n.sa_mask);
	comm_d_n.sa_flags = SA_SIGINFO;
	write_pid();
	signal(SIGTERM, stop_server);
	signal(SIGHUP, stop_server);
	signal(SIGINT, stop_server);
	signal(SIGABRT, stop_server);
	signal(SIGQUIT, stop_server);
	signal(SIGTSTP, stop_server);
	sigaction(SIGUSR1, &comm_r, NULL);
	sigaction(SIGUSR2, &comm_d_n, NULL);
	while (1)
		pause();
	return (0);
}
