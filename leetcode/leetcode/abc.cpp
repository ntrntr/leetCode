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
void getRes(long long int a, long long int b, long long int c)
{
	//cout << a + b << endl;
	if (a > 0 && b > 0 && (a + b) <= 0 )
	{
		cout << "true";
		return;
	}
	if (a < 0 && b < 0 && (a + b) >= 0)
	{
		cout << "false";
		return;
	}
	
	cout << ((a + b) > c ? "true" : "false");
	return;
}
int main()
{
	int n;
	cin >> n;
	long long int a, b, c;
	for (int i = 1; i <= n; ++i)
	{
		
		cin >> a >> b >> c;
		cout << "Case #" << i << ": ";
		getRes(a, b, c);
		cout << endl;
	}
	
	return 0;
}