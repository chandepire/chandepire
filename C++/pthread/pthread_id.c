#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *create(void *arg)
{	
	printf("create new pthread!");
	printf("this thread's id is %u\n",(unsigned int)pthread_self());
	printf("this process'id is %d\n",getpid());
	return (void *)0;
}

int main()
{
	pthread_t pid;
	int error;
	error = pthread_create(&pid,NULL,create,NULL);
	if(error)
	{
		return 1;
	}
	sleep(1);
	printf("the main process is id :%d\n",getpid());
	
	return 0;
}
