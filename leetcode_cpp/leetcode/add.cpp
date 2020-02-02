#include <iostream>
#include <stdio.h>
using namespace std;

int Add(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	int sum, carry;
	sum = a^b;
	carry = (a&b)<<1;
	return Add(sum, carry);

}
int main()
{
	int n = 'c';
	switch (n++)
	{
	default:
		break;
	case 'c': cout << "c";
	case 'd':cout << "d";
	}
	return 0;
}