/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:15:06 by anonymou          #+#    #+#             */
/*   Updated: 2018/01/18 10:44:45 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*ft_dstr(int d, t_struct *para)
{
	char	*dstr;

	d < 0 ? para->less = 1 : 0;
	d < 0 ? (d = d * -1) : 0;
	d == -2147483648 ? (d = 2147483647) && (para->d++) : 0;
	d == -2147483648 ? (para->t_d = 2147483647) : 0;
	d != -2147483648 ? (para->t_d = d) : 0;
	while (para->t_d > 9)
	{
		para->t_d /= 10;
		para->len++;
	}
	dstr = ft_strnew((size_t)para->len + 1);
	while (para->len > 0)
	{
		para->less == 1 ? dstr[para->len + 1] = (d % 10) + '0' : 0;
		para->less != 1 ? (dstr[para->len] = (d % 10) + '0') : 0;
		d /= 10;
		para->len--;
	}
	para->less == 1 ? dstr[para->len + 1] = d + '0' : 0;
	para->less != 1 ? (dstr[para->len] = d + '0') : 0;
	para->less == 1 ? dstr[para->len] = '-' : 0;
	para->d == 1 ? dstr[10] = '8' : 0;
	return (dstr);
}

static char			*ft_dstrz(ssize_t d, t_struct *para)
{
	char		*dstr;
	ssize_t		t_d;

	d == -4594967295 ? t_d = 4594967294 : 0;
	d == -4594967295 ? (d = 4594967294) && (para->d++) : 0;
	d != -4594967295 ? t_d = d : 0;
	while (t_d > 9)
	{
		t_d /= 10;
		para->len++;
	}
	dstr = ft_strnew((size_t)para->len + 1);
	while (para->len > 0)
	{
		para->less == 1 ? dstr[para->len + 1] = (d % 10) + '0' : 0;
		para->less != 1 ? dstr[para->len] = (d % 10) + '0' : 0;
		d /= 10;
		para->len--;
	}
	para->less == 1 ? dstr[para->len + 1] = d + '0' : 0;
	para->less != 1 ? dstr[para->len] = d + '0' : 0;
	para->less == 1 ? dstr[para->len] = '-' : 0;
	para->d == 1 ? dstr[10] = '5' : 0;
	return (dstr);
}

void				ft_d(t_struct *para, char *d)
{
	int		len;

	para->d_ != -1 && d[0] == '0' ? d[0] = '\0' : 0;
	para->p_ == 0 && para->s_ == 1 && d[0] != '-' && para->d_ == -1 ?
	ft_putchar(' ') : 0;
	para->p_ == 0 && para->s_ == 1 && d[0] != '-' && para->d_ == -1 ?
	para->res++ : 0;
	para->p_ == 1 && (para->nbr == -1 || para->l_ == 1) && d[0] != '-' &&
	para->d_ == -1 ? ft_putchar('+') : 0;
	para->p_ == 1 && (para->nbr == -1 || para->l_ == 1) && d[0] != '-' &&
	para->d_ == -1 ? para->res++ : 0;
	len = ft_strlen(d);
	if (para->d_ != -1)
		d = ft_flags_dot_int(d, len, para);
	para->d_ > para->nbr ? para->nbr = -1 : 0;
	len = ft_strlen(d);
	para->nbr != -1 && para->l_ == 0 ?
	d = ft_flags_height_int(d, len, para) : 0;
	para->l_ == 1 ? d = ft_flags_less(d, len, para) : 0;
	para->res += ft_strlen(d);
	ft_putstr(d);
}

void				ft_d_main(t_struct *para, va_list args)
{
	char	*d;

	para->f_one == '\0' && para->chara == 'd' ?
	d = ft_dstr(va_arg(args, int), para) : 0;
	if (para->f_one == 'l' || para->chara == 'D' || para->chara == 'I')
	{
		para->f_two == '\0' ? d = ft_dstrl(va_arg(args, long), para) : 0;
		para->f_two == 'l' ? d = ft_dstrll(va_arg(args, long long), para) : 0;
	}
	if (para->f_one == 'h')
	{
		para->f_two == '\0' ? d = ft_dstrh((short)va_arg(args, int), para) : 0;
		para->f_two == 'h' ? d = ft_dstrhh((char)va_arg(args, int), para) : 0;
	}
	para->f_one == 'j' ? d = ft_dstrll(va_arg(args, intmax_t), para) : 0;
	para->f_one == 'z' ? d = ft_dstrz(va_arg(args, ssize_t), para) : 0;
	ft_d(para, d);
}
