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
enum state
{
	on,
	off
};
struct record
{
	string name;
	int date, dd, hh, mm;
	int state;
	record(){};
	record(string& n, int _date, int _dd, int _hh, int _mm, int _state) :name(n), date(_date), dd(_dd), hh(_hh), mm(_mm), state(_state){};
};
vector<record> f;
vector<int> cost(24, 0);
void insertRecord(string& a, string& b, string& c)
{
	int date, dd, hh, mm, state;
	if (c == "on-line")
	{
		state = 0;
	}
	else
	{
		state = 1;
	}
	date = (b[0] - '0') * 10 + b[1] - '0';
	dd =(b[3] - '0') * 10 + b[4] - '0';
	hh = (b[6] - '0') * 10 + b[7] - '0';
	mm = (b[9] - '0') * 10 + b[10] - '0';
	f.push_back(record(a, date, dd, hh, mm, state));
	return;
}
bool cmp(record& a, record& b)
{
	if (a.name != b.name)
	{
		return a.name < b.name;
	}
	else if (a.date != b.date)
	{
		return a.date < b.date;
	}
	else if (a.dd != b.dd)
	{
		return a.dd < b.dd;
	}
	else if (a.hh != b.hh)
	{
		return a.hh < b.hh;
	}
	else
	{
		return a.mm < b.mm;
	}
}
double getMoney(int a1,int b1, int c1, int a2, int b2, int c2, int& time)
{
	time = 0;
	double sum = 0;
	time = (a2 - a1) * 24 * 60 + (b2 - b1) * 60 + (c2 - c1);
	if (c1 > 0)
	{
		sum -= 1.0 * cost[b1] * c1;
	}
	if (c2 > 0)
	{
		sum += 1.0 * cost[b2] * c2;
	}
	for (int i = a1; i < a2; ++i)
	{
		for (int j = 0; j < 24; ++j)
		{
			sum += cost[j] * 60;
		}
	}
	for (int i = b1; i < b2; ++i)
	{
		sum += cost[i] * 60;
	}
	return sum;
}
int main()
{
	
	
	for (int i = 0; i < 24; ++i)
	{
		cin >> cost[i];
	}
	int n;
	cin >> n;
	string a, b, c;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		insertRecord(a, b, c);
	}
	sort(f.begin(), f.end(), cmp);
	//for (auto i:f)
	//{
	//	cout << i.name << "\t" << i.date << ":" << i.dd << ":" << i.hh << ":" << i.mm << "\t" << i.state << endl;
	//}
	string prevname;
	int state = -1;
	int prevmonth = -1;
	int prevdd, prevhh, prevmm;
	double sum = 0;
	int time;
	double tmp = 0;
	for (int i = 0; i < f.size(); ++i)
	{
		if (prevname != f[i].name || (prevname == f[i].name && prevmonth != f[i].date))
		{
			if (sum > 0.0)
			{
				printf("Total amout: $%.2f\n", sum / 100.0);
			}
			prevmonth = f[i].date;
			prevname = f[i].name;
			cout << f[i].name << " ";
			printf("%02d\n", f[i].date);
			sum = 0;
		}
		if (f[i].state == 0)
		{
			prevdd = f[i].dd;
			prevhh = f[i].hh;
			prevmm = f[i].mm;
			state = 0;
		}
		else if (state == 0 && f[i].state == 1)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d", prevdd, prevhh, prevmm, f[i].dd, f[i].hh, f[i].mm);
			tmp = getMoney(prevdd, prevhh, prevmm, f[i].dd, f[i].hh, f[i].mm, time);
			sum += tmp;
			cout << " " << time << " $";
			printf("%.2f\n", tmp / 100.0);
		}
		
	}
	printf("Total amout: $%.2f\n", sum / 100.0);
	return 0;
}