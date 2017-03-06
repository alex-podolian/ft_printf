/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:03:22 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 19:53:29 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	L,
}	t_length;

typedef enum
{
	no,
	yes,
	o,
	x,
	X,
	dot
}	t_hash;

typedef struct	s_flags
{
	int			left;
	int			plus;
	int			space;
	t_hash		hash;
	int			zero;
}				t_flags;

typedef struct	s_mods
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		qualifier;
}				t_mods;

int				ft_printf(const char *format, ...);
int				ft_flags(const char *format, t_mods *mods);
int				ft_width(const char *format, t_mods *mods, va_list ap);
int				ft_precision(const char *format, t_mods *mods, va_list ap);
int				ft_length(const char *format, t_mods *mods);
int				ft_qualifier(char c, t_mods *mods);

int				ft_no_qual(t_mods *mods);
int				ft_numb(va_list ap, t_mods *mods);
int				ft_char(va_list ap, t_mods *mods);
int				ft_str(va_list ap, t_mods *mods);
int				ft_float(va_list ap, t_mods *mods);

int				ft_size(char *str, t_mods *mods);
int				ft_is_mb(char *s);
char			*ft_convert_len(va_list ap, t_mods *mods, char c);
char			*ft_convert_ulen(va_list ap, t_mods *mods, char c);
void			ft_push_right(t_mods *mods, char **mas, int size, char *str);
void			ft_push_left(t_mods *mods, char **mas, int size, char *str);

#endif