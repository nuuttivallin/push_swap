/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:58:52 by nvallin           #+#    #+#             */
/*   Updated: 2023/11/11 11:27:10 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*new;

	i = 0;
	i2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0')
		i++;
	while (s2[i2] != '\0')
		i2++;
	new = malloc(i + i2 + 1);
	if (!new)
		return (0);
	i = 0;
	while (*s1 != '\0')
		new[i++] = *s1++;
	while (*s2 != '\0')
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
