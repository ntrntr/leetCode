#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
class A
{
public:
	void test(){};
	void test1(){};
	void test2(){};
	void test3(){};
	//virtual void aa(){};
private:
	char k[2];
};
class B : public A
{
public:
	
	virtual bool bb(){};
private:
	char j[2];
};

class C:public B
{
public:
	virtual bool cc(){};
	void a(){};
private:
	char i[4];
};


int main()
{
	cout << sizeof(B) << endl;
	return 0;
}