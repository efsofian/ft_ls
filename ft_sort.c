/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:30:21 by seliasbe          #+#    #+#             */
/*   Updated: 2018/01/07 11:30:22 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_alpha(t_ftls *a, t_ftls *b)
{
	if (ft_strcmp(a->name, b->name) <= 0)
		return (1);
	return (0);
}

int		sort_time(t_ftls *a, t_ftls *b)
{
	long	dif;

	dif = a->buf->st_mtime - b->buf->st_mtime;
	if (!dif)
	{
		dif = a->buf->st_mtimespec.tv_nsec - b->buf->st_mtimespec.tv_nsec;
		if (!dif)
			return (sort_alpha(a, b));
	}
	if (dif >= 0)
		return (1);
	return (0);
}

t_list	*sortedmerge(t_list *a, t_list *b, int (*sort)(t_ftls*, t_ftls*))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (sort(a->content, b->content))
	{
		result = a;
		result->next = sortedmerge(a->next, b, sort);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next, sort);
	}
	return (result);
}

void	frontbacksplit(t_list *source, t_list **frontref, t_list **backref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void	ls_mergesort(t_list **file, int (*sort)(t_ftls*, t_ftls*))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	if (!sort)
		return ;
	head = *file;
	if (head == NULL || head->next == NULL)
		return ;
	frontbacksplit(head, &a, &b);
	ls_mergesort(&a, sort);
	ls_mergesort(&b, sort);
	*file = sortedmerge(a, b, sort);
}
