/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:15:10 by vlima             #+#    #+#             */
/*   Updated: 2023/09/25 13:42:10 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

void	setup_signal_handling(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = ft_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
}

void	start_server(void)
{
	ft_printf("\033[34mThis is your PID %d\n Use it in the client file\n",
		getpid());
	ft_printf("\033[33mWaiting for your message..\n");
	while (1)
	{
		pause();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_printf("Error\nFormat: %s\n", argv[0]);
		return (0);
	}
	setup_signal_handling();
	start_server();
	return (0);
}
