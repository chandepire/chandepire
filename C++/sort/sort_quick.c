#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 2000000


void swap(int p[],int i,int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

int partition(int p[],int i,int j)
{
		int m = i + (j - i)/2;
		if(p[i] > p[j])
			swap(p,i,j);
		if(p[m] > p[j])
			swap(p,m,j);
		if(p[m] > p[i])
			swap(p,m,i);
		
		int base = p[i]; 
		while(i < j)
		{
			while(i < j && p[j] >= base)
				--j;
			p[i] = p[j];
			while(i < j && p[i] <= base)
				++i;
			p[j] = p[i];
		}
		p[i] = base;
	return i;
}

void Qquick(int p[],int begin,int end)
{
	int pivot;
	while(begin < end)
	{
		pivot = partition(p,begin,end);
		Qquick(p,begin,pivot - 1);
		begin = pivot+1;
	}
}

void sort_quick(int p[],int num)
{
	Qquick(p,0,num-1);
}	


int main()
{
	srand(time(0));
	int p[NUM]={0};
	for(int i = 0;i<NUM;++i)
	{
		p[i] = rand()%5000;
		printf("%d ",p[i]);	
	}
	printf("\n\n");	
	clock_t start = clock();
	sort_quick(p,NUM);
	clock_t end =   clock();
	for(int i = 0;i<NUM;++i)
	{
		printf("%d ",p[i]);	
	}
	printf("\n\ntime: %f \n\n",difftime(end,start));

	return 0;
}	
