/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:35:42 by myoung            #+#    #+#             */
/*   Updated: 2017/02/12 22:55:53 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

#include <stdio.h>

t_test_list		*new_test(char *name, void (*test_func)(void))
{
	t_test_list	*new_test;
	if (!(new_test = malloc(sizeof(t_test_list))))
		return (0);
	new_test->name = name;
	new_test->test_func = test_func;
	return (new_test);
}

void			add_test(t_test_list *test_list, char *name, void (*test_func)(void))
{
	t_test_list *cur;

	cur = test_list;
	while(cur->next)
		cur = cur->next;
	cur->next = new_test(name, test_func);
	cur = test_list;
}

void			load_test(t_test_list *test_list, char *name, void (*test_func)(void))
{
	if (!test_list)
		test_list = new_test(name, test_func);
	else
		add_test(test_list, name, test_func);
}

void			launch_tests(t_test_list *test_list)
{
	t_test_list *cur;

	cur = test_list;
	while (cur)
	{
		printf("cur name: %s", cur->name);

		cur = cur->next;
	}
	printf("Never Reached");
}
