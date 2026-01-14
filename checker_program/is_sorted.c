/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:16:50 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/14 19:16:59 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int is_sorted(n_list    **a_stack)
{
    n_list  *current;
    int is_sorted = 1;

    current = *a_stack;
    while (current->next)
    {
        if (current->data > current->next->data)
            is_sorted = -1;
        current = current->next;
    }
    if (is_sorted == -1)
        return (0);
    return (1);
}