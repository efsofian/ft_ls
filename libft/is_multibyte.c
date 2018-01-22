/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_multibyte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:51:56 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/30 21:15:56 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			is_n_bytes(char *str, int n)
{
	int		indx;

	indx = 1;
	while (str[indx] && indx < n)
	{
		if (str[indx] >= -64)
			return (0);
		indx++;
	}
	if (indx == n)
		return (n);
	return (0);
}

int			is_multibyte(char *str)
{
	int		indx;

	if (!str)
		return (0);
	indx = 0;
	if (str[indx] > 0)
		return (1);
	else if (str[indx] > -64 && str[indx] < -32)
		return (is_n_bytes(str, 2));
	else if (str[indx] >= -32 && str[indx] < -16)
		return (is_n_bytes(str, 3));
	else if (str[indx] >= -16 && str[indx] < -8)
		return (is_n_bytes(str, 4));
	else
		return (0);
}
