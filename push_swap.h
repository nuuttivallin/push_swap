/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:59:04 by nvallin           #+#    #+#             */
/*   Updated: 2024/01/30 16:01:22 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				i;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_stack	*t;
}			t_stack;

t_stack	*get_stack(int argc, char **argv);
t_stack	*check_input(int argc, char **argv, t_stack *stack);
t_stack	*check_duplicates(t_stack *stack);
t_stack	*ft_new_node(int value);
void	ft_stack_add_bottom(t_stack **stack, t_stack *new);
void	ft_clear_stack(t_stack **stack);
size_t	ft_stack_len(t_stack **stack);
void	ft_refresh_index(t_stack **stack);
long	ft_atol(const char *str);
int		ft_isnumber(const char *str);
void	ft_free_p2p(int check, char **ptr);
int		ft_is_smallest(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ft_push(t_stack **from, t_stack **to);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ft_sort_3(t_stack **stack);
void	ft_sort_5(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_pb_cheapest(t_stack **a, t_stack **b);
void	ft_pa_cheapest(t_stack **b, t_stack **a);
int		ft_moves_below_median(t_stack *b, t_stack *current);
int		ft_moves_above_median(t_stack *a, t_stack *b, t_stack *current);
void	ft_pb_above_median(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_pb_below_median(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_pa_above_median(t_stack **b, t_stack **a, t_stack *cheapest);
void	ft_pa_below_median(t_stack **b, t_stack **a, t_stack *cheapest);
void	ft_check_cheapest(t_stack *a, t_stack *b, int moves, int least);
void	ft_set_cheapest(t_stack *stack, t_stack *cheapest);
void	ft_set_targets_a(t_stack **a, t_stack **b);
void	ft_set_targets_b(t_stack **b, t_stack **a);
t_stack	*ft_find_smallest(t_stack *stack);
t_stack	*ft_find_biggest(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b);

#endif
