/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:34:31 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:48:36 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			ft_itoa_malloc(char **str, long int ncopy, int size)
{
	if (ncopy < 0)
		*str = malloc(size + 2);
	else
		*str = malloc(size + 1);
}

static char			*ft_itoa_unsigned(unsigned int n)
{
	int				size;
	char			*str;
	long int		ncopy;

	ncopy = n;
	size = ft_nbrlen(n);
	ft_itoa_malloc(&str, ncopy, size);
	if (str == 0)
		return (0);
	str[size--] = '\0';
	if (ncopy == 0)
		str[size] = '0';
	while (ncopy)
	{
		str[size--] = ncopy % 10 + '0';
		ncopy = ncopy / 10;
	}
	return (str);
}

int					ft_print_u(t_lst *lst)
{
	int				width;
	char			*str;
	unsigned int	s;
	int				n;

	s = va_arg(lst->args, unsigned int);
	str = ft_itoa_unsigned(s);
	if (s == 0 && lst->accuracy > -1)
		*str = 0;
	n = ft_strlen(str);
	if (lst->accuracy >= n)
	{
		n = lst->accuracy;
		if (s < 0)
			n++;
	}
	width = lst->width > n ? lst->width : n;
	if (lst->flag_minus)
		ft_print_i_minus(n, width, str);
	else if (lst->flag_zero && lst->accuracy == -1)
		ft_print_i_zero(n, width, str);
	else
		ft_print_i_none(n, width, str);
	free(str);
	return (width);
}
