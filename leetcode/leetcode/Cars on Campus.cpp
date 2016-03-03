#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <set>
using namespace std;
int timetoint(string& s)
{
	int res = 0;
	res = ((s[6] - '0') * 10 + (s[7] - '0')) +
		60 * ((s[3] - '0') * 10 + (s[4] - '0')) +
		60 * 60 * ((s[0] - '0') * 10 + (s[1] - '0'));
	return res;
}
struct mytime
{
	int time;
	int state;
	mytime(){};
};
struct state
{
	vector<int> in;
	vector<int> out;
	state(){};
};
int main()
{
	int n, m;
	cin >> n >> m;
	
	char a1[10], b1[10], c1[5];
	vector<int> car(24 * 60 * 60, 0);
	unordered_map<string, vector<mytime>> f;
	int maxTime = INT_MIN;
	set<string> name;
	for (int i = 0; i < n; ++i)
	{
		//getchar();
		scanf("%s %s %s", &a1, &b1, &c1);
		string a(a1), b(b1), c(c1);
		//cin >> a >> b >> c;
		//cout << a << " " << b << " " << c << endl;
		mytime tmp;
		if (c == "in")
		{
			tmp.time = timetoint(b);
			tmp.state = 1;
			f[a].push_back(tmp);
		}
		else
		{
			tmp.time = timetoint(b);
			tmp.state = 2;
			f[a].push_back(tmp);
		}
			
	}
	for (unordered_map<string, vector<mytime>>::iterator it = f.begin(); it != f.end(); ++it)
	{
		vector<mytime>& tmp = (it->second);
		sort(tmp.begin(), tmp.end(), [](mytime& a, mytime& b)->bool{	return a.time < b.time;});
		int inFlag = 0;
		int prevtime = 0;
		int alltime = 0;
		for (int i = 0; i < tmp.size(); ++i)
		{
			if (tmp[i].state == 1)
			{
				inFlag = 1;
				prevtime = tmp[i].time;
			}
			else
			{
				if (inFlag == 1)
				{
					inFlag = 0;
					transform(car.begin() + prevtime, car.begin() + tmp[i].time, car.begin() + prevtime, [](int& myt){ return ++myt; });
					//for (int j = prevtime; j < tmp[i].time; ++j)
					//{
					//	car[j]++;
					//}
					alltime += tmp[i].time - prevtime;
					
				}
			}

		}
		if (alltime > maxTime)
		{

			name.clear();
			maxTime = alltime;
			name.insert(it->first);
		}
		else if (alltime == maxTime)
		{
			name.insert(it->first);
		}
		
	}
	for (int i = 0; i < m; ++i)
	{
		string b;
		cin >> b;
		cout << car[timetoint(b)] << endl;
	}
	int flag = 0;
	for (auto i = name.begin(); i !=  name.end(); ++i)
	{
		if (flag == 0)
		{
			cout << *i;
			flag = 1;
		}
		else
			cout << " " << *i;
	}
	printf(" %02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 3600 % 60);
	//cout << maxTime << endl;
	return 0;
}