/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:28:55 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:37:37 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack_a;
	tmp->prev = NULL;
	tmp->next = *stack_a;
	(*stack_a)->prev = tmp;
	*stack_a = tmp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
