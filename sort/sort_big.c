/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:34:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/03 23:40:00 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_a(t_pile *a, t_pile *b, int chunk_size[2])
{
	int	i;
	int	value_chunk[10];

	i = -1;
	while (++i < 9)
		value_chunk[i] = chunk_size[0] / 2 * (i + 1);
	value_chunk[i] = b->size;
	while (value_chunk[i])
	{
		chunk_size[1] = chunk_size[0] / 2;
		while (chunk_size[1] && b->size)
		{
			if (i % 2 == 1)
				sort_chunk_a(a, b);
			else if (i % 2 == 0)
			{
				rrb(b);
				sort_chunk_a(a, b);
			}
			chunk_size[1]--;
		}
		if (!check_if_sorted(a->head, a->size))
			sort_a(a);
		i--;
	}
}

static void	after_pb(t_pile *a, t_pile *b, int chunk_size, int val_chunk)
{
	int		half;
	t_stack	*tmp;
	t_stack	*nexto;

	half = chunk_size / 2;
	tmp = b->head;
	nexto = b->head->next;
	printf("Hey knut");
	if (a->head->data > val_chunk && tmp->data < (val_chunk - half))
		rr(a, b);
	else if (a->head->data < val_chunk && tmp->data < (val_chunk - half))
		rb(b);
	else if (a->head->data > val_chunk)
		ra(a);
	else if  (tmp->data < nexto->data && tmp->data < nexto->next->data)
	{
		rb(b);
		sb(b);
		rrb(b);
	}
	else if (tmp->data < nexto->data && tmp->data > nexto->next->data)
		sb(b);
}

static void	put_in_b(t_pile *a, t_pile *b, int chunk_size[2], int value_chunk[5])
{
	int	i;
	
	i = 0;
	printf("before the loop");
	while (value_chunk[i])
	{
		printf("In big loop");
		chunk_size[1] = chunk_size[0];
		while (chunk_size[1] && a->size)
		{
			if (a->head->data < value_chunk[i])
				pb(a, b);
			printf("after pb tu connais");
			after_pb(a, b, chunk_size[0], value_chunk[i]);
			chunk_size[1]--;
		}
		if (a->size && i == 4)
		{
			while (a->size)
			{
				pb(a, b);
				printf("after pb tu connais V2222222");
				after_pb(a, b, chunk_size[0], value_chunk[i]);
			}
		}
		i++;
	}
}

void	sort_big(t_pile *a, t_pile *b)
{
	int	i;
	int	chunk_size[2];
	int	value_chunk[5];

	replace_data_with_rank(a);
	printf("before the chunking");
	if (check_if_sorted(a->head, a->size))
		return ;
	chunk_size[0] = a->size / 5;
	i = -1;
	while (++i < 4)
		value_chunk[i] = chunk_size[0] * (i + 1);
	value_chunk[i] = a->size;
	put_in_b(a, b, chunk_size, value_chunk);
	put_in_a(a, b, chunk_size);
}
