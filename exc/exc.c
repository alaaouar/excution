/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:14:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/16 19:20:57 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int cmd_count(t_cmd *cmd)
{
    int count;
    t_cmd *tmp;
    
    count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

int main_excuter(t_minishell *mini)
{
    if ((mini->exc->num_cmds = cmd_count(mini->cmd)) == 1)
    {
        one_command(mini);
        return (1);
    }
    else
    {
        execute_cmds(mini->cmd, mini->env);
        return (1);
    }
}

t_minishell *data_hold(void)
{
    static t_minishell *mini = NULL;

    if (!mini)
        malloc(sizeof(t_minishell));
    return (mini);
}
