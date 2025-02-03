/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:47:41 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:47:41 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct dl_list
{
	int				number;
	int				index;
	struct dl_list	*prev;
	struct dl_list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
long	ft_atoi(const	char *str);
int		ft_isdigit(int i);
int		is_valid(char **args);
int		ft_lstsize(t_list *lst);
void	free_all(char **args, t_list *stack_a, t_list *stack_b);
void	create_stack(int argc, char **argv, t_list **stack_a);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack_a);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	hard_sort(t_list **stack_a, t_list **stack_b);
void	small_to_b(t_list **stack_a, t_list **stack_b);
int		sort_check(t_list **stack_a);
int		find_smallest(t_list **stack_a);
void	create_index(t_list **stack_a);
int		find_max_bit(t_list **stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif
