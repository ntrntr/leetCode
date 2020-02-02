#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <limits.h>
using namespace std;
int main()
{
	int n, b;
	cin >> n >> b;
	int ileft = b - 1;
	int iright = n - b;
	if (ileft > iright)
	{
		cout << b - 1;
	}
	else
	{
		cout << b + 1;
	}
	return 0;
}