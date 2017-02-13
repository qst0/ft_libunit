/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:25:38 by myoung            #+#    #+#             */
/*   Updated: 2017/02/13 12:05:06 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct	s_test_list
{
	void				(*test_func)(void);
	char					*name;
	struct s_test_list		*next;
}				t_test_list;

t_test_list	*new_test(char *name, void (*test_func)(void));
void		add_test(t_test_list *list, char *name, void (*func)(void));
void		load_test(t_test_list *list, char *name, void (*func)(void));
void		launch_tests(t_test_list *test_list, int *pass, int *count);
