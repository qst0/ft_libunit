#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#include <stdio.h>

/* testing with an example to make sure I understand */

void	catch_bus(int data)
{
	printf("bus, %d\n", data);
	exit(0);
}

void	catch_seg(int data)
{
	printf("seg, %d\n", data);
	exit(0);
}

int main(void)
{
	pid_t child_pid;
	pid_t wpid;
	int status = 0;
	int i;
	int a[3] = {1, 2, 1};

	signal(10, catch_bus);
	signal(11, catch_seg);
	printf("parent_pid = %d\n", getpid());
	for (i = 0; i < 6 ; i++)
	{
		printf("i = %d\n", i);
		if ((child_pid = fork()) == 0)
		{
			printf("In child process (pid = %d)\n", getpid());
			if (a[i] < 2)
			{
				printf("Should be accept\n");
				exit(1);
			}
			else if (i == 3)
			{
				printf("nope? %d\n", a[4000]);
				exit(1);
			}
			else if (i == 4)
			{
				raise(SIGBUS);
				printf("no bus?");
				exit(1);
			}
			else
			{
				printf("Should be reject\n");
				exit(0);
			}
			/*NOTREACHED*/
		}
	}

	while ((wpid = wait(&status)) > 0)
	{
		printf("Exit status of %d was %d (%s)\n", (int)wpid, status,
				(status > 0) ? "accept" : "reject");
	}
	return 0;
}
