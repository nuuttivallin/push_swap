/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:03 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 14:48:21 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_cheapest(t_stack **b, t_stack **a)
{
	int		moves;
	int		least;
	t_stack	*current;

	least = 2147483647;
	moves = 0;
	current = *b;
	ft_check_cheapest(*b, *a, moves, least);
	while (current->cheapest == 0)
		current = current->next;
	if ((size_t)current->i > ft_stack_len(b) / 2)
		ft_pa_above_median(b, a, current);
	else
		ft_pa_below_median(b, a, current);
}

void	ft_pa_above_median(t_stack **b, t_stack **a, t_stack *cheapest)
{
	if ((size_t)cheapest->t->i > ft_stack_len(a) / 2)
	{
		while (*b != cheapest && *a != cheapest->t)
			rrr(a, b);
		while (*b != cheapest)
			rrb(b);
		while (*a != cheapest->t)
			rra(a);
	}
	while (*b != cheapest)
		rrb(b);
	while (*a != cheapest->t)
		ra(a);
	pa(b, a);
}

void	ft_pa_below_median(t_stack **b, t_stack **a, t_stack *cheapest)
{
	if ((size_t)cheapest->t->i <= ft_stack_len(a) / 2)
	{
		while (*b != cheapest && *a != cheapest->t)
			rr(a, b);
		while (*b != cheapest)
			rb(b);
		while (*a != cheapest->t)
			ra(a);
	}
	while (*b != cheapest)
		rb(b);
	while (*a != cheapest->t)
		rra(a);
	pa(b, a);
}
