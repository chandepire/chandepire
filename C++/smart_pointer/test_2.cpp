#include <iostream>
#include <vector>
#include <memory>
#include <new>
using namespace std;

shared_ptr<vector<int>> getpointer()
{
    return make_shared<vector<int>>();
}

void readdata(shared_ptr<vector<int>> temp)
{
    int buf;
    for(int i=0;i<5;++i)
    {
	cin >> buf;
        (*temp).push_back(buf);
    }
}

void printdata(shared_ptr<vector<int>> temp)
{
    for(int i=0;i<(*temp).size();++i)
    {
	cout << (*temp)[i] << endl;
    }
}

int main()
{
    //shared_ptr<vector<int>> q = getpointer();
    //readdata(q);
    //printdata(q);
    shared_ptr<int> p1;
    if(p1)
        cout << "OK" << endl;
    else
        cout << "OJBK" << endl;
    return 0;
}
