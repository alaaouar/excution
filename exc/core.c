/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:37:48 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/16 21:56:56 by alaaouar         ###   ########.fr       */
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
    t_env *env;
    
    env = set_env(mini->cmd->env);
    if (mini->cmd == NULL || mini->cmd->av == NULL || mini->cmd->av[0] == NULL)
    {
        fprintf(stderr, "Invalid command\n");
        return;
    }
    if (ft_strncmp(mini->cmd->av[0], "pwd", 3) == 0)
        pwd_cmd();
    else if (ft_strncmp(mini->cmd->av[0], "echo", 4) == 0)
        minishell_echo(mini->cmd);
    else if (ft_strncmp(mini->cmd->av[0], "cd", 2) == 0)
        minishell_cd(mini->cmd);
    else if (ft_strncmp(mini->cmd->av[0], "env", 3) == 0)
        minishell_env(mini->cmd);
    else if (ft_strncmp(mini->cmd->av[0], "unset", 5) == 0)
        minishell_unset(mini->cmd);
    else
        single_cmd(mini);
    // else if (ft_strncmp(mini->cmd->av[0], "export", 6) == 0)
    //     minishell_export(cmd, env);
    mini->cmd = mini->cmd->next;
}
