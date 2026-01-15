/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:05:53 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/14 18:20:23 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_space(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

int count_words(char *s)
{
    int i = 0;
    int count = 0;
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
    int j;

    j = 0;
	while (arr[j])
	{
		free(arr[j]);
        j++;
	}
	free(arr);
}

int fill_words(char *s, char **arr, int len)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = 0;
    char *word;

    while (i < len)
    {
        while (s[start] && is_space(s[start]))
            start++;
        end = start;
        while (s[end] && !is_space(s[end]))
            end++;
        word = malloc(end - start + 1);
        if (!word)
            return (0);
        j = 0;
        while (start < end)
            word[j++] = s[start++];
        word[j] = '\0';
        arr[i] = word;
        i++;
    }
    return (1);
}

char **ft_split(char *str)
{
    char **arr = NULL;
    int len;

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
