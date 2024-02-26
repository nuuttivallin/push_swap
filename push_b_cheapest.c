/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:49 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 14:48:32 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_cheapest(t_stack **a, t_stack **b)
{
	int		moves;
	int		least;
	t_stack	*current;

	least = 2147483647;
	moves = 0;
	current = *a;
	ft_check_cheapest(*a, *b, moves, least);
	while (current->cheapest == 0)
		current = current->next;
	if ((size_t)current->i > ft_stack_len(a) / 2)
		ft_pb_above_median(a, b, current);
	else
		ft_pb_below_median(a, b, current);
}

void	ft_pb_above_median(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if ((size_t)cheapest->t->i > ft_stack_len(b) / 2)
	{
		while (*a != cheapest && *b != cheapest->t)
			rrr(a, b);
		while (*a != cheapest)
			rra(a);
		while (*b != cheapest->t)
			rrb(b);
	}
	while (*a != cheapest)
		rra(a);
	while (*b != cheapest->t)
		rb(b);
	pb(a, b);
}

void	ft_pb_below_median(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if ((size_t)cheapest->t->i <= ft_stack_len(b) / 2)
	{
		while (*a != cheapest && *b != cheapest->t)
			rr(a, b);
		while (*a != cheapest)
			ra(a);
		while (*b != cheapest->t)
			rb(b);
	}
	while (*a != cheapest)
		ra(a);
	while (*b != cheapest->t)
		rrb(b);
	pb(a, b);
}
