/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:03:20 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 20:15:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
	command_insert(stack, "sa\n");
}

void	swap_b(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
	command_insert(stack, "sb\n");
}

void	swap_all(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
	command_insert(stack, "ss\n");
}
