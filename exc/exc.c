/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:14:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/16 22:03:28 by alaaouar         ###   ########.fr       */
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

void fill_data_hold(t_minishell *mini)
{
    data_hold()->line = mini->line; 
    data_hold()->env = mini->env;
    data_hold()->lexer = mini->lexer;
    data_hold()->cmd = mini->cmd;
    data_hold()->exc = mini->exc;
}

void print_data_hold(void)
{
    t_minishell *mini = data_hold();

    if (mini == NULL)
    {
        printf("data_hold is NULL\n");
        return;
    }

    printf("line: %s\n", mini->line ? mini->line : "NULL");
    if (mini->env)
    {
        printf("env:\n");
        for (char **env = mini->env; *env != NULL; env++)
        {
            printf("  %s\n", *env);
        }
    }
    else
    {
        printf("env: NULL\n");
    }
    printf("lexer: %p\n", (void *)mini->lexer);
    printf("cmd: %p\n", (void *)mini->cmd);
    printf("exc: %p\n", (void *)mini->exc);
}

int main_excuter(t_minishell *mini)
{
    fill_data_hold(mini);
    print_data_hold();
    if ((mini->exc->num_cmds = cmd_count(mini->cmd)) == 1)
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

t_minishell *data_hold(void)
{
    static t_minishell *mini = NULL;

    if (!mini)
        mini = malloc(sizeof(t_minishell));
    return (mini);
}
