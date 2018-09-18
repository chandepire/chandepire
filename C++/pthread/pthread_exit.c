#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <malloc.h>
void *create(void *arg)
{	
	int *a = (int *)malloc(sizeof(int));
	*a = 8;
	printf("create pthread ...\n");
	return (void *)(a);
}

int main()
{	
	pthread_t pid;
	int error;
	void *temp;
	error = pthread_create(&pid,NULL,create,NULL);
	if(error)
	{
		printf("creaet error");
		return 1;
	}
	error = pthread_join(pid,&temp);
	if(error)
	{
		printf("pthread is not exit...\n");
		return -2;
	}
	sleep(5);
	int *value = (int *)temp;
	printf("exit code is %d!",(int)(*value));
	
	return 0;
}
