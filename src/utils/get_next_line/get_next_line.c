/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:59:44 by dosokin           #+#    #+#             */
/*   Updated: 2024/08/03 18:22:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file_and_push_to_stack(char **stack, int fd)
{
	int		r;
	char	*buffer;

	if (!stack || !*stack || BUFFER_SIZE < 0)
		return (-1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	r = read(fd, buffer, BUFFER_SIZE);
	if (r <= 0)
	{
		free(buffer);
		return (r);
	}
	*stack = ft_strjoin_special(*stack, buffer);
	if (!*stack)
		return (-1);
	return (r);
}

static void	trunc_stack(char **stack, const int new_line_index)
{
	int		i;
	int		j;
	char	*stack_copy;

	i = new_line_index + 1;
	stack_copy = ft_strdup(*stack);
	if (!stack_copy)
		return ;
	free(*stack);
	*stack = malloc(ft_strlen(stack_copy) - i + 1);
	if (!*stack)
	{
		free(stack_copy);
		return ;
	}
	j = 0;
	while (stack_copy[i])
		(*stack)[j++] = stack_copy[i++];
	(*stack)[j] = 0;
	free(stack_copy);
}

static char	*end_of_process(char **stack, enum e_exit_type t)
{
	char	*tempo;

	tempo = NULL;
	if (!stack || !*stack)
		return (NULL);
	if (t == EOF && ft_strlen(*stack))
		tempo = ft_strdup(*stack);
	free(*stack);
	*stack = NULL;
	return (tempo);
}

static char	*return_line(char **stack, const int new_line_index)
{
	char	*stack_copy;
	char	*result;

	if (!stack || !*stack)
		return (NULL);
	stack_copy = ft_strdup(*stack);
	if (!stack_copy)
		return (end_of_process(stack, ERR));
	stack_copy[new_line_index + 1] = 0;
	result = ft_strdup(stack_copy);
	free(stack_copy);
	if (!result)
		return (end_of_process(stack, ERR));
	trunc_stack(stack, new_line_index);
	if (!*stack)
	{
		free(result);
		return (end_of_process(stack, ERR));
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	int			r;
	int			i;

	if (fd < 0)
		return (NULL);
	if (!stack)
		stack = ft_calloc(1, sizeof(char));
	while (stack)
	{
		i = find_new_line(stack);
		if (i != -1)
			return (return_line(&stack, i));
		r = read_file_and_push_to_stack(&stack, fd);
		if (r > 0)
			continue ;
		if (r < 0)
			break ;
		return (end_of_process(&stack, EOF));
	}
	return (end_of_process(&stack, ERR));
}
