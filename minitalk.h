/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:34 by kanye             #+#    #+#             */
/*   Updated: 2025/04/01 18:18:10 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <sys/types.h>

void    send_bits(int server_pid, char *message);

#endif
