#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for (int i = 2; i <= n; +i)
	{
		int cur = i;
		int sum = cur;
		while (sum * (++cur) < n)
		{
		}
	}
	return 0;
}