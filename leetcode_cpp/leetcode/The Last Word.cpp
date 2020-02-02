#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <deque>
#include <limits.h>
#include <fstream>
using namespace std;
int main()
{
	freopen("D:\\ÓÃ»§Ä¿Â¼\\Downloads\\A-large-practice.in", "r", stdin);
	int t;
	string s;
	cin >> t;
	deque<char> data;
	int cou = 1;
	ofstream os("D:\\res.txt");
	while (t--)
	{
		cin >> s;
		data.clear();
		data.push_back(s.front());
		for (size_t i = 1; i < s.length(); i++)
		{
			if (data.front() <= s[i])
			{
				data.push_front(s[i]);
			}
			else
			{
				data.push_back(s[i]);
			}
		}
		os << "Case #" << cou++ << ": " << string(data.begin(), data.end()) << endl;
	}
	return 0;
}