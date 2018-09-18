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

void sort_shell(int p[], int num)
{
	int temp ,j;
	int increament = num;
	do
	{
	increament = increament/3 + 1;
	for(int i=increament;i<num;++i)
	{	
		if(p[i]<p[i-increament])
		{
			temp = p[i];
			for(j = i-increament;j>=0&&p[j] > temp;j-=increament)
			{
				p[j+increament] = p[j];
			}
			p[j+increament] = temp;
		}
	}
	}while(increament > 1);
}


int main(int argc,char **argv)
{
	srand(time(0));
	int p_data[NUM];
	for(int i=0;i<NUM;++i)
	{
		p_data[i] = rand() % 5000;
		printf("%d ",p_data[i]);
	}
	clock_t start = clock();
	sort_shell(p_data, NUM);
	clock_t end   = clock();
		
	printf("\n\n");
	for(int i=0;i<NUM;++i)
	{
		printf("%d ",p_data[i]);
	}

	printf("\n\ntime :%f\n\n",difftime( end , start));
	return 0;
}
