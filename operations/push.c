/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:57:48 by amatschi          #+#    #+#             */
/*   Updated: 2025/01/12 15:28:00 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (*stack_b == NULL)
		return ;
	head_b = (*stack_b)->next;
	head_a = *stack_b;
	if (head_b != NULL)
		head_b->prev = NULL;
	*stack_b = head_b;
	head_a->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = head_a;
	*stack_a = head_a;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
