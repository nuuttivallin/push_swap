/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:21 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 15:28:14 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**list;

	list = NULL;
	stack = NULL;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		stack = check_input(argc, list, stack);
	}
	else
		stack = check_input(argc, argv, stack);
	ft_free_p2p(argc, list);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stack);
}

t_stack	*check_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	n;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i] != NULL)
	{
		n = ft_atol(argv[i]);
		if (!ft_isnumber(argv[i]) || n > 2147483647 || n < -2147483648)
		{
			ft_clear_stack(&stack);
			return (NULL);
		}
		ft_stack_add_bottom(&stack, ft_new_node(n));
		i++;
	}
	stack = check_duplicates(stack);
	return (stack);
}

t_stack	*check_duplicates(t_stack *stack)
{
	t_stack	*top;
	t_stack	*compare;

	top = stack;
	while (stack->next != NULL)
	{
		compare = stack->next;
		while (compare != NULL)
		{
			if (stack->value == compare->value)
			{
				ft_clear_stack(&stack);
				return (NULL);
			}
			compare = compare->next;
		}
		stack = stack->next;
	}
	return (top);
}
