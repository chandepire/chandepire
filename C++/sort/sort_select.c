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

void sort_select(int p[], int num)
{
	int min ;
	for(int i=0;i<num-1;++i)
	{	
		min = i;
		for(int j=i+1;j<num;++j)
		{	
			if(p[min] > p[j])
			{
				min = j;
			}
		}
		if(min != i)
			swap(p,min,i);
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
	sort_select(p_data, NUM);
	clock_t end   = clock();
		
	printf("\n\n");
	for(int i=0;i<NUM;++i)
	{
		printf("%d ",p_data[i]);
	}

	printf("\n\ntime :%f\n\n",difftime( end , start));
	return 0;
}
