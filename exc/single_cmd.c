/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:31:20 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/17 19:56:39 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int check_for_builtin(char *cmd)
{
    if (!ft_strncmp(cmd, "echo", 4))
        return (1);
    if (!ft_strncmp(cmd, "cd", 2))
        return (1);
    if (!ft_strncmp(cmd, "pwd", 3))
        return (1);
    if (!ft_strncmp(cmd, "export", 6))
        return (1);
    if (!ft_strncmp(cmd, "unset", 5))
        return (1);
    if (!ft_strncmp(cmd, "env", 3))
        return (1);
    if (!ft_strncmp(cmd, "exit", 4))
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
// void    test_redirections(t_minishell *mini)
// {
//     t_redir *tmp;
//     int     ret;

//     ret = 0;
//     tmp = mini->cmd->redirections;
//     while(tmp)
//     {
//         if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT)
//         {
//             redir_error(tmp);
//             ret = 1;
//         }
//         tmp = tmp->next;
//     }
// }

int	duping(t_redir *redir, t_exc *exc)
{
	exc->fd = open(redir->file, O_RDONLY);
	if (exc->fd == -1)
	{
		return (1);
	}
    return (0);
}

void    one_command(pid_t pid,t_minishell *mini)
{
    ft_fdinit(mini);
	if (pid == -1)
	{
		perror("fork");
		// exit(EXIT_FAILURE);
	}
    if (pid == 0)
    {
        if (mini->cmd->redirections->type == REDIR_IN)
            dup2(mini->exc->fd, 0);
        if (mini->cmd->redirections->type == REDIR_OUT)
            dup2(mini->exc->fd, 1);
        
        // test_redirections(mini);
    }
}

void    single_cmd(t_minishell *mini)
{
    pid_t   pid;

    pid = fork();
    sigchild = 0;
    if (check_for_builtin(mini->cmd->av[0]))
        return ;
    pid = fork();
    one_command(pid, mini);
    
}

