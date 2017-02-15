/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:25:38 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 18:43:26 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIB_UNIT_H
# define LIB_UNIT_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct	s_test_result
{
	int						pass;
	int						fail;
	int						count;
	int						bus;
	int						seg;
}				t_test_result;

typedef struct	s_test_list
{
	int						(*test_func)(void);
	char					*name;
	int						pid;
	struct s_test_list		*next;
}				t_test_list;

t_test_list	*new_test(char *name, int (*test_func)(void));
void		add_test(t_test_list *list, char *name, int (*func)(void));
int			launch_tests(t_test_list *test_list);

#endif
