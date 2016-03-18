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
char data[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
string getData(int x)
{
	string res = "00";
	res[1] = data[x % 13];
	res[0] = data[x / 13];
	return res;
}
int main()
{
	
	int a, b, c;
	cin >> a >> b >> c;
	string res = "#" + getData(a) + getData(b) + getData(c);
	cout << res << endl;
	return 0;
}