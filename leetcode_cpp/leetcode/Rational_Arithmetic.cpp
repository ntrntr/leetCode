#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#include <sstream>

template <typename T>
string NumberToString ( T Number )
{
	ostringstream ss;
	ss.clear();
	ss << Number;
	return ss.str();
}
long int gcd(long int a,long int b)
{
	if (a < b)
	{
		gcd(b,a);
	}
	long int tmp;
	while (a % b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}
string myprint(long int a,long int b)
{
	if (b < 0)
	{
		b = -b;
		a = -a;
	}
	if (b == 0)
	{
		return "Inf";
	}
	bool flag = false;
	if (a<0)
	{
		a = -a;
		flag = true;
	}
	if (a == 0)
	{
		return "0";
	}
	int tmp = gcd(a, b);
	a /= tmp;
	b /= tmp;
	
	string s;
	if (a % b == 0)
	{
		s+=NumberToString<long int>(a/b);
	}
	else if (a > b)
	{
		s += NumberToString<long int>(a/b) + " " + NumberToString<long int>(a % b) + "/"
			+ NumberToString<long int>(b);
	}
	else
	{
		s += NumberToString<long int>(a) + "/" + NumberToString<long int>(b);
	}
	if (flag)
	{
		return "(-" + s + ")";
	}
	else
	return s;
}
int main()
{
	long int a,b,c,d;
	scanf("%ld/%ld %ld/%ld",&a,&b,&c,&d);
	string left(myprint(a , b ));
	string right(myprint(c , d));
	string myadd(myprint(a * d + b * c, b * d));
	string mysub(myprint(a * d - b * c, b * d));
	string myproduct(myprint(a * c, b * d));
	string myquotient(myprint(a * d, b * c));
	cout<<left<<" + "<<right<<" = "<<myadd<<endl;
	cout<<left<<" - "<<right<<" = "<<mysub<<endl;
	cout<<left<<" * "<<right<<" = "<<myproduct<<endl;
	cout<<left<<" / "<<right<<" = "<<myquotient<<endl;
	return 0;
}