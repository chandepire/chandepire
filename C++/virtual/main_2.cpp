#include <iostream>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "Car constructor" << endl;
	}
	~Car()
	{
		cout << "Car destructor" << endl;
	}
	virtual void start() const = 0;
	virtual void stop() const = 0;
};

class Benz: public Car
{
public:
	Benz()
	{
		cout << "Banz constructor" << endl;
	}	
	~Benz()
	{
		cout << "Benz destructor " << endl;
	}
	void start() const
	{
		cout << "Benz start" << endl;
	}
	void stop() const
	{
		cout << "Benz stop" << endl;
	}
};

class Baoma: public Car
{
public:
	Baoma()
	{
		cout << "Baoma constructor" << endl;
	}
	~Baoma()
	{
		cout << "Baoma destructor " << endl;
	}
	void start() const 
	{
		cout << "Baoma start" << endl;
	}
	void stop() const
	{
		cout << "Baoma stop " << endl;
	}
private:
	int speed;
};

void carFunction(Car *car)
{
	car->start();
	car->stop();
}
int main()
{
	Car *benz = new Benz();
	cout << sizeof(Benz) << endl;
	carFunction(benz);
	
	Car *baoma = new Baoma();
	cout << sizeof(Baoma) << endl;
	carFunction(baoma);

	delete benz;
	delete baoma;
	return 0;
}
