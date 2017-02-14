#include <libunit.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void	catch_bus(int data)
{
	exit(data);
}

void	catch_seg(int data)
{
	exit(data);
}

void	make_pass(void)
{
	exit(0);
}

void	make_fail(void)
{
	exit(-1);
}

void	make_bus(void)
{
	char *str = "Hello Bus Error!";
	str[2] = 'm';
	printf("no bus?\n");
}

void	make_seg(void)
{
	int *ptr;

	sleep(1);
	ptr = 0;
	*ptr = -42;
	printf("no seg??\n");
}

int main(void)
{
	t_test_list *tests;

	signal(10, catch_bus);
	signal(11, catch_seg);

	tests = new_test("Dummy_pass: ", make_pass);
	add_test(tests, "Dummy_bus: ", make_bus);
	add_test(tests, "Dummy_seg: ", make_seg);
	add_test(tests, "Dummy_fail: ", make_fail);
	launch_tests(tests);
	
	/* Wait for and tally test results */

	pid_t wpid;
	int status;
	
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
	while ((wpid = wait(&status)) > 0)
	{
		printf("Exit status of %d was %d\n", (int)wpid, status);
		count++;
		if (status == 0)
			pass++;
		if (status == 2560)
			bus++;
		if (status == 2816)
			seg++;
		if (status == 65280)
			fail++;
	}



	/*Print Results */
	printf("\n"
			"bus: %d\n"
			"seg: %d\n"
			"fail: %d\n"
			"pass: %d\n"
			"total: %d\n"
			, bus, seg, fail, pass, count);
	return (pass != count ? -1 : 0);
}
