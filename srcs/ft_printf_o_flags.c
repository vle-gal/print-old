/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:38:38 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/22 13:56:56 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_ostrhh(char p)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned char)p;
	i = 0;
	while (adr > 9)
	{
		adr /= 10;
		i++;
	}
	adr = (unsigned char)p;
	res = ft_strnew(i + 1);
	base = "01234567";
	while ((adr / 8) > 0 || i > 1)
	{
		res[i] = base[(adr % 8)];
		adr /= 8;
		i--;
	}
	res[0] = base[(adr % 8)];
	return (res);
}

void	ft_ohtag(t_struct *para, char *o)
{
	char	*tmp;
	int		n;

	para->d_ == 0 ? para->d_ = -1 : 0;
	n = ft_strlen(o);
	tmp = ft_strnew((size_t)n);
	o[0] != '0' ? tmp[0] = '0' : 0;
	ft_strcat(tmp, o);
	free(o);
	ft_o_draw(para, tmp);
}

void	ft_o_draw(t_struct *para, char *o)
{
	int len;
	int len_less;

	len = ft_strlen(o);
	if (para->d_ != -1)
		o = ft_flags_dot_int(o, len, para);
	len = ft_strlen(o);
	if (para->nbr != '\0' && para->l_ == 0)
		o = ft_flags_height(o, len, para);
	if (para->l_ == 1)
		o = ft_flags_less(o, len, para);
	len_less = ft_strlen(o);
	para->res += ft_strlen(o);
	ft_putstr(o);
}
