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
void FindLongestCommonString(const string& s)
{
	string tmp;
	for (size_t i = s.length() - 1; i > 1; --i)
	{
		for (size_t j = 0; j < s.length(); ++j)
		{
			if (i + j <= s.length())
			{
				size_t t = 0;
				size_t num = 0;
				tmp = s.substr(j, i);
				t = s.find(tmp);
				num = s.rfind(tmp);
				if (t != num)
				{
					cout << tmp << endl;
					return;
				}
			}
		}
	}
}
int main()
{
	FindLongestCommonString("abc");
	return 0;
}