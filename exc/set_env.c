/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:54:12 by alaaouar          #+#    #+#             */
/*   Updated: 2024/11/16 03:05:37 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	convert_path_to_arr_norm(t_env *tmp, char **paths, int *i)
{
	char	*temp;

	while (tmp)
	{
		if (tmp->value)
		{
			temp = ft_strjoin(tmp->key, "=");
			temp = ft_strjoin_free(temp, tmp->value, 1);
			paths[(*i)] = ft_strdup(temp);
			// free
			*i += 1;
		}
		tmp = tmp->next;
	}
}

char	**convert_path_to_array(t_env *env)
{
	char	**paths;
	t_env	*tmp;
	int		i;

	tmp = env;
	i = get_size(tmp);
	paths = (char **)ft_malloc(sizeof(char *) * (i + 1));
	if (!paths)
		return (NULL);
	tmp = env;
	i = 0;
	convert_path_to_arr_norm(tmp, paths, &i);
	paths[i] = NULL;
	return (paths);
}

t_env	*set_env(char **env)
{
	t_env	*head;
	t_env	*new;
	t_env	*last;
	int		i;

	if (!env || !env[0])
		return (NULL);
	i = 0;
	head = NULL;
	while (env[i])
	{
		new = ft_malloc(sizeof(t_env));
		if (!new)
			return (free_env(head), NULL);
		if (copy_env(env[i], new))
			return (free_env(head), NULL);
		new->next = NULL;
		if (!head)
			head = new;
		else
			last->next = new;
		last = new;
		i++;
	}
	return (head);
}
void    ft_free(void *ptr)
{
    free(ptr);
    ptr = NULL;
}

void	free_env(t_env *head)
{
	t_env	*current;
	t_env	*next;

	current = head;
	while (current)
	{
		next = current->next;
		if (current->key)
		{
			ft_free(current->key);
			current->key = NULL;
		}
		if (current->value)
		{
			ft_free(current->value);
			current->value = NULL;
		}
		if (current)
		{
			ft_free(current);
			current = NULL;
		}
		current = next;
	}
	current = NULL;
}

void	*ft_malloc(size_t size)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		return (NULL);
	return (allocated);
}

int	copy_env(char *env, t_env *new)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (env[i] && env[i] != '=')
		i++;
	new->key = ft_malloc(sizeof(char) * (i + 1));
	if (!new->key)
		return (1);
	new->value = ft_malloc(sizeof(char) * (ft_strlen(env) - i));
	if (!new->value)
		return (ft_free(new->key), 1);
	while (++j < i)
		new->key[j] = env[j];
	new->key[i++] = '\0';
	j = 0;
	while (env[i])
		new->value[j++] = env[i++];
	new->value[j] = '\0';
	return (0);
}