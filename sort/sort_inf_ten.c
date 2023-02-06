/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inf_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:02:39 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/06 21:25:12 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_a(t_pile *a, t_pile *b)
{
	while (b->size != 0)
	{
		pa(a, b);
		if (check_if_sorted(a) == 0)
			sa(a, 0);
	}
}

static void	after_pb(t_pile *a, t_pile *b, int val_chunk)
{
	if (a->head->data >= val_chunk)
		ra(a, 0);
	else if (b->head->data < b->head->next->data)
		sb(b, 0);
}

static void	put_in_b(t_pile *a, t_pile *b, int ch_size, int *value_ch)
{
	int	i;
	
	i = 0;
	while (value_ch[i])
	{
		ch_size = 2;
		while (ch_size != 0 && check_if_sorted(a) != 1)
		{
			if (a->head->data < value_ch[i])
			{
				pb(a, b);
				if (!a->head)
					break ;
				ch_size--;
			}
			else
				after_pb(a, b, value_ch[i]);
		}
		i++;
	}
}

void	sort_inf_ten(t_pile *a, t_pile *b)
{
	int	i;
	int	temp;
	int	ch_size;
	int	*value_ch;

	if (check_if_sorted(a))
		return ;
	if ((a->size % 2) == 0)
		temp = (a->size / 2) - 1;
	else
		temp = (a->size / 2);
	value_ch = malloc(sizeof(int *) * (temp + 1));
	if (!value_ch)
		errors_process("malloc");
	i = -1;
	ch_size = 2;
	while (++i < temp)
		value_ch[i] = ch_size * (i + 1);
	value_ch[i] = a->size;
	put_in_b(a, b, ch_size, value_ch);
	put_in_a(a, b);
	free(value_ch);
}
