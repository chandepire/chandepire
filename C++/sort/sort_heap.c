#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

typedef struct p_data
{
	int p[NUM+1];
	int length;
}p_data;

void swap(int p[],int i,int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void heap(int p[],int s,int e)
{
	int j,temp = p[s];
	for(j=2*s;j<=e;j=j*2)
	{
		if(j < e && p[j] < p[j+1])
			++j;
		if(temp > p[j])
			break;
		p[s] = p[j];
		s = j;
	}
	p[s] = temp;
}

void sort_heap(int p[],int num,int len)
{
	//int len = num/2;
	for(int i=len;i>0;--i)
		heap(p,i,num);

	/*for(int i = num;i>1;--i)
	{
		swap(p,1,i);
		heap(p,1,i-1);
	}*/
}


int main()
{
	srand(time(0));
	int p[NUM+1]={0};
	for(int i = 1;i<=NUM;++i)
	{
		p[i] = rand()%50;
		printf("%d ",p[i]);
	}
	printf("\n\n");
	clock_t start = clock();
	sort_heap(p,NUM,3);
	clock_t end =   clock();
	for(int i = 1;i<=NUM;++i)
	{
		printf("%d ",p[i]);
	}
	printf("\n\ntime: %f \n\n",difftime(end,start));

	return 0;
}
