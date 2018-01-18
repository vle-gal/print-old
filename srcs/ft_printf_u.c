/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:03:45 by vle-gal           #+#    #+#             */
/*   Updated: 2017/11/22 19:46:00 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_ustr(int d)
{
	char			*dstr;
	int				len;
	unsigned int	len_n;
	unsigned int	less;

	d < 0 ? less = 4294967295u + (d + 1) : 0;
	d >= 0 ? (less = d) : 0;
	len = 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	return (dstr);
}

static char		*ft_ustrl(long d, t_struct *para)
{
	char			*dstr;
	int				len;
	unsigned long	len_n;
	unsigned long	less;

	d < 0 ? less = 18446744073709551615u + (d + 1) : 0;
	d >= 0 ? less = d : 0;
	len = 0;
	d == 44294967296u ? (len_n = 4294967295u) && (para->d++) : 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	while (len > 0)
	{
		dstr[len] = (less % 10) + '0';
		less /= 10;
		len--;
	}
	dstr[len] = less + '0';
	para->d == 1 ? dstr[10] = '6' : 0;
	return (dstr);
}

static char		*ft_ustrll(long long d)
{
	char				*dstr;
	int					len;
	unsigned long long	len_n;
	unsigned long long	less;

	d < 0 ? less = 18446744073709551615u + (d + 1) : 0;
	d >= 0 ? (less = d) : 0;
	len = 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	return (dstr);
}

static char		*ft_ustrh(int d)
{
	char			*dstr;
	int				len;
	unsigned short	len_n;
	unsigned short	less;

	d < 0 ? less = 65535u + (d + 1) : 0;
	d >= 0 ? (less = d) : 0;
	len = 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	return (dstr);
}

void			ft_u_main(t_struct *para, va_list args)
{
	char	*d;

	para->f_one == '\0' && para->chara == 'u' ?
	d = ft_ustr(va_arg(args, int)) : 0;
	if (para->f_one == 'l' || para->chara == 'U')
	{
		para->f_two == '\0' ? d = ft_ustrl(va_arg(args, long), para) : 0;
		para->f_two == 'l' ? d = ft_ustrll(va_arg(args, long long)) : 0;
	}
	if (para->f_one == 'h' && para->chara == 'u')
	{
		para->f_two == '\0' ? d = ft_ustrh((short)va_arg(args, int)) : 0;
		para->f_two == 'h' ? d = ft_ustrhh((char)va_arg(args, int)) : 0;
	}
	para->f_one == 'j' ? d = ft_ustrll(va_arg(args, long long)) : 0;
	para->f_one == 'z' ? d = ft_ustrl(va_arg(args, long), para) : 0;
	para->s_ = 0;
	para->p_ = 0;
	ft_d(para, d);
}
