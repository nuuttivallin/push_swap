/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:08:12 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 15:36:06 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

int	ft_isnumber(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(*str) == 0)
		return (0);
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

void	ft_free_p2p(int check, char **ptr)
{
	int	i;

	i = 0;
	if (check == 2)
	{
		if (ptr != NULL)
		{
			while (ptr[i] != NULL)
				free(ptr[i++]);
			free(ptr);
			ptr = NULL;
		}
	}
}

int	ft_is_smallest(t_stack *stack)
{
	t_stack	*compare;

	compare = NULL;
	if (stack->next != NULL)
		compare = stack->next;
	while (compare != NULL)
	{
		if (stack->value > compare->value)
			return (0);
		compare = compare->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
