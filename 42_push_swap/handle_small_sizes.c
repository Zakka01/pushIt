/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_sizes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:23:03 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/22 18:23:18 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_list_size(t_list **a_stack, t_list **b_stack)
{
	int	size;

	size = list_size(*a_stack);
	if (size == 1)
		return ;
	else if (size == 2)
		size_of_two(a_stack);
	else if (size == 3)
		size_of_three(a_stack);
	else if ((size == 4 || size == 5) && !is_sorted(a_stack))
		size_of_f(a_stack, b_stack, size);
	else if (size > 5 && !is_sorted(a_stack))
		chunks_sort(a_stack, b_stack, size);
}
