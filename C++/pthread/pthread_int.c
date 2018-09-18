#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void *create(void *arg)
{
	int *num;
	num =(int *)arg;
	for(int i=0;i<10;++i)
		printf("create parameter is %d\n",num[i]);
	return (void *)0;
}



int main()
{
	pthread_t pid;
	int error;

	int test[10] = {11,22,3,42,5,6,7,8,9,10};
	
	error = pthread_create(&pid,NULL,(void *)create,test);
	if(error)
	{
		printf("create error\n");
		return 1;
	}
	sleep(1);
	printf("OK ");
	return 0;
}
