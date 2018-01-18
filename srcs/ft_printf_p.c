/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:14:09 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/19 17:36:15 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_unsigned_longlen(unsigned long lu)
{
	int		len;

	len = 1;
	while (lu > 9)
	{
		len++;
		lu /= 10;
	}
	return (len);
}

static char		*ft_putaddrr(void *p)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	res = ft_strnew(14);
	adr = (unsigned long)p;
	base = "0123456789abcdef";
	ft_unsigned_longlen(adr) == 15 ? i = 11 : 0;
	ft_unsigned_longlen(adr) != 15 ? i = 5 : 0;
	while ((adr / 16) > 0 || i >= 11)
	{
		res[i + 2] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i + 2] = base[(adr % 16)];
	res[0] = ('0');
	res[1] = ('x');
	p == NULL ? res[2] = ('0') : 0;
	return (res);
}

void			ft_p(t_struct *para, char *p)
{
	int len;
	int len_less;

	len = ft_strlen(p);
	if (para->nbr != '\0')
		p = ft_flags_height(p, len, para);
	len_less = ft_strlen(p);
	para->res = ft_strlen(p) + para->res;
	ft_putstr(p);
	free(p);
}

void			ft_p_main(t_struct *para, va_list args)
{
	char	*p;

	if (para->f_one == '\0')
	{
		p = ft_putaddrr(va_arg(args, void *));
		ft_p(para, p);
	}
}
