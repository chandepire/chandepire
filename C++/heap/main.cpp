#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
	int *data;
	int size;
	int Capcity;
};

MaxHeap create(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->data = (int*)malloc(sizeof(int)*(1+MaxSize));
	H->size = 0;
	H->Capcity = MaxSize;
	H->data[0] = INT_MAX; 
	return H;
}

void insert(MaxHeap H, int element)
{
	if(H->size == H->Capcity)
	{	
		cout << "full";
		return ;
	}
	int i;
	i = ++H->size;
	for(;H->data[i/2] < element ;i/=2)
		H->data[i] = H->data[i/2];
	H->data[i] = element;
}

int deldel(MaxHeap H)
{
	if(H->size == 0)
	{
		cout << "None";
		return INT_MAX;
	}
	int item = H->data[1];
 	int temp = H->data[H->size--];
	int parent,child;
	for(parent=1;parent*2<=H->size;parent = child)
	{
		child = parent*2;
		if(child!=H->size && H->data[child] < H->data[child+1])
			++child;
		if(H->data[child] <= temp) 
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = temp;
	return 0;
}

void heap1(MaxHeap H,int s,int n)
{
	int temp = H->data[s];
	int t;
	for(;s*2<=n;s = t)
	{
		t = s*2;
		if(t!=n && H->data[t] < H->data[t+1])
			++t;
		if(H->data[t] <= temp) 
			break;
		else
			H->data[s] = H->data[t];
	}
	H->data[s] = temp;
}

void swap(int *data,int i,int j)
{
	int temp = data[i];
	data[i]  = data[j];
	data[j]  = temp;
}
	
void heapsort(MaxHeap H)
{
	int len = H->size/2;
	for(int i=len;i>0;i--)
		heap1(H,i,H->size);

	for(int i = H->size;i>1;i--)
	{
		swap(H->data,1,i);
		heap1(H,1,i-1);
	}
}

int main()
{
	cout << INT_MAX << endl;
	MaxHeap H = create(10);
	int temp;
	for(int i=0;i<10;++i)
	{
		temp = rand() % 100;
		insert(H, temp);
	}
	for(int i=1;i<=H->size;++i)
		cout << H->data[i] << " " ;
	cout << endl;
	heapsort(H);
	for(int i=1;i<=H->size;++i)
		cout << H->data[i] << " " ;
	cout << endl;
	return 0;
}
