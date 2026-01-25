/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:25:29 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/18 00:14:35 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*add_new_node(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	if (new_node)
		new_node->next = NULL;
	return (new_node);
}

void	add_to_back(t_list **list, t_list *node)
{
	t_list	*tmp;

	if (!list || !node)
		return ;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	add_to_front(t_list **list, t_list *node)
{
	if (!list || !node)
		return ;
	node->next = *list;
	*list = node;
}

int	list_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	parse_create_list(char *arg, t_list **a_head)
{
	t_list	*node;
	char	**numbers;
	int		number;
	int		error;
	int		j;

	numbers = ft_split(arg);
	if (!numbers || !numbers[0])
		return (0);
	j = 0;
	while (numbers[j])
	{
		if (!numbers[j])
			return (free_all_space(numbers), 0);
		number = ft_atoi(numbers[j], &error);
		if (error == -1)
			return (free_all_space(numbers), 0);
		node = add_new_node(number);
		add_to_back(a_head, node);
		j++;
	}
	free_all_space(numbers);
	return (1);
}
