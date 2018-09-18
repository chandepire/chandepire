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

void sort_insert(int p[], int num)
{
	int temp ,j;
	for(int i=1;i<num;++i)
	{	
		if(p[i]<p[i-1])
		{
			temp = p[i];
			for(j = i-1;j>=0&&p[j] > temp;--j)
			{
				p[j+1] = p[j];
			}
			p[j+1] = temp;
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
	sort_insert(p_data, NUM);
	clock_t end   = clock();
		
	printf("\n\n");
	for(int i=0;i<NUM;++i)
	{
		printf("%d ",p_data[i]);
	}

	printf("\n\ntime :%f\n\n",difftime( end , start));
	return 0;
}
