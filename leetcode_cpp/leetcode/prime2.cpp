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
	for (int i = 2; i <= (int)sqrt(x); ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int N;
	cin >> N;
	cout << N << "=";
	if (N == 1 || isPrime(N))
	{
		cout << N << endl;
		return 0;
	}
	int i = 2;
	bool first = true;
	int k = sqrt(N);
	for (int i = 2; i <= k;++i)
	{
		int tot = 0;
		if (N % i == 0)
		{
			while (N%i == 0)
			{
				tot++;
				N /= i;

			}
			if (first)
			{

				first = false;
				
			}
			else
			{
				cout << "*";
				
			}
			if (tot >= 2)
			{
				cout << i << "^" << tot;
			}
			else
				cout << i;
		}
		k = (int)sqrt(N);
	}
	if (N > 1)
	{
		cout << "*" << N;
	}
	cout << endl;
	return 0;
}