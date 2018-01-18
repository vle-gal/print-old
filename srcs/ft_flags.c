/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:34:29 by vle-gal           #+#    #+#             */
/*   Updated: 2018/01/18 11:42:19 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_flags_height(char *s, size_t len, t_struct *para)
{
	int		a;
	int		n;
	char	*new_s;

	n = 0;
	a = para->nbr - (int)len;
	if (a > 0)
	{
		new_s = ft_strnew(para->nbr);
		while (a > 0)
		{
			para->z_ == 1 && para->d_ == -1 ? new_s[n] = '0' : 0;
			para->z_ != 1 || para->d_ != -1 ? new_s[n] = ' ' : 0;
			1 ? a-- && (n++) : 0;
		}
		para->s_ == 1 && para->p_ == 0 ? new_s[0] = ' ' : 0;
		para->p_ == 1 && para->z_ == 1 && para->d_ == -1 ? new_s[0] = '+' : 0;
		para->p_ == 1 && para->z_ == 1 && para->d_ > 0 ?
		new_s[n - 1] = '+' : 0;
		para->p_ == 1 && para->z_ == 0 ? new_s[n - 1] = '+' : 0;
		while (s[a])
			s[a] != 0 ? (new_s[n] = s[a]) && (n++) && (a++) : 0;
		return (new_s);
	}
	return (s);
}

static int	ft_flags_height_int_help(char *new_s, t_struct *para, int a)
{
	while (a > 0)
	{
		para->z_ == 1 && para->d_ == -1 ? new_s[para->n] = '0' : 0;
		para->z_ != 1 || para->d_ != -1 ? new_s[para->n] = ' ' : 0;
		para->n++;
		a--;
	}
	// printf("%d %d %d\n", para->p_, para->nbr, para->d_);
	para->p_ == 1 && para->nbr != -1 && para->d_ > 0? new_s[para->n - 1] = '+' : 0;
	para->p_ == 1 && para->nbr != -1 && para->d_ > 1? para->p_-- : 0;
	para->p_ == 1 && para->d != -1 && para->z_ != 1? ft_putchar('+'): 0;
	para->p_ == 1 && para->d != -1 && para->z_ != 1? para->p_--: 0;
	// para->p_ == 1 && para->z_ == new_s[para->n -1] = '+' : 0;
	para->s_ == 1 && para->p_ == 0 ? new_s[0] = ' ' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ == -1 ? new_s[0] = '+' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ > 0 ?
	new_s[para->n - 1] = '+' : 0;
	para->p_ == 1 && para->z_ == 0 ? new_s[para->n - 1] = '+' : 0;
	return(a);
}

char		*ft_flags_height_int(char *s, size_t len, t_struct *para)
{
	int		a;
	char	*new_s;

	para->n = 0;
	a = para->nbr - (int)len;
	if (a > 0)
	{
		new_s = ft_strnew(para->nbr);
		a = ft_flags_height_int_help(new_s, para, a);
		while (s[a])
		{
			new_s[para->n] = s[a];
			s[a] == '-' && para->z_ == 1 ? new_s[0] = '-' : 0;
			s[a] == '-' && para->z_ == 1 ? new_s[para->n] = '0' : 0;
			para->n++;
			a++;
		}
		return (new_s);
	}
	return (s);
}

char		*ft_flags_dot(char *s, size_t len, t_struct *para)
{
	int		n;
	int		x;
	char	*new_s;

	n = 0;
	x = 0;
	if (para->d_ < (int)len)
		return (s);
	else
	{
		new_s = ft_strnew((size_t)para->d_);
		while (n < (para->d_ - (int)len))
		{
			new_s[n] = '0';
			n++;
		}
		while (n < para->d_)
		{
			new_s[n] = s[x];
			x++;
			n++;
		}
		return (new_s);
	}
	return (s);
}
