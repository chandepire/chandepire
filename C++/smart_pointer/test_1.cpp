#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <initializer_list>

using namespace std;

class StrBlob
{
    public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &t) {data->push_back(t);}
	void pop_back();

	std::string& front();
	std::string& back();

	const std::string& front() const;
	const std::string& back() const;

    private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(size_type i,const std::string &msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()) {cout << "OK" << endl;}
StrBlob::StrBlob(initializer_list<string> i1):data(make_shared<vector<string>>(i1)) {cout << "OJBK" << endl;}

void StrBlob::check(size_type i,const std::string &msg) const
{
	if(i>=data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0,"error1");
    data->pop_back();
}

std::string& StrBlob::front()
{
    check(0,"error2");
    data->front();
}

std::string& StrBlob::back()
{
    check(0,"error3");
    data->back();
}

const std::string& StrBlob::front() const
{
    check(0,"error2");
    data->front();
}

const std::string& StrBlob::back() const
{
    check(0,"error3");
    data->back();
}

int main()
{
    StrBlob b1;
    {
	StrBlob b2 = {"a","b","c"};
	b1 = b2;
        b1.push_back("d");
    }
    cout << b1.size() << endl;
    cout << b1.front() << endl;
    cout << b1.back() << endl;
    b1.pop_back();
    cout << b1.back() << endl;
    return 0;
}
