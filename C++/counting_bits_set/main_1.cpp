
#include<iostream>

using namespace std;

int main()
{
	unsigned int v = 100;
	unsigned int c = 0;
	//for(c =0;v;c++)
	//	v &= v-1;
	

	//c = (v * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;

	//c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	//c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;

	c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 
     0x1f;
	c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	cout << c << endl;
	return 0;
}
