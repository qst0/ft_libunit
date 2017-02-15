#include <libunit.h>
#include <unit_tests.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main(void)
{
	printf("****************************\n");
	printf("***   42 - Unit Tests    ***\n");
	printf("****************************\n");
	printf("Demos:\n");
	demo_launcher();
	return (0);
}
