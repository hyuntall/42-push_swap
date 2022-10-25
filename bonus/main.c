/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:33:17 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/25 18:13:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(t_stack *stack)
{
	stack->as = 0;
	stack->at = 0;
	stack->ab = 0;
	stack->bs = 0;
	stack->bt = 0;
	stack->bb = 0;
}

void	parse_command(t_stack *stack, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		swap_a(stack);
	else if (!ft_strcmp(command, "sb\n"))
		swap_b(stack);
	else if (!ft_strcmp(command, "ss\n"))
		swap_all(stack);
	else if (!ft_strcmp(command, "pa\n"))
		push_a(stack);
	else if (!ft_strcmp(command, "pb\n"))
		push_b(stack);
	else if (!ft_strcmp(command, "ra\n"))
		rotate_a(stack);
	else if (!ft_strcmp(command, "rb\n"))
		rotate_b(stack);
	else if (!ft_strcmp(command, "rr\n"))
		rotate_all(stack);
	else if (!ft_strcmp(command, "rra\n"))
		reverse_rotate_a(stack);
	else if (!ft_strcmp(command, "rrb\n"))
		reverse_rotate_b(stack);
	else if (!ft_strcmp(command, "rrr\n"))
		reverse_rotate_all(stack);
	else
		print_error(stack);
}

void	check_result(t_stack *stack)
{
	if (stack_is_sort(stack) && !stack->bs)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	command_in(t_stack *stack)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		parse_command(stack, command);
		free(command);
		command = 0;
		command = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init(&stack);
	if (!argv_to_stack(&stack, ++argv))
		print_error(&stack);
	command_in(&stack);
	check_result(&stack);
	clear_stack(&stack);
	return (0);
}
