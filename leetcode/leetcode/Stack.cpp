#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <deque>
#include <sstream>
#include <set>
using namespace std;
int mystoi(string& s)
{
	stringstream ss;
	ss << s;
	int res;
	ss >> res;
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> f;
	f.reserve(5000);
	getchar();
	string tmp;
	multiset<int> g;
	for (int i = 0; i < N; ++i)
	{
		getline(cin, tmp);
		if (tmp == "Pop")
		{
			if (f.size() == 0)
			{
				cout << "Invalid" << endl;
			}
			else
			{
				cout << f[f.size() - 1] << endl;
				
				f.pop_back();
				
			}
		}
		else if (tmp == "PeekMedian")
		{
			if (f.size() == 0)
			{
				cout << "Invalid" << endl;
			}
			else
			{
				
				cout << (f.size() % 2 == 0 ? *next(g.begin(), f.size() / 2 - 1) : *next(g.begin(), f.size() / 2)) << endl;
			}
		}
		else
		{
			string t(tmp.begin() + 5, tmp.end());
			f.push_back(mystoi(t));
			g.insert(mystoi(t));
		}
	}
	return 0;
}