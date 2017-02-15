/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:35:42 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 23:17:23 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

t_test_list		*new_test(char *name, int (*test_func)(void))
{
	t_test_list	*new_test;
	if (!(new_test = malloc(sizeof(t_test_list))))
		return (0);
	new_test->name = unit_strdup(name);
	new_test->test_func = test_func;
	new_test->next = 0;
	return (new_test);
}

void			add_test(t_test_list *test_list, char *name, int (*test_func)(void))
{
	t_test_list *cur;

	cur = test_list;
	while (cur && cur->next)
		cur = cur->next;
	cur->next = new_test(name, test_func);
	cur = test_list;
}

void catch_bus(int data)
{
	exit(data);
}

void catch_seg(int data)
{
	exit(data);
}

t_test_result		new_test_result(void)
{
	t_test_result	res;

	res.seg = 0;
	res.bus = 0;
	res.pass = 0;
	res.fail = 0;
	res.count = 0;
	return (res);
}

int					launch_tests(t_test_list *test_list)
{
	t_test_list		*cur;
	t_test_result	res;
	pid_t			child_pid;
	int				status;

	signal(10, catch_bus);
	signal(11, catch_seg);
	res = new_test_result();
	cur = test_list;
	while (cur)
	{
		if ((child_pid = fork()) == 0)
			exit(cur->test_func());
		unit_puts(cur->name);
		wait(&status);
		res.count++;
		if (status == 0)
		{
			res.pass++;
			unit_puts("PASS\n");
		}
		if (status == 2560)
		{
			res.bus++;
			unit_puts("BUS\n");	
		}
		if (status == 2816)
		{
			res.seg++;
			unit_puts("SEG\n");
		}
		if (status == 65280)
		{
			res.fail++;
			unit_puts("FAIL\n");
		}
		cur = cur->next;
	}

	unit_puts("\n");

	unit_puts("\n");
	unit_putn(1337);
	unit_puts("\n");


	unit_puts("bus: ");
	res.bus ? unit_putn(res.bus) : unit_puts("0");
	unit_puts("\n");
	unit_puts("seg: ");
	res.seg ? unit_putn(res.seg) : unit_puts("0");
	unit_puts("\n");
	unit_puts("fail: ");
	res.fail ? unit_putn(res.fail) : unit_puts("0");
	unit_puts("\n");
	unit_puts("pass: ");
	res.pass ? unit_putn(res.pass) : unit_puts("0");
	unit_puts("\n");
	unit_puts("total: ");
	res.count ? unit_putn(res.count) : unit_puts("0");
	unit_puts("\n");
	return (res.pass != res.count ? -1 : 0);
}
