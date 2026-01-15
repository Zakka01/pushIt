/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:06:06 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/14 18:16:56 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

n_list *add_new_node(int content)
{
    n_list *new_node;

    new_node = malloc(sizeof(n_list));
    if (!new_node)
        return (NULL);
    new_node->data = content;
    if (new_node)
        new_node->next = NULL;
    return (new_node);
}

void add_to_back(n_list **list, n_list *node)
{
    n_list *tmp;

    if (!list || !node)
        return;
    node->next = NULL;
    if (!*list)
    {
        *list = node;
        return;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

void add_to_front(n_list **list, n_list *node)
{
    if (!list || !node)
        return;
    node->next = *list;
    *list = node;
}

int list_size(n_list *list)
{
    int size;

    size = 0;

    while (list)
    {
        size++;
        list = list->next;
    }
    return (size);
}

int    parse_create_list(char *arg, n_list **a_head)
{
    n_list  *node;
    char    **numbers;
    int     number;
    int     error;
    int     j;
    
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
