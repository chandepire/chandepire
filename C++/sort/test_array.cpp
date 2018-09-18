#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a = b^a;
}

void adjustHeap(std::vector<int> &v,int i,int length)
{
   int child = 2*i + 1;
   if(child < length)
   {
       if(child+1<length && v[child+1]>v[child])
            ++child;

       if(v[child] > v[i])
       {
         swap(v[child],v[i]);
         adjustHeap(v,child,length);
       }
   }
}

int main()
{
    std::vector<int> v = {33,21,62,12,4,42,6,10};
    int k = 3;
    for(int i=v.size()/2-1;i>=0;--i)
        adjustHeap(v,i,k);

    for(int i=0;i<v.size();++i)
          cout << v[i] << " ";

    cout << endl;
    int i = k;
    while(i < v.size())
    {
        if(v[0] > v[i])
        {
          swap(v[0],v[i]);
          adjustHeap(v,0,k);
          i = k;
        }
        else
          ++i;
    }

    for(int i=0;i<k;++i)
      cout << v[i] << " ";
    return 0;
}
