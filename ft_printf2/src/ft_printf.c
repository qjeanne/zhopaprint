/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:39:27 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:42:09 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const char	*ft_parsing(const char *str, t_lst *lst)
{
	str = ft_get_flags(str, lst);
	str = ft_get_width(str, lst);
	str = ft_get_accuracy(str, lst);
	str = ft_get_type(str, lst);
	return (str);
}

static int			ft_print(t_lst *lst)
{
	int				len;

	if (lst->type == 'c')
		len = ft_print_c(lst);
	else if (lst->type == 's')
		len = ft_print_s(lst);
	else if (lst->type == 'p')
		len = ft_print_p(lst);
	else if (lst->type == 'd' || lst->type == 'i')
		len = ft_print_i(lst);
	else if (lst->type == 'u')
		len = ft_print_u(lst);
	else if (lst->type == 'x' || lst->type == 'X')
		len = ft_print_x(lst);
	else if (lst->type == '%')
		len = ft_print_prcnt(lst);
	else
		return (-1);
	return (len);
}

static t_lst		*ft_new_list(void)
{
	t_lst			*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->flag_minus = 0;
	new->flag_zero = 0;
	new->width = 0;
	new->accuracy = -1;
	new->type = 0;
	return (new);
}

static t_lst		*ft_refill(t_lst *new)
{
	if (!new)
		return (0);
	new->flag_minus = 0;
	new->flag_zero = 0;
	new->width = 0;
	new->accuracy = -1;
	new->type = 0;
	return (new);
}

int					ft_printf(const char *str, ...)
{
	t_lst			*lst;
	int				len;

	len = 0;
	lst = ft_new_list();
	va_start(lst->args, str);
	while (*str)
	{
		lst = ft_refill(lst);
		if (*str == '%')
		{
			str = ft_parsing(++str, lst);
			len += ft_print(lst);
		}
		else
		{
			ft_putchar(*str++);
			len++;
		}
	}
	va_end(lst->args);
	free(lst);
	return (len);
}
