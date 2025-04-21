/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:16:29 by kanye             #+#    #+#             */
/*   Updated: 2025/04/21 13:16:29 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Server must not have more than one argument (./server)\n");
		exit(1);
	}
	server_pid = getpid();
	ft_printf("PID number of the server: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("Waiting for signals'\n'");
	while (1)
		pause();
	return (0);
}

void	signal_handler(int signal)
{
	static unsigned char	bits[8];
	static int				bit_index;
	unsigned char			result;
	int						i;

	if (signal == SIGUSR1)
		bits[bit_index] = 0;
	else if (signal == SIGUSR2)
		bits[bit_index] = 1;
	bit_index++;
	if (bit_index == 8)
	{
		i = 0;
		result = 0;
		while (i < 8)
		{
			result |= bits[i] << (7 - i);
			i++;
		}
		if (result == '\0')
			write(1, "\n", 1);
		else
			write(1, &result, 1);
		bit_index = 0;
	}
}
