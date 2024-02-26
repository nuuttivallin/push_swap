/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:02:24 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/26 13:30:00 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
	{
		if ((*a)->value > (*a)->next->next->value)
			ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	if ((*a)->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->next->value > (*a)->next->next->value)
	{
		rra(a);
		sa(a);
	}
}

void	ft_sort_5(t_stack **a, t_stack **b)
{
	while (ft_stack_len(a) != 3)
	{
		if (ft_is_smallest(*a))
			pb(a, b);
		else if (ft_is_smallest((*a)->next))
			sa(a);
		else
			rra(a);
	}
	ft_sort_3(a);
	while (ft_stack_len(b) != 0)
		pa(b, a);
}
