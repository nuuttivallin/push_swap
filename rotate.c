/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:22:40 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/28 16:38:51 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		*stack = (*stack)->next;
		(*stack)->previous = NULL;
		last->next->previous = last;
		last->next->next = NULL;
		ft_refresh_index(stack);
	}
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
