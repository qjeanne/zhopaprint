/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prcnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:31:14 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:31:29 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_print_prcnt(t_lst *lst)
{
	int			width;
	char		s;
	int			n;

	s = '%';
	n = 1;
	if (lst->width > n)
		width = lst->width;
	else
		width = n;
	if (lst->flag_minus)
		ft_print_c_minus(width, s);
	else if (lst->flag_zero)
		ft_print_c_zero(width, s);
	else
		ft_print_c_none(width, s);
	return (width);
}
