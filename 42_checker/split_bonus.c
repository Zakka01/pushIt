/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:33 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/18 00:15:40 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	count_words(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_space(s[i]) && (is_space(s[i + 1]) || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	free_all_space(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

int	fill_words(char *s, char **arr, int len)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < len)
	{
		while (s[start] && is_space(s[start]))
			start++;
		end = start;
		while (s[end] && !is_space(s[end]))
			end++;
		arr[i] = malloc(end - start + 1);
		if (!arr[i])
			return (0);
		j = 0;
		while (start < end)
			arr[i][j++] = s[start++];
		arr[i][j] = '\0';
		i++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		len;

	arr = NULL;
	if (!str || !*str)
		return (NULL);
	len = count_words(str);
	if (len == 0)
		return (NULL);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_words(str, arr, len))
	{
		free_all_space(arr);
		return (NULL);
	}
	arr[len] = NULL;
	return (arr);
}
