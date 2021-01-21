/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:36:42 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:47:08 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_print_i_minus(int n, int width, char *s)
{
	int			len;

	len = ft_strlen(s);
	width -= n;
	if (s[0] == '-')
		ft_putchar(*s++);
	while (n-- > len)
		ft_putchar('0');
	while (len-- && *s != '\0')
		ft_putchar(*s++);
	while (width--)
		ft_putchar(' ');
}

void			ft_print_i_zero(int n, int width, char *s)
{
	int			len;

	len = ft_strlen(s);
	width -= n;
	if (s[0] == '-')
		ft_putchar(*s++);
	while (width--)
		ft_putchar('0');
	while (n-- > len)
		ft_putchar('0');
	while (len-- && *s != '\0')
		ft_putchar(*s++);
}

void			ft_print_i_none(int n, int width, char *s)
{
	int			len;

	len = ft_strlen(s);
	width -= n;
	while (width--)
		ft_putchar(' ');
	if (s[0] == '-')
		ft_putchar(*s++);
	while (n-- > len)
		ft_putchar('0');
	while (len-- && *s != '\0')
		ft_putchar(*s++);
}

int				ft_print_i(t_lst *lst)
{
	int			width;
	char		*str;
	int			s;
	int			n;

	s = va_arg(lst->args, int);
	str = ft_itoa(s);
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
