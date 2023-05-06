
// int	best_move_to_b(t_meta	*meta, t_node	*lis)
// {
// 	int		tmp[2];
// 	int		bmb[2];
// 	t_node	*iterator;
// 	int		found_move;

// 	iterator = meta->stack_a;
// 	found_move = 0;
// 	while (iterator)
// 	{
// 		if (ll_is_in(lis, iterator->value) == -1)
// 		{
// 			bmb[0] = iterator->value;
// 			bmb[1] = moves_needed_to_top(meta->stack_a, iterator->value);
// 			found_move = 1;
// 			break;
// 		}
// 		iterator = iterator->next;
// 	}
// 	if (!found_move)
// 		return 0;
// 	iterator = meta->stack_a;
// 	while (iterator)
// 	{
// 		if (ll_is_in(lis, iterator->value) == -1)
// 		{
// 			tmp[0] = iterator->value;
// 			tmp[1] = moves_needed_to_top(meta->stack_a, iterator->value);
// 			if (abs(tmp[1]) < abs(bmb[1]))
// 			{
// 				bmb[0] = tmp[0];
// 				bmb[1] = tmp[1];
// 			}
// 		}
// 		iterator = iterator->next;
// 	}
// 	printf("val %d mvs %d\n", bmb[0], bmb[1]);
// 	rotate_to_top(&meta->stack_a, bmb[0], ra, rra);
// 	pb(&meta->stack_a, &meta->stack_b);
// 	return (1);
// }

