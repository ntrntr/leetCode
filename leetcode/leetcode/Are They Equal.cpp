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
int n;
void getStard(string& str, string& res, int& alpha)
{
	int pos = -1;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '0')
		{
			pos = i;
		}
		else
			break;
	}
	if (pos != -1)
	{
		str = str.substr(pos + 1);
	}
	string tmp;
	auto posPoint = str.find('.');
	if (posPoint == string::npos)
	{
		alpha = str.length();
		tmp = str;
	}
	else
	{
		alpha = posPoint;
		tmp = str;
		tmp.erase(posPoint,1);
	}
	pos = -1;
	for (int i = 0; i < tmp.size(); ++i)
	{
		if (tmp[i] == '0')
		{
			pos = i;
		}
		else
			break;
	}
	if (pos != -1)
	{
		if (pos == tmp.size() - 1)
		{

		}
		else
		{
			alpha -= (pos + 1);
			tmp = tmp.substr(pos + 1);
		}
		
		
	}
	if (tmp.length() >= n)
	{
		res = tmp.substr(0,n);
	}
	else
	{
		res = tmp;
		for (int i = 0; i < n - tmp.length(); ++i)
		{
			res.push_back('0');
		}
	}
}
void myprintf(string& src, int alpha)
{
	cout << "0." << src << "*10^" << alpha;
}
int main()
{
	
	string a, b;
	string a1, b1;
	int c1, c2;
	cin >> n >> a >> b;
	string tmp1, tmp2;
	getStard(a, a1, c1);
	getStard(b, b1, c2);
	if (a1 == b1 && c1 == c2)
	{
		cout << "YES" << " ";
		myprintf(a1, c1);
	}
	else
	{
		cout << "NO" << " ";
		myprintf(a1, c1);
		cout << " ";
		myprintf(b1, c2);
	}
	cout << endl;
	return 0;
}