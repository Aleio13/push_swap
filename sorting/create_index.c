/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:57:51 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:36:49 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_index(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*current;
	int		index;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	index = 0;
	while (index < ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		current = NULL;
		while (tmp)
		{
			if (tmp->index == -1 && (!current || tmp->number < current->number))
				current = tmp;
			tmp = tmp->next;
		}
		if (current)
			current->index = index++;
	}
}
