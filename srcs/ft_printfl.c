/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:14:26 by anonymou          #+#    #+#             */
/*   Updated: 2018/01/18 10:45:43 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_flag_bis(const char *format, t_struct *para)
{
	int a;

	a = 0;
	if (format[para->i] != '.')
		a = format[para->i] - '0';
	para->i++;
	while (format[para->i] <= '9' && format[para->i] >= '0')
	{
		a = a * 10;
		a = a + format[para->i] - '0';
		para->i++;
	}
	para->i--;
	return (a);
}

static void		ft_flags(const char *format, t_struct *para)
{
	para->d_ = -1;
	para->nbr = -1;
	while ((format[para->i] <= '9' && format[para->i] > '0') ||
				format[para->i] == '-' || format[para->i] == '0' ||
				format[para->i] == ' ' || format[para->i] == '+' ||
				format[para->i] == '.' || format[para->i] == 'l' ||
				format[para->i] == 'h' || format[para->i] == 'j' ||
				format[para->i] == 'z' || format[para->i] == '#')
	{
		format[para->i] == '-' ? para->l_ = 1 : 0;
		format[para->i] == '#' ? para->h_ = 1 : 0;
		format[para->i] == '0' ? para->z_ = 1 : 0;
		format[para->i] == ' ' ? para->s_ = 1 : 0;
		format[para->i] == '+' ? para->p_ = 1 : 0;
		format[para->i] <= '9' && format[para->i] > '0' ?
		para->nbr = ft_flag_bis(format, para) : 0;
		format[para->i] == '.' ? para->d_ = ft_flag_bis(format, para) : 0;
		if (format[para->i] == 'l' || format[para->i] == 'h' ||
			format[para->i] == 'j' || format[para->i] == 'z')
		{
			(para->f_one == '\0') ? para->f_one = format[para->i] :
			(para->f_two = format[para->i]);
		}
		para->i++;
	}
}

static int		ft_format(const char *format, t_struct *para)
{
	while ((format[para->i] && format[para->i] != '%') ||
	(format[para->i] == '%' && format[para->i + 1] == '%'))
	{
		if (format[para->i] == '%' && format[para->i + 1] == '%')
		{
			para->res++;
			ft_putchar('%');
			para->i = para->i + 2;
		}
		else
		{
			para->res++;
			ft_putchar(format[para->i]);
			para->i++;
		}
	}
	if (format[para->i] == '%')
	{
		para->i++;
		ft_flags(format, para);
		return (1);
	}
	return (0);
}

static void		ft_para(const char *format, t_struct *para, va_list args)
{
	char *mod;

	mod = NULL;
	para->chara = format[para->i];
	para->chara == 's' || format[para->i] == 'S' ? ft_s_main(para, args) : 0;
	para->chara == 'p' || format[para->i] == 'P' ? ft_p_main(para, args) : 0;
	para->chara == 'd' || format[para->i] == 'D' ? ft_d_main(para, args) : 0;
	para->chara == 'i' || format[para->i] == 'I' ? ft_d_main(para, args) : 0;
	para->chara == 'o' || format[para->i] == 'O' ? ft_o_main(para, args) : 0;
	para->chara == 'u' || format[para->i] == 'U' ? ft_u_main(para, args) : 0;
	para->chara == 'x' || format[para->i] == 'X' ? ft_x_main(para, args) : 0;
	para->chara == 'c' || format[para->i] == 'C' ? ft_c_main(para, args) : 0;
	para->s_ = 0;
	if (format[para->i] == '%')
	{
		mod = ft_strnew(1);
		mod[0] = '%';
		ft_d(para, mod);
	}
	para->l_ = 0;
	para->z_ = 0;
	para->p_ = 0;
	para->d_ = 0;
	para->nbr = 0;
	para->less = 0;
	para->len = 0;
	para->t_d = 0;
}

int				ft_printf(const char *format, ...)
{
	t_struct	para;
	va_list		args;


	// t_struct	tutu;
	// para = NULL;
	// if (!(para = (t_struct *)malloc(sizeof(t_struct))))
	// 	return (0);
	bzero(&para, sizeof(para));
	va_start(args, format);
	while (ft_format(format, &para))
	{
		ft_para(format, &para, args);
		para.i++;
	}
	va_end(args);
	return (para.res);
}
