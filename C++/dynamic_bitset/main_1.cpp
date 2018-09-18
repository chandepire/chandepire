
#include <iostream>
#include <boost/typeof/typeof.hpp>
#include <boost/array.hpp>
#include <boost/assign.hpp>
#include <boost/dynamic_bitset.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;

int main()
{
	dynamic_bitset<> db1;
	dynamic_bitset<> db2(10);
	dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));
	dynamic_bitset<> db4(string("0100"));
	dynamic_bitset<> db5(db3);
	dynamic_bitset<> db6;
	db6 = db4;
	
	cout << hex << db5.to_ulong() << endl;
	cout << db4[0] << db4[1] << db4[2] << endl;
	dynamic_bitset<> db(4,BOOST_BINARY(1010));
	
	assert(db.test(0) == 0 && db.test(1) == 1);
	assert(db.any());
	assert(!db.none());
	cout << "其中1的个数为:" << db.count() << endl;

	for(int i=0;i<db.size();++i)
		cout << db[i] << endl;

	cout << "after reset ..." << endl;

	db.reset();
	for(int i=0;i<db.size();++i)
		cout << db[i] << endl;

	cout << "after flip ..." << endl;
	db.flip();
	for(int i=0;i<db.size();++i)
		cout << db[i] << endl;

	cout << "after set(m,n) ...." << endl;
	db.set(0,0);
	for(int i=0;i<db.size();++i)
		cout << db[i] << endl;

	cout << "after reset(m)..." << endl;
	db.reset(1);
	for(int i=0;i<db.size();++i)
		cout << db[i] <<endl;

	cout << "after flip(m,n)......." << endl;
	db.flip(3);
	for(int i=0;i<db.size();++i)
		cout << db[i] << endl;

	cout << "测试类型转换" << endl;
    	dynamic_bitset<>db8(10,BOOST_BINARY(1010101));
    	cout << "输出的整形是：" << db8.to_ulong() << endl;

	cout << ~(uint64_t)0 << endl;
	cout << (uint64_t)~(uint64_t)0/3<< endl;
	cout << (uint64_t)~(uint64_t)0/15*3 << endl;
	cout << ((uint64_t)~(uint64_t)0/255) << endl;
	return 0;
}
