/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_atoi_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:22:04 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 22:35:08 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_tests.h>
#include <libunit.h>

int		atoi_launcher(void)
{
	t_test_list *tests;

	tests = new_test("atoi min", test_ft_atoi_min);
	add_test(tests, "atoi max", test_ft_atoi_max);
	add_test(tests, "atoi hard", test_ft_atoi_hard);
	add_test(tests, "atoi medium", test_ft_atoi_medium);
	add_test(tests, "atoi easy", test_ft_atoi_easy);
	add_test(tests, "atoi veryhard", test_ft_atoi_veryhard);
	add_test(tests, "atoi none", test_ft_atoi_none);
	return (launch_tests(tests));
}
