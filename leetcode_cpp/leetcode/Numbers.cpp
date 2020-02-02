#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

//int main2()
//{
//	string s;
//	cin >> s;
//	long long int n, t;
//	cin >> n;
//	t = n;
//	map<string, int> data;
//	vector<string> res;
//	res.push_back(s);
//	long long int count = 1;
//	while (n)
//	{
//		if (!data[s])
//		{
//			data[s] = count++;
//			char tmp = s[0];
//			s.erase(s.begin());
//			s.insert(s.begin() + (tmp - '1'), tmp);
//			res.push_back(s);
//			//cout << s << endl;
//		}
//		else
//		{
//			cout << res[data[s] - 1 + (n) % (count - data[s])] << endl;
//			return 0;
//		}
//		n--;
//	}
//	cout << s << endl;
//	return 0;
//}