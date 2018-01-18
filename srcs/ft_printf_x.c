/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:07:42 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/20 18:38:26 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_xstr(int p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	p < 0 ? i = 7 : 0;
	res = ft_strnew(i);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

static char		*ft_xstrl(long p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	res = ft_strnew(i);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

static char		*ft_xstrll(long long p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	res = ft_strnew(i + 1);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

static char		*ft_xstrh(short p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	res = ft_strnew(i);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

void			ft_x_main(t_struct *para, va_list args)
{
	char	*x;

	para->f_one == '\0' ? x = ft_xstr(va_arg(args, int), para) : 0;
	if (para->f_one == 'l')
	{
		para->f_two == '\0' ? x = ft_xstrl(va_arg(args, long), para) : 0;
		para->f_two == 'l' ? x = ft_xstrll(va_arg(args, long long), para) : 0;
	}
	if (para->f_one == 'h')
	{
		para->f_two == '\0' ? x = ft_xstrh((short)va_arg(args, int), para) : 0;
		para->f_two == 'h' ? x = ft_xstrhh((char)va_arg(args, int), para) : 0;
	}
	para->f_one == 'j' ? x = ft_xstrll(va_arg(args, long long), para) : 0;
	para->f_one == 'z' ? x = ft_xstrl(va_arg(args, long), para) : 0;
	para->chara == 'X' ? x = ft_xmaj(x) : 0;
	para->h_ == 1 ? ft_xhtag(para, x) : ft_x_draw(para, x);
	para->xdoth = 0;
}
