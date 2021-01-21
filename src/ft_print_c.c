/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:32:42 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:32:44 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_print_c_minus(int width, char s)
{
	width -= 1;
	ft_putchar(s);
	while (width--)
		ft_putchar(' ');
}

void			ft_print_c_zero(int width, char s)
{
	while (width - 1)
	{
		ft_putchar('0');
		width--;
	}
	ft_putchar(s);
}

void			ft_print_c_none(int width, char s)
{
	while (width - 1)
	{
		ft_putchar(' ');
		width--;
	}
	ft_putchar(s);
}

int				ft_print_c(t_lst *lst)
{
	int			width;
	char		s;
	int			n;

	s = va_arg(lst->args, int);
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
