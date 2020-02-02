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
bool isPrime(int x)
{
	if (x == 0 || x == 1)
	{
		return false;
	}
	for (int i = 2; i <= (int)sqrt(1.0*x); ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool isReverse(int n, int radix)
{
	int res = 0;
	do 
	{
		res = res * radix + n % radix;
		n = n / radix;
	} while (n != 0);

	return isPrime(res);
}

int main()
{
	int n, d;
	while (cin>>n)
	{
		if (n < 0)
		{
			return 0;
		}
		cin >> d;
		cout << ((isReverse(n, d) && isPrime(n)) ? "Yes" : "No") << endl;
	}

	return 0;
}