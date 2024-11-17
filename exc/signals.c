/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:37:07 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/17 20:25:07 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

int sigchild = 0;

void    sig_handler(int sig)
{
	if (sig == SIGINT && sigchild)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		sigchild = 0;
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void    sig_handler2(int sig)
{
	// write(1, "here", 4);
	if (sig == SIGQUIT && sigchild)
	{
		printf("Quit (core dumped)\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		sigchild = 0;
	}
	else
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
