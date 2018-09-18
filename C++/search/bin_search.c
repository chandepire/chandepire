#include <stdio.h>

int F[100] = {0,1};

int search1(int *p,int num,int key)
{
	int low = 1;
	int high= num;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(p[mid] == key)
			return mid;
		else if(key < p[mid])
			high = mid - 1;
		else
			low = mid+1;
	}
	return 0;
}

int search2(int *p,int num,int key)
{
	int low = 1;
	int high= num;
	while(low <= high)
	{
		printf("%f\n",(double)(key-p[low])/(p[high]-p[low]));
		int mid = low + (double)(key-p[low])/(p[high]-p[low])*(high - low);
		if(p[mid] == key)
			return mid;
		else if(key < p[mid])
			high = mid - 1;
		else
			low = mid+1;
	}
	return 0;
}

int search3(int *p,int num,int key)
{
	int low = 1;
	int high= num;

	int k = 0;
	while(num > F[k] - 1)
		++k;
	printf("k:%d\n",k);

	for(int i=num+1;i<F[k];++i)
		p[i] = p[num];
	
	while(low <= high)
	{
		int mid = low + F[k-1] - 1;
                if(key < p[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if(key > p[mid])
		{
			low = mid+1;
			k = k - 2;
		}
		else
		{
			if(mid <= num)
				return mid;
			else
				return num;
		}
	}
	return 0;
}

int main()
{
	for(int i=2;i<100;++i)
		F[i] = F[i-1] + F[i-2];

	int a[100] = {0,3,11,21,23,32,43,66,84,99,100};
	printf("%d\n", search3(a,10,100) );
	printf("%d\n", search3(a,10,99) );
	return 0;
}
