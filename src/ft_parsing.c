/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:37:33 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 21:37:35 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char		*ft_get_flags(const char *str, t_lst *lst)
{
	while (str)
	{
		if (*str == '-')
			lst->flag_minus = 1;
		else if (*str == '0')
			lst->flag_zero = 1;
		else
			return (str);
		str++;
	}
	return (str);
}

const char		*ft_get_width(const char *str, t_lst *lst)
{
	int			width;

	if (*str == '*')
	{
		width = va_arg(lst->args, int);
		if (width < 0)
		{
			lst->width = -width;
			lst->flag_minus = 1;
		}
		else
			lst->width = width;
		str++;
	}
	else if (ft_isdigit(*str))
	{
		lst->width = ft_atoi(str);
		str += ft_nbrlen(lst->width);
	}
	return (str);
}

const char		*ft_get_accuracy(const char *str, t_lst *lst)
{
	int			accuracy;

	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			accuracy = va_arg(lst->args, int);
			if (accuracy < 0)
				lst->accuracy = -1;
			else
				lst->accuracy = accuracy;
			str++;
		}
		else if (ft_isdigit(*str))
		{
			lst->accuracy = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else
			lst->accuracy = 0;
	}
	return (str);
}

const char		*ft_get_type(const char *str, t_lst *lst)
{
	if (*str == 'c')
		lst->type = 'c';
	else if (*str == 's')
		lst->type = 's';
	else if (*str == 'p')
		lst->type = 'p';
	else if (*str == 'd')
		lst->type = 'd';
	else if (*str == 'i')
		lst->type = 'i';
	else if (*str == 'u')
		lst->type = 'u';
	else if (*str == 'x')
		lst->type = 'x';
	else if (*str == 'X')
		lst->type = 'X';
	else if (*str == '%')
		lst->type = '%';
	else
		str--;
	return (++str);
}
