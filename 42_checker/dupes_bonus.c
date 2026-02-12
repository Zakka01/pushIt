/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:17:32 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/27 20:43:00 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_dup(t_list *a_head)
{
	t_list	*this_num;
	t_list	*next_num;

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
