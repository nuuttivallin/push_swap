/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:16:10 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 14:53:16 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_targets_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*compare;
	long	best;

	best = -2147483649;
	current = *a;
	compare = *b;
	while (current != NULL)
	{
		while (compare != NULL)
		{
			if (compare->value < current->value
				&& compare->value > best)
			{
				best = compare->value;
				current->t = compare;
			}
			compare = compare->next;
		}
		if (best == -2147483649)
			current->t = ft_find_biggest(*b);
		current = current->next;
		compare = *b;
		best = -2147483649;
	}
}

void	ft_set_targets_b(t_stack **b, t_stack **a)
{
	t_stack	*current;
	t_stack	*compare;
	long	best;

	best = 2147483649;
	current = *b;
	compare = *a;
	while (current != NULL)
	{
		while (compare != NULL)
		{
			if (compare->value > current->value
				&& compare->value < best)
			{
				best = compare->value;
				current->t = compare;
			}
			compare = compare->next;
		}
		if (best == 2147483649)
			current->t = ft_find_smallest(*a);
		current = current->next;
		compare = *a;
		best = 2147483649;
	}
}

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	smallest = stack;
	current = stack;
	if (stack->next != NULL)
	{
		current = stack->next;
		while (current->next != NULL)
		{
			if (current->value < smallest->value)
				smallest = current;
			current = current->next;
		}
	}
	if (current->value < smallest->value)
		smallest = current;
	return (smallest);
}

t_stack	*ft_find_biggest(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*current;

	biggest = stack;
	current = stack;
	if (stack->next != NULL)
	{
		current = stack->next;
		while (current->next != NULL)
		{
			if (current->value > biggest->value)
				biggest = current;
			current = current->next;
		}
	}
	if (current->value > biggest->value)
		biggest = current;
	return (biggest);
}
