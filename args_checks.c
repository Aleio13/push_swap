/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:04:52 by almatsch          #+#    #+#             */
/*   Updated: 2025/01/11 12:46:36 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(int pos, int num, char **args)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = args[pos];
	while (i < pos)
	{
		if (ft_atoi(args[i]) == num)
			return (0);
		if (ft_atoi(args[i]) == 2147483648)
			return (0);
		i++;
	}
	i = 0;
	if (tmp[i] == '-' || tmp[i] == '+')
		i++;
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (num < -2147483648 || num > 2147483647)
			return (0);
		if (!validation(i, (int)num, args))
			return (0);
		i++;
	}
	return (1);
}
