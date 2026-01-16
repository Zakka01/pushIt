/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:24:07 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/16 15:56:17 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap(n_list **h_stack)
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
}

void    swap_both(n_list **a_stack, n_list **b_stack)
{
    swap(a_stack);
    swap(b_stack);
}

void    push(n_list **src_stack, n_list **dst_stack)
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
}

void    rotate(n_list **h_stack)
{
    n_list *head;

    if (!h_stack || !*h_stack || !(*h_stack)->next)
        return;
    head = *h_stack;
    *h_stack = head->next;
    head->next = NULL;
    add_to_back(h_stack, head);
}

void    rotate_both(n_list **a_stack, n_list **b_stack)
{
    rotate(a_stack);
    rotate(b_stack);
    write(1, "rr\n", 3);
}

void    rev_rotate(n_list **h_stack)
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
}

void    rev_rotate_both(n_list  **a_stack, n_list   **b_stack)
{
    rev_rotate(a_stack);
    rev_rotate(b_stack);
}
