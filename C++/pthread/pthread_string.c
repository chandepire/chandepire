#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *create(void *arg)
{
	char *str = (char *)arg;
	printf("%s\n",str);
	return (void *)0;
}
int main()
{
	pthread_t pid;
	int error;
	char *str = "hello world!";
	error = pthread_create(&pid,NULL,create, (void *)str);
	if(error)
	{
		printf("create error");
		return 1;
	}
	sleep(10);
	printf("OK!");
	
	
	return 0;
}
