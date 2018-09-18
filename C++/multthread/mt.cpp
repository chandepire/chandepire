
#include <iostream>

class ppm
{
	bool flag_alloc;
	void init();
	unsigned int nr_lines;
	unsigned int nr_columns;
public:
	unsigned char *r;
	unsigned char *g;
	unsigned char *b;
	unsigned int height;
	unsigned int width;
	unsigned int max_col_val;
	unsigned int size;
	ppm();
	ppm(const std::string *fname);
	ppm(unsigned int int_width,unsigned int int_height);
	~ppm();

	void read(const string &fname);
	void write(const string &fname);
};

