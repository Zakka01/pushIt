/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:24:07 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/15 20:23:28 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap(n_list **h_stack, char w_stack)
{
    n_list *first;
    n_list *second;
    n_list *third;

    first = *h_stack;
    second = first->next;
    third = second->next;

    second->next = first;
    first->next = third;
    *h_stack = second;

    if (w_stack == 'a')
        write(1, "sa\n", 3);
    if (w_stack == 'b')
        write(1, "sb\n", 3);
}

void    swap_both(n_list **a_stack, n_list **b_stack)
{
    swap(a_stack, 'a');
    swap(b_stack, 'b');
    write(1, "ss\n", 3);
}

void    push(n_list **src_stack, n_list **dst_stack, char w_stack)
{
    n_list *src_head;
    n_list *dst_head;

    if (!src_stack || !*src_stack)
        return;

    src_head = *src_stack;
    dst_head = *dst_stack;
    *src_stack = src_head->next;
    src_head->next = dst_head;
    *dst_stack = src_head;
    if (w_stack == 'a')
        write(1, "pa\n", 3);
    if (w_stack == 'b')
        write(1, "pb\n", 3);
}

void    rotate(n_list **h_stack, char w_stack)
{
    n_list *head;

    if (!h_stack || !*h_stack || !(*h_stack)->next)
        return;
    head = *h_stack;
    *h_stack = head->next;
    head->next = NULL;
    add_to_back(h_stack, head);

    if (w_stack == 'a')
        write(1, "ra\n", 3);
    if (w_stack == 'b')
        write(1, "rb\n", 3);
}

void    rotate_both(n_list **a_stack, n_list **b_stack)
{
    rotate(a_stack, 'a');
    rotate(b_stack, 'b');
    write(1, "rr\n", 3);
}

void    rev_rotate(n_list **h_stack, char w_stack)
{   
    n_list *current;
    n_list *prev;

    if (!h_stack || !*h_stack || !(*h_stack)->next)
        return;
    current = *h_stack;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    add_to_front(h_stack, current);
    if (w_stack == 'a')
        write(1, "rra\n", 4);
    if (w_stack == 'b')
        write(1, "rrb\n", 4);
}

void    rev_rotate_both(n_list  **a_stack, n_list   **b_stack)
{
    rev_rotate(a_stack, 'a');
    rev_rotate(b_stack, 'b');
    write(1, "rrr\n", 4);
}
