/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:35:42 by myoung            #+#    #+#             */
/*   Updated: 2017/02/13 14:21:53 by myoung           ###   ########.fr       */
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

void			launch_tests(t_test_list *test_list, int *pass, int *count)
{
	int status;
	t_test_list *cur;
	pid_t wpid;
	pid_t child_pid;

	cur = test_list;
	while (cur)
	{
		if ((child_pid = fork()) == 0)
		{
			*count = *count + 1;
			printf("pid: %d\tname: %s\n", getpid(), cur->name);
			cur->test_func();
			(*pass)++;
			exit(0);
		}
		cur = cur->next;
	}
	printf("All tests Launched.\n Waiting for results.\n");

	while ((wpid = wait(&status)) > 0)
	{
		printf("Exit status of %d was %d\n", (int)wpid, status);
	}
}
