/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:00:33 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 22:33:21 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS
#define UNIT_TESTS
# include <libunit.h>

int		demo_launcher(void);
int		demo_pass(void);
int		demo_seg(void);
int		demo_bus(void);
int		demo_fail(void);

int		atoi_launcher(void);
int		test_ft_atoi_launcher(void);
int		test_ft_atoi_min(void);
int		test_ft_atoi_max(void);
int		test_ft_atoi_hard(void);
int		test_ft_atoi_medium(void);
int		test_ft_atoi_easy(void);
int		test_ft_atoi_veryhard(void);
int		test_ft_atoi_none(void);


#endif
