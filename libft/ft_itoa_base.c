/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:47:46 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/19 19:49:04 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_realloc(char *str, int k, long int s)
{
	char	*new;

	new = malloc(k + 1);
	new[k] = '\0';
	if (s <= 9)
		new[0] = s + 48;
	else
		new[0] = s + 97 - 10;
	k = 1;
	while (str[k - 1])
	{
		new[k] = str[k - 1];
		k++;
	}
	free(str);
	return (new);
}

char		*ft_itoa_base(long int value, int base)
{
	char	*str;
	int		k;

	k = 0;
	str = malloc(1);
	str[0] = '\0';
	if (!value)
		str = ft_realloc(str, k + 1, 0);
	while (value)
	{
		str = ft_realloc(str, k + 1, value % base);
		value = value / base;
		k++;
	}
	return (str);
}
