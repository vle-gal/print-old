/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:09:45 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/19 17:46:36 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_ustrhh(char d)
{
	char			*dstr;
	int				len;
	unsigned char	len_n;
	unsigned char	less;

	d < 0 ? less = 255u + (d + 1) : 0;
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
