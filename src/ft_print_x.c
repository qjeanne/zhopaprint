/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:33:37 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:48:23 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			*ft_toup(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int					ft_print_x(t_lst *lst)
{
	int				width;
	unsigned int	s;
	char			*str;
	int				n;

	s = va_arg(lst->args, unsigned int);
	str = ft_itoa_base(s, 16);
	if (s == 0 && lst->accuracy > -1)
		*str = 0;
	n = ft_strlen(str);
	if (lst->type == 'X')
		str = ft_toup(str);
	if (lst->accuracy > n)
		n = lst->accuracy;
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
