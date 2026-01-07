/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:41 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/07 21:25:01 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if there is a duplicated numbers
int check_dup(n_list *a_head)
{
    n_list *this_num;
    n_list *next_num;

    if (!a_head)
        return (0);
    this_num = a_head;
    while (this_num)
    {
        next_num = this_num->next;
        while (next_num)
        {
            if (this_num->data == next_num->data)
                return (0);
            next_num = next_num->next;
        }
        this_num = this_num->next;
    }
    return (1);
}
