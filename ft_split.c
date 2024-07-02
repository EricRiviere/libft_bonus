/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:42:25 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/25 08:43:12 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter ++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (counter);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **arr)
{
	while (i > 0)
	{
		i --;
		free (arr[i]);
	}
	free(arr);
}

static char	**split(char const *s, char c, char **arr, size_t w_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < w_count)
	{
		while (s[j] && s[j] == c)
			j++;
		arr[i] = ft_substr(s, j, get_word_len(&s[j], c));
		if (!arr[i])
		{
			free_array(i, arr);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = split(s, c, arr, words);
	return (arr);
}
