/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:51 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/23 19:08:58 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_of_two(t_list **a_stack)
{
	if ((*a_stack)->data > (*a_stack)->next->data)
		swap(a_stack, 'a');
}

void	size_of_three(t_list **a_stack)
{
	int	first;
	int	second;
	int	third;

	first = (*a_stack)->data;
	second = (*a_stack)->next->data;
	third = (*a_stack)->next->next->data;
	if (first > second && second < third && third > first)
		swap(a_stack, 'a');
	else if (first > second && second < third && third < first)
		rotate(a_stack, 'a');
	else if (first < second && second > third && third < first)
		rev_rotate(a_stack, 'a');
	else if (first > second && second > third && third < first)
	{
		swap(a_stack, 'a');
		rev_rotate(a_stack, 'a');
	}
	else if (first < second && second > third && third > first)
	{
		swap(a_stack, 'a');
		rotate(a_stack, 'a');
	}
}

void	bring_min_to_top(t_list **a_stack, int index)
{
	int		a_size;
	int		times;

	a_size = list_size(*a_stack);
	if (index <= a_size / 2)
	{
		while (index-- > 0)
			rotate(a_stack, 'a');
	}
	else
	{
		times = a_size - index;
		while (times-- > 0)
			rev_rotate(a_stack, 'a');
	}
}

void	find_push_min(t_list **a_stack, t_list **b_stack)
{
	t_list	*currect;
	int		i;
	int		min;
	int		index;

	currect = *a_stack;
	i = 0;
	index = 0;
	min = currect->data;
	while (currect)
	{
		if (currect->data < min)
		{
			min = currect->data;
			index = i;
		}
		currect = currect->next;
		i++;
	}
	bring_min_to_top(a_stack, index);
	if (!is_sorted(a_stack))
		push(a_stack, b_stack, 'b');
}

void	size_of_f(t_list **a_stack, t_list **b_stack, int size)
{
	int	pushes;

	pushes = size - 3;
	while (pushes > 0)
	{
		find_push_min(a_stack, b_stack);
		pushes--;
	}
	size_of_three(a_stack);
	while (*b_stack)
		push(b_stack, a_stack, 'a');
}
