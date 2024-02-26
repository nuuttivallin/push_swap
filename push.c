/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:18:14 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/28 15:10:47 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	if (*from != NULL)
	{
		if ((*from)->next != NULL)
			(*from)->next->previous = NULL;
		if (*to == NULL)
		{
			*to = *from;
			*from = (*from)->next;
			(*to)->previous = NULL;
			(*to)->next = NULL;
		}
		else
		{
			(*to)->previous = *from;
			*from = (*from)->next;
			(*to)->previous->next = *to;
			(*to)->previous->previous = NULL;
			*to = (*to)->previous;
		}
		if (*from != NULL)
			ft_refresh_index(from);
		if (*to != NULL)
			ft_refresh_index(to);
	}
}

void	pa(t_stack **b, t_stack **a)
{
	if (b != NULL && *b != NULL)
	{
		ft_push(b, a);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (a != NULL && *a != NULL)
	{
		ft_push(a, b);
		ft_printf("pb\n");
	}
}
