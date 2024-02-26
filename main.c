/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:29 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 15:01:38 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	size_t	len;

	len = ft_stack_len(a);
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	if (len == 3)
		ft_sort_3(a);
	if (len == 4 || len == 5)
		ft_sort_5(a, b);
	if (len > 5)
		ft_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		a = get_stack(argc, argv);
		if (a == NULL)
			return (0);
		ft_refresh_index(&a);
		if (!ft_is_sorted(a))
			push_swap(&a, &b);
		if (a != NULL)
			ft_clear_stack(&a);
		if (b != NULL)
			ft_clear_stack(&b);
	}
	return (0);
}
