#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int *a,int *b)
{
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*b)^(*a);
}

void shell(int array[],int length)
{
     int i=0,temp=0,j=0;
     int increatment = length;
     do{
          increatment = increatment/3+1;
          for(i=increatment;i<length;++i)
          {
              if(array[i-increatment] < array[i])
              {
                  temp = array[i];
                  for(j=i-increatment;j>=0&&array[j]<temp;j-=increatment)
                      array[j+increatment] = array[j];
                  array[j+increatment] = temp;
              }
          }
     }while(increatment > 1);
}

int part(int array[],int begin,int end)
{
    int buffer = array[begin];
    while(begin<end)
    {
        while(begin < end && array[end]>=buffer)
              --end;
        array[begin] = array[end];
        while(begin < end && array[begin]<=buffer)
              ++begin;
        array[end] = array[begin];
    }
    array[begin] = buffer;
    return begin;
}

void subquick(int array[],int begin,int end)
{
    int partation;
    if(begin < end)
    {
        partation = part(array,begin,end);
        subquick(array,begin,partation-1);
        subquick(array,partation+1,end);
    }
}

void quick(int array[],int length)
{
    subquick(array,0,length-1);
}
#define NUM 10

typedef struct array{
     int data[NUM+1];
     int length;
}array;

void heap(int array[],int st, int en)
{
    int temp = array[st];
    for(int j=2*st;j<=en;j*=2)
    {
        if(j+1<=en && array[j]>array[1+j])
            ++j;
        if(temp < array[j] )
            break;
        array[st] = array[j];
        st = j;
    }
    array[st] = temp;
}

void heap_sort(int array[],int length,int k)
{
    assert(k<=length);
    for(int i=k;i>0;--i)
    {
        heap(array, i, length);
    }
    for(int i=NUM;i>1;--i)
   {
     swap(&array[i],&array[1]);
     heap(array,1,i-1);
   }
}

int main()
{
    int array[NUM+1];
    srand(time(0));
    for(int i=1;i<=NUM;++i)
        array[i] = rand()%1000;
    for(int i=1;i<=NUM;++i)
        printf("%d ",array[i]);
    printf("\n\n");
    heap_sort(array, NUM, NUM/2);
    for(int i=1;i<=NUM;++i)
        printf("%d ",array[i]);
    printf("\n");

    return 0;
}
