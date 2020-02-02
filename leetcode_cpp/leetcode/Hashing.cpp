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
int msize, N;
bool isPrime(int x)
{
	if (x <= 1)
	{
		return false;
	}
	for (int i = 2; i < (int)sqrt(x) + 1; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int getMinPrime(int x)
{
	while (x)
	{
		if (isPrime(x))
		{
			return x;
		}
		++x;
	}
	return x;
}

void getPos(int x, vector<int>& f)
{
	int pos = x;
	int i = 0;
	int finalpos = pos;
	while (i<=msize)
	{
		finalpos = (pos + i * i) % msize;
		if (f[finalpos] == 0)
		{
			f[finalpos] = 1;
			cout << finalpos;
			return;
		}
		++i;
	}
	cout << "-";
	return;
}
int main()
{
	
	cin >> msize >> N;
	msize = getMinPrime(msize);
	vector<int> f(msize, 0);
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		getPos(tmp, f);
		if (i == N-1)
		{
			cout << endl;
		}
		else
		{
			cout <<" ";
		}
	}
	return 0;
}