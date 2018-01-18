/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/20 16:14:27 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void		ft_c_draw_0(t_struct *para)
{
	para->res++;
	while (para->nbr > 1 && para->l_ == 0)
	{
		para->z_ == 1 ? ft_putchar('0') : (ft_putchar(' '));
		para->res++;
		para->nbr--;
	}
	ft_putchar(0);
	while (para->l_ == 1 && para->nbr > 1)
	{
		ft_putchar(' ');
		para->res++;
		para->nbr--;
	}
}

static	char		*ft_cstr(char c, t_struct *para)
{
	char *new_c;

	if (c == 0)
	{
		ft_c_draw_0(para);
		new_c = ft_strnew(0);
	}
	else
	{
		new_c = ft_strnew(2);
		c != 0 ? new_c[0] = c : (para->res++);
		c == 0 ? new_c[0] = 0 : 0;
	}
	return (new_c);
}

void				ft_c_draw(t_struct *para, char *c)
{
	int len;
	int len_less;

	if (c[0] != 0)
	{
		len = ft_strlen(c);
		if (para->nbr != '\0' && para->l_ == 0)
			c = ft_flags_height(c, len, para);
		if (para->l_ == 1)
			c = ft_flags_less(c, len, para);
		len_less = ft_strlen(c);
		para->res += len_less;
		ft_putstr(c);
	}
	free(c);
}

void				ft_c_main(t_struct *para, va_list args)
{
	char *c;

	c = ft_cstr((char)va_arg(args, int), para);
	c[0] != 0 ? ft_c_draw(para, c) : 0;
}
