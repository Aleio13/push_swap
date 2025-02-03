/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:28:09 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 17:03:25 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_bit(int index, int i)
{
	if ((index >> i) & 1)
		return (1);
	else
		return (0);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	m_bit;
	int	l_size;
	int	i;
	int	j;

	if (sort_check(stack_a) == 1)
		return ;
	m_bit = find_max_bit(stack_a);
	l_size = ft_lstsize(*stack_a);
	i = 0;
	while (i < m_bit)
	{
		j = 0;
		while (j < l_size)
		{
			if (get_bit((*stack_a)->index, i) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
