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
vector<bool> myPrime;
vector<int> res;
vector<int> c;
int tmpN;
int N;
void crossOff(int x)
{
	for (int i = x*x; i <= tmpN; i += x)
	{
		myPrime[i] = false;
	}
}
int getNextPrime(int x)
{
	while (x < myPrime.size() && !myPrime[x])
	{
		++x;
	}
	return x;
}
bool isPrime(int x)
{
	for (int i = 2; i <= (int)sqrt(x);++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int getNextPrime1(int x)
{
	while (true)
	{
		if (!isPrime(x))
		{
			++x;
		}
		else
			return x;
	}
}
void createPrime(int max)
{
	int i = 2;
	while (i <= max)
	{
		int tmp = 0;
		int flag = true;
		while ((tmpN%i) == 0)
		{
			tmp++;
			tmpN /= i;
			if (flag)
			{
				res.push_back(i);
				flag = false;
			}
		}
		if (!flag)
		{
			c.push_back(tmp);
		}
		if (tmpN == 1)
		{
			return;
		}
		//crossOff(i);
		i = getNextPrime1(i + 1);
	}
}

int main()
{
	
	cin >> N;
	if (N == 1)
	{
		cout << "1=1" << endl;
		return 0;
	}
	if (isPrime(N))
	{
		cout << N << "=" << N << endl;
		return 0;
	}
	//vector<int> ress;
	//for (int i = 2; i < 10000;++i)
	//{
	//	if (isPrime(i))
	//	{
	//		ress.push_back(i);
	//	}
	//}
	//for (auto i:ress)
	//{
	//	cout << i << ",";
	//}
	tmpN = N;
	createPrime(N);

	cout << N << "=";
	for (int i = 0; i < res.size(); ++i)
	{
		if (i == 0)
		{
			cout<< res[i];
		}
		else
		{
			cout << "*" << res[i];
		}
		
		if (c[i]>1)
		{
			cout << "^" << c[i];
		}
		else
		{

		}
	}
	cout << endl;
	return 0;
}