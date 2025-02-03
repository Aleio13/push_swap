/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:59:30 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:37:23 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **stack_a)
{
	t_list	*head;
	t_list	*bottom;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	bottom = *stack_a;
	while (bottom->next != NULL)
		bottom = bottom->next;
	if (head->next == bottom)
	{
		swap(stack_a);
		return ;
	}
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = head;
	head->prev = bottom;
	*stack_a = bottom;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
