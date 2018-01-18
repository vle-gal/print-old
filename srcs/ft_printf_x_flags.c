/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:12:30 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/20 18:55:32 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_xstrhh(char p, t_struct *para)
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

void	ft_xhtag(t_struct *para, char *x)
{
	char	*tmp;
	int		n;

	if (para->d_ == -1 && (ft_strlen(x) > 1))
	{
		n = ft_strlen(x) + 2;
		tmp = ft_strnew((size_t)n);
		tmp[0] = '0';
		para->chara == 'x' ? tmp[1] = 'x' : 0;
		para->chara != 'x' ? tmp[1] = 'X' : 0;
		ft_strcat(tmp, x);
		ft_x_draw(para, tmp);
	}
	else
		ft_x_draw(para, x);
}

char	*ft_xmaj(char *x)
{
	int i;

	i = 0;
	while (x[i] != '\0')
	{
		if (ft_isalpha(x[i]))
			x[i] = x[i] - 32;
		i++;
	}
	return (x);
}

void	ft_x_draw(t_struct *para, char *x)
{
	int len;
	int len_less;

	x[0] == '0' && para->d_ == 0 ? x[0] = '\0' : 0;
	len = ft_strlen(x);
	if (para->d_ != -1)
		x = ft_flags_dot(x, len, para);
	len = ft_strlen(x);
	if (para->nbr != '\0' && para->l_ == 0)
		x = ft_flags_height(x, len, para);
	len_less = ft_strlen(x);
	if (para->l_ == 1)
		x = ft_flags_less(x, len, para);
	para->res += ft_strlen(x);
	para->chara == 'x' && para->z_ == 1 && para->nbr > len && para->l_ == 0 &&
	para->h_ == 1 ? (x[1] = 'x') : 0;
	para->chara == 'x' && para->z_ == 1 && para->nbr > len && para->l_ == 0 &&
	para->h_ == 1 ? (x[para->nbr - (len - 1)] = '0') : 0;
	para->chara == 'X' && para->z_ == 1 && para->nbr > len && para->h_ == 1 ?
	(x[1] = 'X') : 0;
	para->chara == 'X' && para->z_ == 1 && para->nbr > len && para->h_ == 1 ?
	(x[para->nbr - (len - 1)] = '0') : 0;
	(para->chara == 'x' || para->chara == 'X') &&
	para->h_ == 1 && para->z_ == 1 ? x[0] = '0' : 0;
	ft_putstr(x);
}
