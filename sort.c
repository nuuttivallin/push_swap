/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:11:17 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 15:12:56 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	while (ft_stack_len(a) > 3 && ft_stack_len(b) < 2)
		pb(a, b);
	ft_set_targets_a(a, b);
	while (ft_stack_len(a) > 3)
	{
		ft_pb_cheapest(a, b);
		ft_set_targets_a(a, b);
	}
	ft_sort_3(a);
	ft_set_targets_b(b, a);
	while (ft_stack_len(b) != 0)
	{
		ft_pa_cheapest(b, a);
		ft_set_targets_b(b, a);
	}
	smallest = ft_find_smallest(*a);
	if ((size_t)smallest->i > ft_stack_len(a) / 2)
	{
		while (*a != smallest)
			rra(a);
	}
	while (*a != smallest)
		ra(a);
}

int	ft_moves_below_median(t_stack *b, t_stack *current)
{
	int	moves;

	moves = current->i;
	if ((size_t)current->t->i > ft_stack_len(&b) / 2)
		moves += (ft_stack_len(&b) - current->t->i);
	else if (current->t->i > current->i)
		moves = current->t->i;
	return (moves);
}

int	ft_moves_above_median(t_stack *a, t_stack *b, t_stack *current)
{
	int	moves;

	moves = ft_stack_len(&a) - current->i;
	if ((size_t)current->t->i <= ft_stack_len(&b) / 2)
		moves += current->t->i;
	else if (ft_stack_len(&b) - current->t->i > ft_stack_len(&a) - current->i)
		moves = ft_stack_len(&b) - current->t->i;
	return (moves);
}

void	ft_check_cheapest(t_stack *a, t_stack *b, int moves, int least)
{
	t_stack	*current;

	current = a;
	while (current != NULL)
	{
		if ((size_t)current->i <= ft_stack_len(&a) / 2)
			moves = ft_moves_below_median(b, current);
		else
			moves = ft_moves_above_median(a, b, current);
		if (moves < least)
		{
			least = moves;
			ft_set_cheapest(a, current);
			if (moves == 0)
				return ;
		}
		current = current->next;
	}
}

void	ft_set_cheapest(t_stack *stack, t_stack *cheapest)
{
	t_stack	*current;

	current = stack;
	while (current != cheapest)
	{
		current->cheapest = 0;
		current = current->next;
	}
	current->cheapest = 1;
	while (current->next != NULL)
	{
		current = current->next;
		current->cheapest = 0;
	}
}
