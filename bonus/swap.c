/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:03:20 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 15:49:52 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack *stack)
{
	int		first;
	int		second;

	if (!stack->as)
		return ;
	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
}

void	swap_b(t_stack *stack)
{
	int		first;
	int		second;

	if (!stack->bs)
		return ;
	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
}

void	swap_all(t_stack *stack)
{
	int		first;
	int		second;

	if (!stack->as || !stack->bs)
		return ;
	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
}
