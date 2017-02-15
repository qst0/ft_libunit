/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_atoi_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:22:04 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:31:44 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_tests.h>
#include <libunit.h>

int		atoi_launcher(void)
{
	t_test_list *tests;

	tests = new_test("strcmp str1:", test_ft_strcmp_str1);
	add_test(tests, "strcmp str2", test_ft_strcmp_str2);
	add_test(tests, "strcmp str3", test_ft_strcmp_str3);
	add_test(tests, "strcmp str4", test_ft_strcmp_str4);
	add_test(tests, "strcmp str5", test_ft_strcmp_str5);
	add_test(tests, "strcmp str6", test_ft_strcmp_str6);
	add_test(tests, "strcmp str7", test_ft_strcmp_str7);
	add_test(tests, "strcmp str8", test_ft_strcmp_str8);
	return (launch_tests(tests));
}
