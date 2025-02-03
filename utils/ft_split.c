/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:48:16 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/02 15:48:16 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			w_count++;
		}
	}
	return (w_count);
}

static int	word_size(char const *s, char c, int *w_start)
{
	int	w_len;

	w_len = 0;
	while (s[*w_start] != c && s[*w_start] != '\0')
	{
		w_len++;
		(*w_start)++;
	}
	return (w_len);
}

char	*word_find(char const *s, char c, int *w_start)
{
	int		i;
	int		w_len;
	char	*word;

	w_len = word_size(s, c, w_start);
	word = malloc((w_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < w_len)
	{
		word[i] = s[*w_start - w_len + i];
		i++;
	}
	word[w_len] = '\0';
	return (word);
}

char	**make_matrix(char const *s, char c, char **matrix, int *m_index)
{
	int	w_start;

	w_start = 0;
	while (s[w_start] != '\0')
	{
		while (s[w_start] == c)
			w_start++;
		if (s[w_start] != c && s[w_start] != '\0')
		{
			matrix[*m_index] = word_find(s, c, &w_start);
			if (matrix[*m_index] == NULL)
			{
				while (*m_index > 0)
					free(matrix[--(*m_index)]);
				free(matrix);
				return (NULL);
			}
			(*m_index)++;
		}
	}
	matrix[*m_index] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		m_size;
	int		m_index;

	if (s == NULL)
		return (NULL);
	m_size = word_count(s, c);
	matrix = malloc((m_size + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	m_index = 0;
	return (make_matrix(s, c, matrix, &m_index));
}
