/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:35:02 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/22 19:41:24 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_dstrl(long d, t_struct *para)
{
	char	*dstr;

	d < 0 ? para->less = 1 : 0;
	d < 0 ? d = d * -1 : 0;
	d == -2147483648 ? para->t_d = 2147483647 : 0;
	d == -2147483648 ? (d = 2147483647) && (para->d++) : 0;
	d != -2147483648 ? para->t_d = d : 0;
	while (para->t_d > 9)
	{
		para->t_d /= 10;
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
	para->d == 1 ? dstr[10] = '8' : 0;
	return (dstr);
}

char	*ft_dstrh(short d, t_struct *para)
{
	char	*dstr;

	d < 0 ? para->less = 1 : 0;
	d < 0 ? d = d * -1 : 0;
	d == -32768 ? para->t_d = 32767 : 0;
	d == -32768 ? (d = (d * -1) - 1) && (para->d++) : 0;
	d != -32768 ? para->t_d = d : 0;
	while (para->t_d > 9)
	{
		para->t_d /= 10;
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
	para->d == 1 ? dstr[5] = '8' : 0;
	return (dstr);
}

char	*ft_dstrll(long long d, t_struct *para)
{
	char		*dstr;

	d < 0 ? para->less = 1 : 0;
	d < 0 ? d = d * -1 : 0;
	(d == -9223372036854775807 - 1) ? para->t_d = 9223372036854775807 : 0;
	(d == -9223372036854775807 - 1) ?
	(d = 9223372036854775807) && (para->d++) : 0;
	(d != -9223372036854775807 - 1) ? para->t_d = d : 0;
	while (para->t_d > 9)
	{
		para->t_d /= 10;
		para->len++;
	}
	dstr = ft_strnew((size_t)para->len + 2);
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
	para->d == 1 ? dstr[19] = '8' : 0;
	return (dstr);
}

char	*ft_dstrhh(char d, t_struct *para)
{
	char	*dstr;

	d < 0 ? para->less = 1 : 0;
	d < 0 ? (d = d * -1) : 0;
	d == -128 ? para->t_d = 127 : 0;
	d == -128 ? (d = 127) && (para->d++) : 0;
	d != -128 ? para->t_d = d : 0;
	while (para->t_d > 9)
	{
		para->t_d /= 10;
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
	para->d == 1 ? dstr[3] = '8' : 0;
	return (dstr);
}
