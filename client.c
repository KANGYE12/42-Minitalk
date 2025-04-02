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
    char *message;
    int i;

    i = 0;    
    if(argc != 3)
        ft_printf("ERROR. Different than 3 arguments are not allowed");
    pid = ft_atoi(argv[1]);
    message = argv[2];
    
    while(message[i]){
        send_bit(pid, message[i]);
        i++;
    }
    send_bit(pid, '\0');
}

void send_bit(pid_t pid, char c)
{
    int i = 0; //10000000 & 1
        kill(pid, SIGUSR2); //bit 1
        //else
           // kill(pid, SIGUSR1); //bit 0
    while(i << 7)
    {
        i++;
        usleep(100);
    }
    
    
}