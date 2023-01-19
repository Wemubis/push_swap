/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:48 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 18:55:47 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_pile stack)
{
	while ((*stack.a)->next)
		printf("%d", (*stack.a)->data);
	// if (check_if_sorted(stack.a))
	// 	exit(EXIT_SUCCESS);
	// if (size_stack(stack.a) <= 5)
	// 	sort_small(stack);
	// if (size_stack(stack.a) <= 100)
	// 	sort_big(stack);
	// if (size_stack(stack.a) <= 500)
	// 	sort_huge(stack);
}
