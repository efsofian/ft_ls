/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:54:16 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/30 21:16:03 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		flags(const char *format, t_params *params)
{
	int		indx;

	indx = 0;
	while (format[indx] == '#' || format[indx] == '0' || format[indx] == '-'
		|| format[indx] == '+' || format[indx] == ' ')
	{
		if (format[indx] == '#')
			params->flags.hash = yes;
		else if (format[indx] == '0')
			params->flags.zero = 1;
		else if (format[indx] == '-')
			params->flags.minus = 1;
		else if (format[indx] == '+')
			params->flags.plus = 1;
		else if (format[indx] == ' ')
			params->flags.space = 1;
		indx++;
	}
	return (indx);
}

int		width(const char *format, t_params *params, va_list ap)
{
	int		indx;

	indx = 0;
	if (format[indx] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->flags.minus = 1;
			params->width *= -1;
		}
		return (1);
	}
	if (ft_isdigit(format[indx]))
		params->width = 0;
	while (ft_isdigit(format[indx]))
		params->width = params->width * 10 + (format[indx++] - '0');
	return (indx);
}

int		precision(const char *format, t_params *params, va_list ap)
{
	int		indx;

	indx = 0;
	params->preci = 0;
	if (format[++indx] == '*')
	{
		params->preci = va_arg(ap, int);
		return (2);
	}
	while (ft_isdigit(format[indx]))
		params->preci = params->preci * 10 + (format[indx++] - '0');
	return (indx);
}

int		double_length(const char *format, t_params *params, int indx)
{
	if (format[indx] == 'h')
	{
		if (params->length == h)
			params->length = hh;
		else if (params->length < h)
			params->length = h;
	}
	else if (format[indx] == 'l')
	{
		if (params->length == l)
			params->length = ll;
		else if (params->length < l)
			params->length = l;
	}
	return (indx);
}

int		length(const char *format, t_params *params)
{
	int		indx;

	indx = 0;
	if (format[indx] == 'h' || format[indx] == 'l')
		indx = double_length(format, params, indx);
	else if (format[indx] == 'j')
		params->length = j;
	else if (format[indx] == 'z')
		params->length = z;
	else
		return (0);
	return (1);
}
