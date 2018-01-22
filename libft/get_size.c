/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:51:34 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/30 21:15:53 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		get_size(char *str, t_params *params)
{
	int		len;
	int		size;
	int		hash;

	len = (str[0] == '-') ? ft_strlen(str) - 1 : ft_strlen(str);
	hash = (params->specifier == 'o' && params->flags.hash
			&& len >= params->preci) ? 1 : 0;
	if ((params->specifier == 'x' || params->specifier == 'X'
		|| params->specifier == 'p') && params->flags.hash)
		hash += 2;
	if (params->width > len + hash && params->width > params->preci)
		size = params->width;
	else
	{
		size = len > params->preci ? len + hash : params->preci + hash;
		if (params->flags.plus || params->flags.space || str[0] == '-')
			size++;
	}
	return (size);
}
