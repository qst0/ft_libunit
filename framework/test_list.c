/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:35:42 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 15:00:18 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

#include <stdio.h>

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

t_test_list		*new_test(char *name, void (*test_func)(void))
{
	t_test_list	*new_test;
	if (!(new_test = malloc(sizeof(t_test_list))))
		return (0);
	new_test->name = ft_strdup(name);
	new_test->test_func = test_func;
	new_test->next = 0;
	return (new_test);
}

void			add_test(t_test_list *test_list, char *name, void (*test_func)(void))
{
	t_test_list *cur;

	cur = test_list;
	while (cur && cur->next)
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

int			launch_tests(t_test_list *test_list)
{
	t_test_list	*cur;
	pid_t		child_pid;
	int			status;

	int pass;
	int fail;
	int count;
	int bus;
	int seg;

	seg = 0;
	bus = 0;	
	pass = 0;
	fail = 0;
	count = 0;


	cur = test_list;
	while (cur)
	{
		if ((child_pid = fork()) == 0)
			cur->test_func();
		wait(&status);
		printf("%s %d\n", cur->name, status);
		count++;
		if (status == 0)
			pass++;
		if (status == 2560)
			bus++;
		if (status == 2816)
			seg++;
		if (status == 65280)
			fail++;
	
		cur = cur->next;
	}

	printf("\n"
			"bus: %d\n"
			"seg: %d\n"
			"fail: %d\n"
			"pass: %d\n"
			"total: %d\n"
			, bus, seg, fail, pass, count);
	return (pass != count ? -1 : 0);
}
