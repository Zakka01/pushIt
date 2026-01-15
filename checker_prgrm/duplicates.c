/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:17:32 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/14 19:17:42 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
