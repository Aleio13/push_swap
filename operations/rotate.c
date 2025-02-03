/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:19 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:37:28 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack_a)
{
	t_list	*head;
	t_list	*bottom;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	bottom = *stack_a;
	while (bottom->next != NULL)
		bottom = bottom->next;
	*stack_a = head->next;
	(*stack_a)->prev = NULL;
	head->next = NULL;
	head->prev = bottom;
	bottom->next = head;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
