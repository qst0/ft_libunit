#include <unit_tests.h>
#include <libunit.h>

int demo_launcher(void)
{
	t_test_list *tests;

	tests = new_test("demo_pass: ", demo_pass);
	add_test(tests, "demo_bus: ", demo_bus);
	add_test(tests, "demo_seg: ", demo_seg);
	add_test(tests, "demo_fail: ", demo_fail);

	return (launch_tests(tests));
}
