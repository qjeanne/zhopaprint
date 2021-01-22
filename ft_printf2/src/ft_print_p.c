/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:35:08 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:35:10 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_print_p_minus(int n, int width, char *s)
{
	int			len;

	len = ft_strlen(s);
	width -= n;
	ft_putchar('0');
	ft_putchar('x');
	n -= 2;
	while (n > len)
	{
		ft_putchar('0');
		n--;
	}
	while (n--)
		ft_putchar(*s++);
	while (width--)
		ft_putchar(' ');
}

static void		ft_print_p_none(int n, int width, char *s)
{
	int			len;

	len = ft_strlen(s);
	width -= n;
	while (width--)
		ft_putchar(' ');
	ft_putchar('0');
	ft_putchar('x');
	n -= 2;
	while (n > len)
	{
		ft_putchar('0');
		n--;
	}
	while (n--)
		ft_putchar(*s++);
}

int				ft_print_p(t_lst *lst)
{
	int			width;
	long		s;
	char		*str;
	int			n;

	s = va_arg(lst->args, long);
	str = ft_itoa_base(s, 16);
	if (!s && lst->accuracy != -1)
		str = 0;
	n = ft_strlen(str) + 2;
	if (lst->accuracy > n - 2)
		n = lst->accuracy + 2;
	if (lst->width > n)
		width = lst->width;
	else
		width = n;
	if (lst->flag_minus)
		ft_print_p_minus(n, width, str);
	else
		ft_print_p_none(n, width, str);
	free(str);
	return (width);
}
