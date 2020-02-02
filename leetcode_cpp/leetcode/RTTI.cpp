#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <typeinfo>
using namespace std;
class base
{
public:
	virtual void funcA(){ cout << "base" << endl; };
};
class derived: public base
{
public:
	virtual void funcB(){ cout << "derived" << endl; };
protected:
private:
};
void funcC(base* p)
{
	derived* dp = dynamic_cast<derived*>(p);
	if (dp)
	{
		dp->funcB();
	}
	else
		p->funcA();
}
void funcD(base* p)
{
	derived* dp = nullptr;
	if (typeid(*p) == typeid(derived))
	{
		dp = dynamic_cast<derived*>(p);
		dp->funcB();
	}
	else
	{
		p->funcA();
	}
}
int main()
{
	printf("%d", 5.01);
	return 0;
}