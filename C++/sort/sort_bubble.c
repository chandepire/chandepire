#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10000
void swap(int p[],int i,int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void sort_bubble1(int p[], int num)
{
	int temp ;
	for(int i=0;i<num-1;++i)
	{	
		for(int j=i+1;j<num;++j)
		{	
			if(p[i] > p[j])
			{
				swap(p,i,j);
			}
		}
	}
}

void sort_bubble2(int p[], int num)
{
	int temp ;
	int flag = 1;
	for(int i=0;i<num-1&&flag;++i)
	{	
		flag = 0;
		for(int j=num-2;j>=i;--j)
		{	
			if(p[j] > p[j+1])
			{
				flag = 1;
				swap(p,j+1,j);
			}
		}
	}
}

int main(int argc,char **argv)
{
	srand(time(0));
	int p_data[NUM];
	for(int i=0;i<NUM;++i)
	{
		p_data[i] = rand() % NUM;
		printf("%d ",p_data[i]);
	}
	clock_t start = clock();
	sort_bubble2(p_data, NUM);
	clock_t end   = clock();
	printf("\n\ntime :%f\n\n",difftime( end , start));	
	
	for(int i=0;i<NUM;++i)
	{
		printf("%d ",p_data[i]);
	}
	return 0;
}
