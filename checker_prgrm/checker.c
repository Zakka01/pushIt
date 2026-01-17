/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:12:09 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/16 16:46:58 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    free_stack(n_list **stack)
{
    n_list *current;
    n_list *tmp;

    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}

void    apply_valid_move(char *line, n_list **a_stack, n_list **b_stack)
{
    if (validate_line(line))
    {
        if (is_move(line, "sa\n"))
            swap(a_stack);
        else if (is_move(line, "sb\n"))
            swap(b_stack);
        else if (is_move(line, "ss\n"))
            swap_both(a_stack, b_stack);
        else if (is_move(line, "ra\n"))
            rotate(a_stack);
        else if (is_move(line, "rb\n"))
            rotate(b_stack);
        else if (is_move(line, "rr\n"))
            rotate_both(a_stack, b_stack);
        else if (is_move(line, "pa\n"))
            push(b_stack, a_stack);
        else if (is_move(line, "pb\n"))
            push(a_stack, b_stack);
        else if (is_move(line, "rra\n"))
            rev_rotate(a_stack);
        else if (is_move(line, "rrb\n"))
            rev_rotate(b_stack);
        else if (is_move(line, "rrr\n"))
            rev_rotate_both(a_stack, b_stack);
    }
}

void    check_ok(n_list **a_stack, n_list **b_stack)
{
    if (is_sorted(a_stack) && *b_stack == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

void    extra(n_list **a_stack, n_list **b_stack)
{
    char *line;
    
    while ((line = get_line(0)))
    {
        if (!validate_line(line))
        {
            write(2, "Error\n", 6);
            free(line);
            free_stack(a_stack);
            free_stack(b_stack);
            return;
        }
        apply_valid_move(line, a_stack, b_stack);
        free(line);
    }
    check_ok(a_stack, b_stack);
}

int main(int ac, char **av)
{
    int i;
    n_list *a_head;
    n_list *b_head;

    a_head = NULL;
    b_head = NULL;
    if (ac >= 2)
    {
        i = 1;
        while (ac > i)
        {
            if (!parse_create_list(av[i], &a_head))
                return (write(1, "Error\n", 6), free_stack(&a_head), 0);
            i++;
        }
        if (!check_dup(a_head))
            return (write(1, "Error\n", 6), free_stack(&a_head), 0);
    }
    extra(&a_head, &b_head);
    free_stack(&a_head);
    free_stack(&b_head);
    return (0);
}
