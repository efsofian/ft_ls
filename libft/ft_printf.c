/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:51:16 by seliasbe          #+#    #+#             */
/*   Updated: 2018/01/07 12:19:38 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

static void	set_params(t_params *params)
{
	params->flags.hash = no;
	params->flags.zero = 0;
	params->flags.minus = 0;
	params->flags.plus = 0;
	params->flags.space = 0;
	params->width = 0;
	params->preci = -1;
	params->length = none;
	params->specifier = '\0';
}

int			check_print(const char *format, t_params *params, va_list ap)
{
	unsigned int	indx;
	char			*type;
	int				ret;

	ret = 0;
	indx = 0;
	while (format[indx])
	{
		if ((type = ft_strchr(&format[indx], '%')))
		{
			write(1, &format[indx], type - &format[indx]);
			ret += type - &format[indx];
			set_params(params);
			indx = parse_params(indx + type - &format[indx] + 1,
				format, params, ap);
			ret += parse_specifiers(ap, params);
		}
		else
		{
			ft_putstr(&format[indx]);
			ret += ft_strlen(&format[indx]);
			break ;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	params;
	int			ret;

	if (!format)
		return (0);
	va_start(ap, format);
	ret = 0;
	if ((ret = check_print(format, &params, ap)) < 0)
		return (-1);
	va_end(ap);
	return (ret);
}
