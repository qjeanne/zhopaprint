/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:35:47 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:35:49 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_print_s_minus(int n, int width, char *s)
{
	width -= n;
	if (!s)
		ft_putstr_len("(null)", n, 1);
	else
	{
		while (n--)
			ft_putchar(*s++);
	}
	while (width-- > 0)
		ft_putchar(' ');
}

static void		ft_print_s_zero(int n, int width, char *s)
{
	width -= n;
	while (width-- > 0)
		ft_putchar('0');
	if (!s)
		ft_putstr_len("(null)", n, 1);
	else
	{
		while (n-- > 0)
			ft_putchar(*s++);
	}
}

static void		ft_print_s_none(int n, int width, char *s)
{
	width -= n;
	while (width--)
		ft_putchar(' ');
	if (!s)
		ft_putstr_len("(null)", n, 1);
	else
	{
		while (n-- > 0)
			ft_putchar(*s++);
	}
}

int				ft_print_s(t_lst *lst)
{
	int			width;
	char		*s;
	int			n;
	int			len;

	s = va_arg(lst->args, char *);
	len = ft_strlen(s);
	if (!s)
		len = 6;
	if (lst->accuracy == -1)
		n = len;
	else
		n = ft_min(len, lst->accuracy);
	if (lst->width > n)
		width = lst->width;
	else
		width = n;
	if (lst->flag_minus)
		ft_print_s_minus(n, width, s);
	else if (lst->flag_zero)
		ft_print_s_zero(n, width, s);
	else
		ft_print_s_none(n, width, s);
	return (width);
}
