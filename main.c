/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:29:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 21:38:05 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *stack)
{
	stack->as = 0;
	stack->at = 0;
	stack->ab = 0;
	stack->bs = 0;
	stack->bt = 0;
	stack->bb = 0;
	stack->comm = 0;
}

void	small_size_sort(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->at->n;
	second = stack->at->next->n;
	third = stack->ab->n;
	if (stack_is_sort(stack))
		return ;
	if (third > first && first > second)
		swap_a(stack);
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first > third && third > second)
		rotate_a(stack);
	else if (second > third && third > first)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else
		reverse_rotate_a(stack);
}

void	small_size_sort_b(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->bt->n;
	second = stack->bt->next->n;
	third = stack->bb->n;
	if (stack->bs == 2 && first < third)
		swap_b(stack);
	else if (third > second && second > first)
	{
		rotate_b(stack);
		swap_b(stack);
	}
	else if (second > third && third > first)
		rotate_b(stack);
	else if (third > first && first > second)
		reverse_rotate_b(stack);
	else if (second > first && first > third)
		swap_b(stack);
	else
	{
		swap_b(stack);
		rotate_b(stack);
	}
}

void	six_under_sort(t_stack *stack)
{
	while (stack->as > 3)
		push_b(stack);
	small_size_sort(stack);
	if (stack->bs > 1)
		small_size_sort_b(stack);
	while (stack->bs > 0)
	{
		if (stack->bt->n > stack->ab->n || \
		(stack->at->n > stack->bt->n && \
			stack->ab->n > stack->bt->n && \
			stack->ab->n > stack->at->n))
			push_a(stack);
		else if (stack->ab->n > stack->bt->n)
			reverse_rotate_a(stack);
		if (stack->bs && \
		stack->at->n < stack->ab->n && stack->at->n > stack->bt->n)
			push_a(stack);
	}
	while (!stack_is_sort(stack))
		reverse_rotate_a(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init(&stack);
	if (!argv_to_stack(&stack, ++argv))
		print_error(&stack);
	if (stack_is_sort(&stack))
	{
		clear_stack(&stack);
		return (0);
	}
	if (stack.as == 2)
		swap_a(&stack);
	else if (stack.as == 3)
		small_size_sort(&stack);
	else if (stack.as < 7)
		six_under_sort(&stack);
	else
		stack_sort(&stack);
	clear_stack(&stack);
	print_command(&stack);
	clear_commands(&stack);
	return (0);
}
