/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:59:40 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/28 15:08:36 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (0);
	head->value = value;
	head->next = NULL;
	head->previous = NULL;
	return (head);
}

void	ft_stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (new != NULL)
	{
		current = *stack;
		if (*stack == NULL)
			*stack = new;
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
			current->next->previous = current;
			current->next->next = NULL;
		}
	}
}

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack != NULL && *stack != NULL)
	{
		while ((*stack)->previous != NULL)
			(*stack) = (*stack)->previous;
		current = *stack;
		while (current != NULL)
		{
			temp = current->next;
			current->next = NULL;
			current->previous = NULL;
			free(current);
			current = temp;
		}
		*stack = NULL;
	}
}

size_t	ft_stack_len(t_stack **stack)
{
	size_t	len;
	t_stack	*current;

	if (*stack == NULL)
		return (0);
	len = 1;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

void	ft_refresh_index(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	if (stack != NULL && *stack != NULL)
	{
		current = *stack;
		while (current->next != NULL)
		{
			current->i = i;
			i++;
			current = current->next;
		}
		current->i = i;
	}
}
