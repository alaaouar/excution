// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/13 21:07:39 by alaaouar          #+#    #+#             */
// /*   Updated: 2024/11/14 01:42:45 by alaaouar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../include/minishell.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// t_env	*copy_env_list(t_env *env)
// {
// 	t_env	*tmp;
// 	t_env	*new;
// 	t_env	*head;

// 	tmp = env;
// 	head = NULL;
// 	while (tmp)
// 	{
// 		new = ft_malloc(sizeof(t_env));
// 		if (!new)
// 			return (NULL);
// 		new->key = ft_strdup(tmp->key);
// 		new->value = ft_strdup(tmp->value);
// 		new->next = NULL;
// 		if (!head)
// 			head = new;
// 		else
// 		{
// 			new->next = head;
// 			head = new;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (head);
// }

// void	sort_env_list(t_env *env)
// {
// 	t_env	*tmp;
// 	t_env	*tmp2;
// 	char	*temp;

// 	tmp = env;
// 	while (tmp)
// 	{
// 		tmp2 = tmp->next;
// 		while (tmp2)
// 		{
// 			if (ft_strcmp(tmp->key, tmp2->key) > 0)
// 			{
// 				temp = tmp->key;
// 				tmp->key = tmp2->key;
// 				tmp2->key = temp;
// 				temp = tmp->value;
// 				tmp->value = tmp2->value;
// 				tmp2->value = temp;
// 			}
// 			tmp2 = tmp2->next;
// 		}
// 		tmp = tmp->next;
// 	}
// }
// void	print_export_list(t_env *env)
// {
// 	t_env	*tmp;
// 	t_env	*to_free;

// 	tmp = copy_env_list(env);
// 	if (!tmp)
// 		return ;
// 	sort_env_list(tmp);
// 	to_free = tmp;
// 	while (tmp)
// 	{
// 		ft_putstr_fd("declare -x ", 1);
// 		ft_putstr_fd(tmp->key, 1);
// 		if (tmp->value)
// 		{
// 			ft_putstr_fd("=\"", 1);
// 			ft_putstr_fd(tmp->value, 1);
// 			ft_putchar_fd('\"', 1);
// 		}
// 		ft_putchar_fd('\n', 1);
// 		tmp = tmp->next;
// 	}
// 	free_env(to_free);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = ft_strlen(s);
// 	if (c == 0)
// 		return ((char *)(s + j));
// 	while (i <= j)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	src_len;
// 	size_t	length;

// 	length = 0;
// 	if (!s)
// 		return (NULL);
// 	src_len = ft_strlen(s);
// 	if (start >= src_len)
// 		return (ft_strdup(""));
// 	if (start < src_len)
// 		length = src_len - start;
// 	if (length > len)
// 		length = len;
// 	sub = ft_malloc(sizeof(char) * (length + 1));
// 	if (!sub)
// 		return (NULL);
// 	// ft_strlcpy(sub, s + start, length + 1);
// 	return (sub);
// }

// int	key_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && (str[i] != '=' && !(str[i] == '+' && str[i + 1] == '=')))
// 		i++;
// 	return (i);
// }

// void	export_args_handle(t_cmd *cmd, char *key, char *value)
// {
// 	int	i;

// 	i = 1;
// 	while (cmd->av[i])
// 	{
// 		if (ft_strchr(cmd->av[i], '='))
// 		{
// 			value = ft_strchr(cmd->av[i], '=') + 1;
// 			key = ft_substr(cmd->av[i], 0, key_len(cmd->av[i]));
// 			if (export_error_display(cmd, key, value, &i))
// 				continue ;
// 		}
// 		else if (export_null(&i, cmd))
// 			continue ;
// 		i++;
// 		ft_free(key);
// 	}
// }

void    minishell_export(t_cmd *cmd, t_env *env)
{
	// char	*key;
	// char	*value;

    (void)cmd;
    (void)env;
	// key = NULL;
	// value = NULL;
    // if (cmd->ac == 1)
	// 	print_export_list(env);
	// else
	// 	export_args_handle(cmd, key, value);
}
