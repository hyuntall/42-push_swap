/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:42:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 18:33:41 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

int	ft_atoll(t_stack *stack, char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (!(*str >= '0' && *str <= '9') && !(*str == '-'))
		print_error(stack);
	if (*str == '-')
	{
		sign = 0 - sign;
		str++;
	}
	if (*str < '0' && *str > '9')
		print_error(stack);
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	num = sign * num;
	if (num > 2147483647 || num < -2147483648)
		print_error(stack);
	return (num);
}

char	*join_argv(t_stack *stack, char **argv)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (argv[i])
	{
		ft_atoll(stack, argv[i]);
		tmp = str;
		str = ft_strjoin(str, argv[i++]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
	}
	return (str);
}

int	argv_to_stack(t_stack *stack, char **argv)
{
	int		i;
	char	**sstack;
	char	*str;

	str = join_argv(stack, argv);
	sstack = ft_split(str, ' ');
	free(str);
	if (!sstack)
		return (0);
	i = -1;
	while (sstack[++i])
	{
		if (!stack->at)
			first_insert(stack, ft_atoll(stack, sstack[i]));
		else
			node_insert(stack, ft_atoll(stack, sstack[i]));
		stack->as += 1;
	}
	i = 0;
	while (sstack[i])
		free(sstack[i++]);
	free(sstack);
	return (1);
}
