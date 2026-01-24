/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:06:02 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/24 15:56:48 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (ac >= 2)
	{
		i = 1;
		while (ac > i)
		{
			if (!parse_create_list(av[i], &a_head))
				return (write(2, "Error\n", 6), free_stack(&a_head), 0);
			i++;
		}
		if (!check_dup(a_head))
			return (write(2, "Error\n", 6), free_stack(&a_head), 0);
		handle_list_size(&a_head, &b_head);
	}
	free_stack(&a_head);
	free_stack(&b_head);
	return (0);
}
