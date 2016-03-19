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
long long n;
long long maxDivisors = 0;
long long res;
vector<long long> numPrime;
bool isPrime(long long x)
{
	if (x == 1)
	{
		return true;
	}
	for (long long i = 2; i <= (long long)sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
void initPrime()
{
	long long count = 0;
	for (long long i = 0;i < 42;i++)
	{
		if (isPrime(i))
		{
			numPrime.push_back(i);
			count++;
		}
	}
}

long long nextPrime(long long x)
{
	for (long long i = x + 1;; ++i)
	{
		if (isPrime(i))
		{
			return i;
		}
	}
	return x;
}
void dfs(long long prime, long long now, long long divisors, long long lastNi)
{
	if (prime > n)
	{
		return;
	}
	if (divisors > maxDivisors || (divisors == maxDivisors && now < res))
	{
		maxDivisors = divisors;
		res = now;
	}
	long long i = 0;
	while (now * pow(prime, i) < n && i <= lastNi)
	{
		dfs(nextPrime(prime), now * pow(prime, i), divisors*(i + 1), i);
		i++;
	}
}
int main()
{
	
	cin >> n;
	
	dfs(2, 1, 1,INT_MAX);
	cout << res << endl;
	return 0;
}