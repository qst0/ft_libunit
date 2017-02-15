/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:35:42 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 19:37:31 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

char			*ft_strdup(const char *s1)
{
	char		*copy;
	int			len;

	len = 0;
	while (s1[len])
		len++;
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	len = 0;
	while (s1[len])
	{
		copy[len] = s1[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

t_test_list		*new_test(char *name, int (*test_func)(void))
{
	t_test_list	*new_test;
	if (!(new_test = malloc(sizeof(t_test_list))))
		return (0);
	new_test->name = ft_strdup(name);
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

#include <stdio.h>

void catch_bus(int data)
{
	exit(data);
}

void catch_seg(int data)
{
	exit(data);
}

int			launch_tests(t_test_list *test_list)
{
	t_test_list		*cur;
	t_test_result	res;
	pid_t			child_pid;
	int				status;

	signal(10, catch_bus);
	signal(11, catch_seg);
	res.seg = 0;
	res.bus = 0;
	res.pass = 0;
	res.fail = 0;
	res.count = 0;
	cur = test_list;
	while (cur)
	{
		if ((child_pid = fork()) == 0)
			exit(cur->test_func());
		wait(&status);
		printf("%s %s\n", cur->name, status ? "FAIL" : "PASS");
		res.count++;
		if (status == 0)
			res.pass++;
		if (status == 2560)
			res.bus++;
		if (status == 2816)
			res.seg++;
		if (status == 65280)
			res.fail++;

		cur = cur->next;
	}

	printf("\n"
			"bus: %d\n"
			"seg: %d\n"
			"fail: %d\n"
			"pass: %d\n"
			"total: %d\n"
			, res.bus, res.seg, res.fail, res.pass, res.count);
	return (res.pass != res.count ? -1 : 0);
}
