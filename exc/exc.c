/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:14:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/17 19:51:31 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int cmd_count(t_cmd *cmd)
{
    int count;
    t_cmd *tmp;
    
    tmp = cmd;
    count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

int    ft_fdinit(t_minishell*mini)
{
    t_redir *tmp;


    tmp = mini->cmd->redirections;
    while (tmp)
    {
        if (tmp->type == REDIR_IN)
        {
            mini->exc->fd = open(tmp->file, O_RDONLY);
            if (mini->exc->fd == -1)
            {
                ft_putstr_fd("minishell: ", 2);
                ft_putstr_fd(tmp->file, 2);
                if (!access(tmp->file, F_OK) && access(tmp->file, X_OK) == -1)
                    ft_putstr_fd(": Permission denied\n", 2);
                else
                    ft_putstr_fd(": No such file or directory\n", 2);
                return (1);
            }
        }
        else if (tmp->type == REDIR_OUT)
        {
            mini->exc->fd = open(tmp->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (mini->exc->fd == -1)
            {
                ft_putstr_fd("minishell: ", 2);
                ft_putstr_fd(tmp->file, 2);
                if (!access(tmp->file, F_OK) && access(tmp->file, X_OK) == -1)
                    ft_putstr_fd(": Permission denied\n", 2);
                else
                    ft_putstr_fd(": No such file or directory\n", 2);
                return (1);
            }
        }
        tmp = tmp->next;
    }
    return (0);
}


int main_excuter(t_minishell *mini)
{
    int nm_cmd;

    nm_cmd = cmd_count(mini->cmd); 
    ft_fdinit(mini);
    if (nm_cmd== 1)
    {
        single_cmd(mini);
        return (1);
    }
    else
    {
        execute_cmds(mini->cmd, mini->env);
        return (1);
    }
}