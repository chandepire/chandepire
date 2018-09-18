#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *myThread1(void)
{
	int i;
	for(int i=0;i<100;++i)
	{
		printf("%d:pthread1\n",i);
		sleep(1);
	}
}

void *myThread2(void)
{
	int i;
	for(int i=0;i<100;++i)
	{
		printf("%d:pthread2\n",i);
		sleep(1);
	}
}

int main()
{
	int i=0,ret=0;
	pthread_t id1,id2;
	printf("OK!\n");
	ret = pthread_create(&id1,NULL,(void*)myThread1,NULL);
	if(ret)
	{
		printf("pthread1 error");
		return 1;
	}
	ret = pthread_create(&id2,NULL,(void*)myThread2,NULL);
	if(ret)
	{
		printf("pthread2 error");
		return 1;
	}

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}

