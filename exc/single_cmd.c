/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:31:20 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/16 21:19:02 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int check_for_builtin(char *cmd)
{
    if (!ft_strcmp(cmd, "echo"))
        return (1);
    if (!ft_strcmp(cmd, "cd"))
        return (1);
    if (!ft_strcmp(cmd, "pwd"))
        return (1);
    if (!ft_strcmp(cmd, "export"))
        return (1);
    if (!ft_strcmp(cmd, "unset"))
        return (1);
    if (!ft_strcmp(cmd, "env"))
        return (1);
    if (!ft_strcmp(cmd, "exit"))
        return (1);
    return (0);
}

void    redir_error(t_redir *redi)
{
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(redi->file, 2);
    if (!access(redi->file, F_OK) && access(redi->file, X_OK) == -1)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": No such file or directory\n", 2);
}
void    test_redirections(t_minishell *mini)
{
    t_redir *tmp;
    int     ret;

    ret = 0;
    tmp = mini->cmd->redirections;
    while(tmp)
    {
        if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT)
        {
            redir_error(tmp);
            ret = 1;
        }
        tmp = tmp->next;
    }
}

void    one_command(pid_t pid,t_minishell *mini)
{
    if (pid == -1)
    {
        perror("fork");
        // exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (mini->cmd->redirections->type == REDIR_IN)
            dup2(mini->cmd->redirections->file, 0);
        if (mini->cmd->redirections->type == REDIR_OUT)
            dup2(mini->cmd->redirections->file, 1);
        // test_redirections(mini);
        
        
    }
}

void    single_cmd(t_minishell *mini)
{
    pid_t   pid;
    int     status;

    pid = fork();
    sigchild = 0;
    if (check_for_builtin(mini->cmd->av[0]))
        return ;
    pid = fork();
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler2);
    one_command(pid, mini);
    
}
