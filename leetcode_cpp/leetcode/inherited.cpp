#include <iostream>
using namespace std;

class A
{
public:
	A(int v = -1) :a(v), b(v), c(v){};
public:
	int a; 
protected:
	int b;
private:
	int c;
};

class B : public A
{
public:
	int getA(){ return a; };
	int getB(){ return b; };
	//int getC(){ return c; };

private:

};

class C : protected A
{
public:
	int getA(){ return a; };
	int getB(){ return b; };
	//int getC(){ return c; };

private:

};

class D : private A
{
public:
	int getA(){ return a; };
	int getB(){ return b; };
	//int getC(){ return c; };

private:

};


int main()
{
	C a;
}