/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:28:14 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:28:31 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char *s, int len, int fd)
{
	if (fd != -1 && s)
		while (*s != '\0' && len)
		{
			write(fd, s++, 1);
			len--;
		}
}
