#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <time.h>
#include <windows.h>
using namespace std;
const unsigned int gMax = 12345;
unsigned int Count1(unsigned int x)
{
	unsigned int res = 0;
	while (x)
	{
		if (x % 10 == 1)
		{
			res++;
		}
		x /= 10;
	}
	return res;
}
int count2sInRangeAtDigit(unsigned int number, unsigned int d)
{
	unsigned int powerOf10 = (unsigned int)pow(10, d);
	unsigned int nextPowerOf10 = powerOf10 * 10;
	unsigned int right = number % powerOf10;
	unsigned int roundDown = number - number % nextPowerOf10;
	unsigned int roundUp = roundDown + nextPowerOf10;
	unsigned int digit = (number / powerOf10) % 10;
	if (digit < 2)
		return roundDown / 10;
	else if (digit == 2)
	{
		return roundDown / 10 + right + 1;
	}
	else
		return roundUp / 10;
}
int getLen(unsigned int number)
{
	unsigned int res = 0;
	while (number)
	{
		res++;
		number /= 10;
	}
	return res;
}
unsigned int count2sInRange(unsigned int number)
{
	unsigned int count = 0;
	unsigned int len = getLen(number);
	for (unsigned int i = 0; i < len; ++i)
	{
		count += count2sInRangeAtDigit(number, i);
	}
	cout <<number<<" "<<count << endl;
	return count;
}
unsigned int GetMaxFn(unsigned int n)
{
	unsigned int res = 0;
	unsigned int sum = 0;
	for (unsigned int i = 0; i <= n; ++i)
	{

		unsigned int tmp = Count1(i);
		if(tmp)
		{
			sum += tmp;
		}

		cout << "f(" <<i<<") = " << sum << endl;
		if (i == sum)
		{
			res = i;
		}
	}
	return res;
}

int main()
{
	unsigned long begin = GetTickCount();
	count2sInRange(gMax);
	cout << (GetTickCount() - begin) << "ms" << endl;
	return 0;
}