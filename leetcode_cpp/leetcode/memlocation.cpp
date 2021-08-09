#include <iostream>
using namespace std;

class Base
{
public:

	Base(int i) :baseI(i) {};

	int getI() { return baseI; }

	static void countI() {};

	virtual ~Base() {}

	virtual void print(void) { cout << "Base::print()"; }



private:

	int baseI;

	static int baseS;
};

int main(void)
{
	auto s = Base(1000);
	s.print();
	return 0;
}