#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t p;
	printf("Starting the fork\n");
	p = fork();

	if(p == 0)
	{
		printf("I am a child process: %d\n", getpid());
		printf("My parent id is %d\n", getppid());
	}
	else
	{
		printf("I am parent process: %d\n", getpid());
		printf("My child is %d\n", p);
		sleep(100);
		wait(NULL);
	}
}
