#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int a = 4;
void *create(void *arg)
{
	printf("input pthread!\nthe data a is :%d\n",a);
	
	return (void *)0;
}
int main()
{
	pthread_t pid;
	a = 10;
	int error;
	error = pthread_create(&pid,NULL,create,NULL);
	if(error)
	{
		printf("create error!\n");
		return 1;
	}
	sleep(1);
	printf("create pthread is OK!\n");
	return 0;
}
