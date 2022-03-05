/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:15:56 by amaribel          #+#    #+#             */
/*   Updated: 2021/10/23 00:00:21 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen1(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_counter(char *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	**ft_free(char **words)
{
	int	j;

	j = 0;
	while (words[j])
	{
		free(words[j]);
		j++;
	}
	free(words);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**words;

	j = 0;
	if (!s)
		return (0);
	words = (char **)malloc((sizeof(char *) * (ft_counter((char *)s, c) + 1)));
	if (!words)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			words[j] = ft_substr((char *)s, 0, ft_strlen1((char *)s, c));
			if (!words[j])
				ft_free(words);
			j++;
		}
		s = s + ft_strlen1((char *)s, c);
	}
	words[j] = 0;
	return (words);
}
