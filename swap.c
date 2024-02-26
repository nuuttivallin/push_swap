/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:12:16 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/29 17:45:40 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	first = *stack;
	if (first != NULL && first->next != NULL)
	{
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
		ft_refresh_index(stack);
	}
}

void	sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
