/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:07:11 by vle-gal           #+#    #+#             */
/*   Updated: 2018/01/18 11:51:10 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#	include "libft/doth/libft.h"
#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
#	include <fcntl.h>
#	include <stdarg.h>
#	include <wchar.h>
#	include <stdint.h>

typedef struct		s_struct
{
	int n;
	int d;
	int i;
	int s_sec;
	int xdoth;
	unsigned long x;
	int flag;
	char chara;
	int h_;
	int z_;
	int l_;
	int p_;
	int s_;
	int d_;
	int nbr;
	char f_one;
	char f_two;
	char *s1;
	int res;
	va_list *args;
	int len;
	int less;
	long long t_d;
}									t_struct;


# define BLACK "\x1B[30m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"
# define CRESET "\x1B[0m"

int		ft_printf(const char* format, ...);
void	ft_putaddr(void* p, t_struct * para);
void	ft_puthex(unsigned int p, t_struct * para);
void	ft_putoctal(unsigned int p, t_struct * para);
void	ft_putoctal_long(unsigned long p, t_struct * para);
void	ft_puthex_long(unsigned long p, t_struct * para);
void	ft_s_main(t_struct * para, va_list args);
void	ft_putstr_ls(t_struct * para, wchar_t * s);
char*	ft_flags_dot(char* s, size_t len, t_struct * para);
char*	ft_flags_dot_int(char* s, size_t len, t_struct * para);
char*	ft_flags_height(char* s, size_t len, t_struct * para);
char*	ft_flags_height_int (char * s, size_t len, t_struct * para);
char*	ft_flags_less(char* s, size_t len, t_struct * para);
void  ft_p_main(t_struct *para, va_list args);
void  ft_d_main(t_struct *para, va_list args);
char* ft_dstrl(long d, t_struct * para);
char* ft_dstrll(long long d, t_struct * para);
char* ft_dstrh(short d, t_struct * para);
char* ft_dstrhh(char d, t_struct * para);
void  ft_d(t_struct * para, char* d);
void  ft_u_main(t_struct * para, va_list args);
char* ft_ustrhh(char d);
char* ft_ustrz(size_t d);
void ft_o_main(t_struct *para, va_list args);
void ft_x_main(t_struct *para, va_list args);
void ft_c_main(t_struct *para, va_list args);
char* ft_xstrhh(char p, t_struct * para);
char* ft_ostrhh(char p);
void ft_ohtag(t_struct * para, char *o);
void ft_xhtag(t_struct * para, char *x);
char *ft_xmaj(char *x);
void ft_x_draw(t_struct * para, char *x);
void ft_c_draw(t_struct * para, char *c);
void ft_o_draw(t_struct * para, char *o);
#endif
