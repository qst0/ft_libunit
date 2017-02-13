#include <libunit.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#include <stdio.h>

/* testing with an example to make sure I understand */

void	catch_bus(int data)
{
	printf("\nBUS and pid, %d %d\n\n", data, (int)getpid());
	exit(0);
}

void	catch_seg(int data)
{
	printf("\nSEG and pid, %d %d\n\n", data, (int)getpid());
	exit(0);
}

void	something(void)
{
	printf("Something\n");
}

void	make_bus(void)
{
	char *str = "Hello Bus Error!";
	str[2] = 'm';
	printf("no bus?\n");
}

int main(void)
{
	//pid_t child_pid;
	//pid_t wpid;
	//int status = 0;
	//int i;
	//int	*make_a_seg;
	int pass;
	int count;
	t_test_list *tests;

	signal(10, catch_bus);
	signal(11, catch_seg);
	pass = 0;
	count = 0;
	tests = new_test("Test 0", something);
	add_test(tests, "Test 1", make_bus);
	add_test(tests, "Test 2", something);
	launch_tests(tests, &pass, &count);
	printf("tests: pass: %d count: %d", pass, count);
	/*
	printf("parent_pid = %d\n", getpid());
	for (i = 0; i < 6 ; i++)
	{
		printf("i = %d\n", i);
		if ((child_pid = fork()) == 0)
		{
			printf("In child process (pid = %d)\n", getpid());
			if (i == 0)
				raise(SIGSEGV);
			else if (i == 1)
				raise(SIGBUS);
			else
			{
				printf("Loop what am I doing here");
				exit(3);
			}
		}
	}
	*/
/*
	while ((wpid = wait(&status)) > 0)
	{
		printf("Exit status of %d was %d (%s)\n", (int)wpid, status,
				(status > 0) ? "accept" : "reject");
	}
	*/
	return (0);
}
