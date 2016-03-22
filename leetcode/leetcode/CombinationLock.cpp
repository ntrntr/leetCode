#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
inline void docmd1(int begin, int end, char x, string& s)
{
	if (!( begin >= 1 && end >= begin && s.size() >= end))
	{
		return;
	}
	for (int i = begin; i <= end; ++i)
	{
		s[i - 1] = x;
	}
}
inline void docmd2(int begin, int end, int step, string& s)
{
	if (!( begin >= 1 && end >= begin && s.size() >= end))
	{
		return;
	}
	for (int i = begin; i <= end; ++i)
	{
		s[i - 1] = 'A' + (s[i - 1] - 'A' + step) % 26;
	}

}
inline void docmd3(int step, string& s)
{
	string a = s.substr(0, step);
	string b = s.substr(step, s.size() - step);
	s = b + a; 
}

inline void docmd4(int begin, int end, string& s)
{
	if (begin > end)
	{
		return;
	}
	else
	{
		docmd4(begin + 1, end, s);
		docmd2(begin, end, 1, s);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	string lock;
	cin>>lock;
	for (int i = 0; i < m; i++)
	{
		int cmd,start,end,step;
		char x;
		getchar();
		scanf("CMD %d",&cmd);
		switch (cmd)
		{
		case 1:
			//cin>>start>>end>>x;
			scanf("%d %d %c",&start, &end, &x);
			docmd1(start, end, x, lock);
			break;
		case 2:
			//cin>>start>>end>>step;
			scanf("%d %d %d",&start, &end, &step);
			docmd2(start, end, step, lock);
			break;
		case 3:
			//cin>>step;
			scanf("%d", &step);
			docmd3(step, lock);
			break;
		case 4:
			//cin>>start>>end;
			scanf("%d %d", &start, &end);
			docmd4(start, end, lock);
			break;
		default:
			break;
		}
	}
	cout<<lock<<endl;
	return 0;
}