/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:36:48 by omanar            #+#    #+#             */
/*   Updated: 2024/02/02 00:38:06 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i <= (end - 1))
		i++;
	while (ft_strchr(set, s1[end - 1]) && i <= (end - 1))
		end--;
	p = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, (char *)s1 + i, (end - i + 1));
	return (p);
}
