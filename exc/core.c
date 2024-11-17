/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:37:48 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/17 03:15:36 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd_cmd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		return;
	}
	ft_putstr_fd(pwd, 1);
	write(1, "\n", 1);
	free(pwd);
}

void    minishell_echo(t_cmd *cmd)
{
	int i;

	i = 1;
	while (cmd->av[i])
	{
		ft_putstr_fd(cmd->av[i], 1);
		if (cmd->av[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
void    minishell_cd(t_cmd *cmd)
{
	if (cmd->ac == 1)
	{
		chdir(getenv("HOME"));
		return;
	}
	if (chdir(cmd->av[1]) == -1)
	{
		perror("cd");
		return;
	}
}

void    minishell_env(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->env[i])
	{
		ft_putstr_fd(cmd->env[i], 1);
		write(1, "\n", 1);
		i++;
	}
}
void    minishell_unset(t_cmd *cmd)
{
	int i;

	i = 1;
	while (cmd->av[i])
	{
		if (unsetenv(cmd->av[i]) == -1)
		{
			perror("unsetenv");
			return;
		}
		i++;
	}
}

void    excute(t_minishell *mini)
{
	// t_env *env;

	// env = set_env(mini->cmd->env);
	if (mini->cmd == NULL || mini->cmd->av == NULL || mini->cmd->av[0] == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		return;
	}
	mini->cmd = mini->cmd->next;
}
