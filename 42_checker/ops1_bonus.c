/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:24:07 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/27 20:43:10 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_list **h_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *h_stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*h_stack = second;
}

void	swap_both(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
}

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*src_head;
	t_list	*dst_head;

	if (!src_stack || !*src_stack)
		return ;
	src_head = *src_stack;
	dst_head = *dst_stack;
	*src_stack = src_head->next;
	src_head->next = dst_head;
	*dst_stack = src_head;
}

void	rotate(t_list **h_stack)
{
	t_list	*head;

	if (!h_stack || !*h_stack || !(*h_stack)->next)
		return ;
	head = *h_stack;
	*h_stack = head->next;
	head->next = NULL;
	add_to_back(h_stack, head);
}

void	rotate_both(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
