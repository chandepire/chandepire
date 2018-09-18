#include "my_vector.h"
#include <iostream>
using namespace std;

int main(){
  
	My_Vector<int> vec;
	for (int i = 0; i != 10; ++i)
		vec.push_back(i);  //push_back()

	My_Vector<int>::iterator it;
	My_Vector<int> vec2(vec); //拷贝构造
	for (it = vec2.begin(); it != vec2.end(); ++it) //begin(),end()
		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
	cout << endl;

	My_Vector<int> vec3 = vec; //拷贝赋值运算符
	for (it = vec3.begin(); it != vec3.end(); ++it)
		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
	cout << endl;

	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";   //0 1 2 3 4 5 6 7 8 9
	cout << endl;
	cout << "size:" << vec.size() << endl; //10 size()
	cout << "capacity:" << vec.capacity() << endl; //16 capacity()
	vec.reserve(10); //reserve()
	cout << "capacity:" << vec.capacity() << endl; //16
	vec.reserve(30);//reserve()
	cout << "capacity:" << vec.capacity() << endl; //30

	vec.pop_back(); //pop_back()
	for (size_t i = 0; i <vec.size(); ++i)
		cout << vec[i] << " ";//0 1 2 3 4 5 6 7 8
	cout << endl;

	cout << "front:" << vec.front() << endl; //0 front()
	cout << "back:" << vec.back() << endl; //8 back()

	vec.insert(vec.begin() + 5, 3, 10);  //insert()
	for (const auto& c : vec)
		cout << c << " ";//0 1 2 3 4 10 10 10 5 6 7 8
	cout << endl;

	vec.erase(vec.begin() + 2, vec.begin() + 5); //erase()
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";//0 1 10 10 10 5 6 7 8
	cout << endl;
	cout << "size:" << vec.size() << endl; //9

	vec.resize(5);  //resize()
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";//0 1 10 10 10
	cout << endl;
	cout << "size:" << vec.size() << endl; //5

	vec.resize(10);
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";//0 1 10 10 10 0 0 0 0 0
	cout << endl;
	cout << "size:" << vec.size() << endl; //10

	vec.clear();  //clear()
	cout << (vec.empty() ? "vector empty" : "vector not empty") << endl; //empty


	return 0;
}
