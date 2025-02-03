/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:23:05 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:37:07 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_check(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return (1);
	tmp = (*stack_a);
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_smallest(t_list **stack_a)
{
	t_list	*small;
	t_list	*tmp;
	int		pos;
	int		i;

	tmp = (*stack_a);
	small = (*stack_a);
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (small->number > tmp->number)
		{
			small = tmp;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	small_to_b(t_list **stack_a, t_list **stack_b)
{
	int	lst_len;
	int	small_pos;
	int	i;

	small_pos = find_smallest(stack_a);
	lst_len = ft_lstsize(*stack_a);
	if (small_pos <= lst_len / 2)
	{
		i = 0;
		while (i < small_pos)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < lst_len - small_pos)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
}

int	find_max_bit(t_list **stack_a)
{
	int	m_val;
	int	bit;

	m_val = ft_lstsize(*stack_a) - 1;
	bit = 0;
	while (m_val >> bit)
		bit++;
	return (bit);
}
