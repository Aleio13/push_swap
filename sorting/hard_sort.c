/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:13:52 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:37:00 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_n(t_list **stack_a)
{
	t_list	*top;
	t_list	*mid;
	t_list	*bot;

	top = *stack_a;
	mid = (*stack_a)->next;
	bot = mid->next;
	if (top->number > mid->number && mid->number > bot->number)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top->number > bot->number && bot->number > mid->number)
		ra(stack_a);
	else if (mid->number > top->number && top->number > bot->number)
		rra(stack_a);
	else if (mid->number > bot->number && bot->number > top->number)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top->number > mid->number && bot->number > top->number)
		sa(stack_a);
}

void	sort_4_n(t_list **stack_a, t_list **stack_b)
{
	small_to_b(stack_a, stack_b);
	sort_3_n(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5_n(t_list **stack_a, t_list **stack_b)
{
	small_to_b(stack_a, stack_b);
	sort_4_n(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	int	lst_len;

	lst_len = ft_lstsize(*stack_a);
	if (sort_check(stack_a) == 1)
		return ;
	if (lst_len == 2)
		sa(stack_a);
	if (lst_len == 3)
		sort_3_n(stack_a);
	if (lst_len == 4)
		sort_4_n(stack_a, stack_b);
	if (lst_len == 5)
		sort_5_n(stack_a, stack_b);
}
