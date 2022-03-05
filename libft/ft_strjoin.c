/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:13:21 by amaribel          #+#    #+#             */
/*   Updated: 2021/10/21 12:01:27 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	z;

	if (!s1)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	i = 0;
	j = 0;
	z = 0;
	while (i < ft_strlen(s1) && s1[i])
		dest[z++] = s1[i++];
	while (j < (ft_strlen(s1) + ft_strlen(s2)) && s2[j])
		dest[z++] = s2[j++];
	dest[z] = '\0';
	return (dest);
}
