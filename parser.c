/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:34:29 by almatsch          #+#    #+#             */
/*   Updated: 2025/01/12 18:36:58 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **args, t_list *stack_a, t_list *stack_b);

void	append_args(t_list *new_num, t_list **stack_a)
{
	t_list	*current_num;

	current_num = *stack_a;
	while (current_num->next)
		current_num = current_num->next;
	current_num->next = new_num;
	new_num->prev = current_num;
}

void	atos(t_list **stack_a, char **args, int argc)
{
	t_list			*new_num;
	unsigned int	index;

	index = 0;
	while (args[index] != NULL)
	{
		new_num = malloc(sizeof(t_list));
		if (new_num == NULL)
		{
			if (argc == 2)
				free_all(args, *stack_a, NULL);
			else
				free_all(NULL, *stack_a, NULL);
			write (2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		new_num->number = ft_atoi(args[index]);
		new_num->next = NULL;
		new_num->prev = NULL;
		if (*stack_a == NULL)
			*stack_a = new_num;
		else
			append_args(new_num, stack_a);
		index++;
	}
}

void	free_all(char **args, t_list *stack_a, t_list *stack_b)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}
}

void	create_stack(int argc, char **argv, t_list **stack_a)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
		{
			write (2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	else
		args = argv + 1;
	if (!is_valid(args))
	{
		if (argc == 2)
			free_all(args, NULL, NULL);
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	atos(stack_a, args, argc);
	if (argc == 2)
		free_all(args, NULL, NULL);
}
