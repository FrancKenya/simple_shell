#include <stdio.h>
#include <unistd.h>
/**
* main - prints PID of parent's process
* Return: 0 for success
*/
int main(void)
{
	pid_t i;

	i = getppid();
	printf("%u\n", i);
	return (0);
}
