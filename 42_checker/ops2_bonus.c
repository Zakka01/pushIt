/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:13:33 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/27 20:43:12 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rev_rotate(t_list **h_stack)
{
	t_list	*current;
	t_list	*prev;

	if (!h_stack || !*h_stack || !(*h_stack)->next)
		return ;
	current = *h_stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	add_to_front(h_stack, current);
}

void	rev_rotate_both(t_list **a_stack, t_list **b_stack)
{
	rev_rotate(a_stack);
	rev_rotate(b_stack);
}
