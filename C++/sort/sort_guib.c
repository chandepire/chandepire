#include <stdio.h>
#define MAXSIZE 100


void Merge(int SR[],int TR[],int i,int m,int n)
{
	int k=0,j,l ;
	for(k=i,j = m+1;i<=m && j <= n;k++)
	{
		if(SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if(i <= m)
	{
		for(int l=0;l<=m-i;++l)
			TR[k+l] = SR[i+l];	
	}
	if(j <= n)
	{
		for(int l=0;l<=n-j;++l)
			TR[k+l] = SR[j+l];	
	}
}


void MSORT(int SR[],int TR1[],int s,int t)
{
	int m;
	int TR2[MAXSIZE];
	if(s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
	        m = (s+t)/2;
		MSORT(SR,TR2,s,m);
		MSORT(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
	}
}

int main()
{
	int a[5] = {35,47,58,54,99};	
	MSORT(a,a,0,4);
	for(int i=0;i<5;++i)
		printf("%d ",a[i]);
	return 0;
}
