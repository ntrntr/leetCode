#include <iostream>
using namespace std;

class B
{
public:
	B(int b1, int b2, int b3)
		: b1(b1),
		b2(b2),
		b3(b3)
	{
	}
	int b1;
	virtual void show()
	{
		cout << "B b1:" << b1 << "\tb2:" << b2 << "\tb3:" << b3 << endl;
	}
protected:
	int b2;
private:
	int b3;
};

class D_priv:private B
{
public:
	D_priv(int b1, int b2, int b3)
		: B(b1, b2, b3)
	{
	}

	void show() override
	{
		cout << "D_priv b1:" << b1 << "\tb2:" << b2 << endl;
	}
};

class D_protect:protected B
{
public:
	D_protect(int b1, int b2, int b3)
		: B(b1, b2, b3)
	{
	}


	void show() override
	{
		cout << "D_protect b1:" << b1 << "\tb2:" << b2 <<endl;
	}
};

class D_publ:public B
{
public:
	D_publ(int b1, int b2, int b3)
		: B(b1, b2, b3)
	{
	}

	void show() override
	{
		cout << "D_publ b1:" << b1 << "\tb2:" << b2 << endl;
		B::show();
	}
};

int main(void)
{
	cout << "hello world" << endl;
	auto b = B(1, 2, 1);
	b.show();
	auto d_pub = D_publ(1, 1, 1);
	d_pub.show();
	auto d_pro = D_protect(1, 1, 1);
	d_pro.show();
	auto d_pri = D_priv(1, 1, 1);
	d_pri.show();
	
	cout << d_pub.b1 << endl;
	return 0;
}