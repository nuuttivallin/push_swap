/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:25:48 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/28 16:14:07 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->previous->next = NULL;
		first->previous = last;
		first->previous->next = first;
		*stack = (*stack)->previous;
		(*stack)->previous = NULL;
		ft_refresh_index(stack);
	}
}

void	rra(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
