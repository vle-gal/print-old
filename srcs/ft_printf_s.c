/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:09:57 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/19 17:44:15 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_switch_wchar(wchar_t *s_l)
{
	char	*new_s;
	int		n;
	int		a;

	a = 0;
	n = 0;
	while (s_l[n])
	{
		n++;
	}
	new_s = ft_strnew(n);
	while (n > 0)
	{
		new_s[a] = (char)s_l[a];
		n--;
		a++;
	}
	return (new_s);
}

static void		ft_ls(t_struct *para, wchar_t *s_l)
{
	int		len;
	int		len_less;
	char	*s;

	if (s_l == NULL)
	{
		s = (ft_strnew(6));
		s = ft_strcpy(s, "(null)");
	}
	else
		s = ft_switch_wchar(s_l);
	len = ft_strlen(s);
	if (para->d_ != -1)
		s = ft_flags_dot(s, len, para);
	len = ft_strlen(s);
	if (para->nbr != '\0')
		s = ft_flags_height(s, len, para);
	len_less = ft_strlen(s);
	ft_putstr(s);
	para->res = ft_strlen(s) + para->res;
}

static void		ft_s(t_struct *para, char *s)
{
	int		len;
	int		len_less;
	char	*test;

	test = NULL;
	s == NULL ? test = ft_strnew(6) : 0;
	s == NULL ? test = ft_strcpy(test, "(null)") : 0;
	s != NULL ? test = ft_strdup(s) : 0;
	len = ft_strlen(test);
	if (para->d_ != -1)
	{
		while (para->d_ < len)
		{
			len--;
			test[len] = '\0';
		}
	}
	len = ft_strlen(test);
	if (para->nbr != '\0' && para->l_ != 1)
		test = ft_flags_height(test, len, para);
	para->l_ == 1 ? test = ft_flags_less(test, len, para) : 0;
	len_less = ft_strlen(test);
	para->res = ft_strlen(test) + para->res;
	ft_putstr(test);
}

void			ft_s_main(t_struct *para, va_list args)
{
	if (para->f_one == '\0' && para->chara == 's')
		ft_s(para, va_arg(args, char *));
	else
		ft_ls(para, va_arg(args, wchar_t*));
}
