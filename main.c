/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:27:17 by almatsch          #+#    #+#             */
/*   Updated: 2025/01/08 16:27:17 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		lst_len;

	if (argc < 2 || argv[1][0] == '\0')
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_a = NULL;
	stack_b = NULL;
	create_stack(argc, argv, &stack_a);
	create_index(&stack_a);
	lst_len = ft_lstsize(stack_a);
	if (lst_len <= 5)
		hard_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_all(NULL, stack_a, stack_b);
	return (0);
}
