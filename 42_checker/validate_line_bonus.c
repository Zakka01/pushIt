/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:46:44 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/25 19:10:23 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_move(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (str1[i] == '\0' && str2[i] == '\0');
}

int	validate_line(char *line)
{
	if (!line)
		return (0);
	if ((is_move(line, "sa\n")) || (is_move(line, "sb\n")) 
		|| (is_move(line, "ss\n")))
		return (1);
	else if ((is_move(line, "pa\n")) || (is_move(line, "pb\n")))
		return (1);
	else if ((is_move(line, "ra\n")) || (is_move(line, "rb\n"))
		|| (is_move(line, "rr\n")))
		return (1);
	else if ((is_move(line, "rra\n")) || (is_move(line, "rrb\n"))
		|| (is_move(line, "rrr\n")))
		return (1);
	else
		return (0);
}
