/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:16:12 by kanye             #+#    #+#             */
/*   Updated: 2025/04/01 18:36:30 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int main(int argc, char **argv)
{  
    pid_t pid;

    if(argc != 3)
    {
        ft_printf("ERROR. Different than 3 arguments are not allowed\n");
        ft_printf("FORMAT REQUIRED: ./client <PID> <MESSAGE>");
    }
    else
    {
        pid = ft_atoi(argv[1]);
        if(!pid)
        {
            ft_printf("ERROR in the PID number");
            return 0;
        }
        if(!argv[2])
        {
            ft_printf("ERROR in the MESSAGE to send");
            return 0;
        }
        send_bits(pid, argv[2]);
    }
    return 0;
    
}

void    send_bits(int pid, char *message)
{
    
}

