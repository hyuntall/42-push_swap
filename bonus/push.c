/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:15:17 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 15:48:45 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	empty_stack(t_stack *stack)
{
	if (stack->as == 0)
	{
		stack->at = 0;
		stack->ab = 0;
	}
	if (stack->bs == 0)
	{
		stack->bt = 0;
		stack->bb = 0;
	}
}

void	push_b(t_stack *stack)
{
	t_node	*node;

	if (!stack->as)
		return ;
	node = stack->at;
	if (stack->as > 1)
	{
		stack->at = stack->at->next;
		stack->at->prev = 0;
	}
	if (stack->bs == 0)
	{
		node->next = 0;
		stack->bt = node;
		stack->bb = node;
	}
	else
	{
		node->next = stack->bt;
		stack->bt->prev = node;
		stack->bt = node;
	}
	stack->bs += 1;
	stack->as -= 1;
	empty_stack(stack);
}

void	push_a(t_stack *stack)
{
	t_node	*node;

	if (!stack->bs)
		return ;
	node = stack->bt;
	if (stack->bs > 1)
	{
		stack->bt = stack->bt->next;
		stack->bt->prev = 0;
	}
	if (stack->as == 0)
	{
		node->next = 0;
		stack->at = node;
		stack->ab = node;
	}
	else
	{
		node->next = stack->at;
		stack->at->prev = node;
		stack->at = node;
	}
	stack->as += 1;
	stack->bs -= 1;
	empty_stack(stack);
}
