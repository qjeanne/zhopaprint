/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:04:30 by tjohnnie          #+#    #+#             */
/*   Updated: 2021/01/20 22:05:54 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"

typedef struct		s_lst
{
	int				flag_minus;
	int				flag_zero;
	int				width;
	int				accuracy;
	char			type;
	va_list			args;
}					t_lst;

int					ft_printf(const char *format, ...);
const char			*ft_get_flags(const char *str, t_lst *lst);
const char			*ft_get_width(const char *str, t_lst *lst);
const char			*ft_get_accuracy(const char *str, t_lst *lst);
const char			*ft_get_type(const char *str, t_lst *lst);
int					ft_print_s(t_lst *lst);
int					ft_print_c(t_lst *lst);
int					ft_print_p(t_lst *lst);
int					ft_print_prcnt(t_lst *lst);
int					ft_print_i(t_lst *lst);
int					ft_print_x(t_lst *lst);
void				ft_print_c_minus(int width, char s);
void				ft_print_c_zero(int width, char s);
void				ft_print_c_none(int width, char s);
void				ft_print_i_minus(int n, int width, char *s);
void				ft_print_i_zero(int n, int width, char *s);
void				ft_print_i_none(int n, int width, char *s);
char				*ft_itoa_base(long int value, int base);
void				ft_putstr_len(char *s, int len, int fd);
int					ft_print_u(t_lst *lst);

#endif
