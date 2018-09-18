#include <stdio.h>

int search1(int *p,int num,int key)
{
	for(int i=1;i<=num;++i)
		if(p[i] == key)
			return i;
	return 0;
}

int search2(int *p,int num,int key)
{
	int i = num;
	p[0] = key;
	while(key != p[i])
		--i;
	return i;
}

int main()
{
	int a[11] = {0,99,23,43,11,21,32,3,66,84,100};
	printf("%d\n", search2(a,10,21) );
	printf("%d\n", search2(a,10,22) );
	return 0;
}
