/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:51 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/13 20:32:00 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void size_of_two(n_list **a_stack)
{
    if ((*a_stack)->data > (*a_stack)->next->data)
        swap(a_stack, 'a');
}

void size_of_three(n_list **a_stack)
{
    n_list *first;
    n_list *second;
    n_list *third;

    first = *a_stack;
    second = first->next;
    third = second->next;

    if (first->data > second->data && second->data < third->data && third->data > first->data)
        swap(a_stack, 'a');
    else if (first->data > second->data && second->data < third->data && third->data < first->data)
        rotate(a_stack, 'a');
    else if (first->data < second->data && second->data > third->data && third->data < first->data)
        rev_rotate(a_stack, 'a');
    else if (first->data > second->data && second->data > third->data && third->data < first->data)
    {
        swap(a_stack, 'a');
        rev_rotate(a_stack, 'a');
    }
    else if (first->data < second->data && second->data > third->data && third->data > first->data)
    {
        swap(a_stack, 'a');
        rotate(a_stack, 'a');
    }
}

void find_push_min(n_list **a_stack, n_list **b_stack)
{
    n_list *currect;
    int i;
    int min;
    int index;

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
    while (index > 0)
    {
        rotate(a_stack, 'a');
        index--;
    }
    if (!is_sorted(a_stack))
        push(a_stack, b_stack, 'b');
}

void size_of_f(n_list **a_stack, n_list **b_stack, int size)
{
    int pushes;

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

void handle_list_size(n_list **a_stack, n_list **b_stack)
{
    int size;

    size = list_size(*a_stack);
    if (size == 1)
        return;
    else if (size == 2)
        size_of_two(a_stack);
    else if (size == 3)
        size_of_three(a_stack);
    else if ((size == 4 || size == 5) && !is_sorted(a_stack))
        size_of_f(a_stack, b_stack, size);
    else if (size > 5 && !is_sorted(a_stack))
        chunks_sort(a_stack, b_stack, size);
}