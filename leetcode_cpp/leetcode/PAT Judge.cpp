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
int n, k, m;
struct node
{
	node(){};
	node(int num,int k)
	{
		id = num;
		score = vector<int>(k,-2);
		perfectNum = 0;
		flag = 0;
		total = 0;
	};
	int id;
	vector<int> score;
	int perfectNum;
	int flag;
	int total;
};
vector<node> s;
vector<int> score;
//template<int T>
int mycomp(const node& a,const node& b)
{
	if (a.total != b.total)
	{
		return a.total > b.total;
	}
	else if (a.perfectNum != b.perfectNum)
	{
		return a.perfectNum > b.perfectNum;
	}
	else
	{
		return a.id < b.id;
	}
}
void myprint(int rank, node& p)
{
	cout << rank << " ";
	printf("%05d", p.id);
	cout << " " << p.total;
	for (int i = 1; i <= (int)p.score.size()-1; ++i)
	{
		cout << " ";
		if (p.score[i] == -2)
		{
			cout << "-";
		}
		else if (p.score[i] == -1)
		{
			cout << "0";
		}
		else
		{
			cout << p.score[i];
		}
	}
	cout << endl;
}
int main()
{
	cin >> n >> k >> m;
	score.resize(k+1);
	for (int i = 0; i < n + 1; ++i)
	{
		s.push_back(node(i, k + 1));
	}
	for (int i = 1; i <= k; ++i)
	{
		cin >> score[i];
	}
	int a, b, c;
	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		s[a].score[b] = max(c, s[a].score[b]);
	}
	for (int i = 1; i <= n; ++i)
	{
		int tmpsum = 0;
		int flag = 0;
		for (int j = 1; j < k+1; ++j)
		{
			if (score[j] == s[i].score[j])
			{
				++s[i].perfectNum;
				s[i].total += s[i].score[j];
				flag = 1;
			}
			else if (s[i].score[j] == -2)
			{
				continue;
			}
			else if (s[i].score[j] == -1)
			{
				continue;
			}
			else
			{
				s[i].total += s[i].score[j];
				flag = 1;
			}
		}
		s[i].flag = flag;
	}
	sort(s.begin(), s.end(), mycomp);
	int rank = 1;
	int prevRank = 1;
	int rankScore = 0;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		
		if (s[i].flag)
		{
			if (i == 0)
			{
				rankScore = s[i].total;
				prevRank = rank;
				myprint(rank, s[i]);
				
			}
			else if (s[i].total == rankScore)
			{
				myprint(prevRank, s[i]);

			}
			else
			{
				myprint(rank, s[i]);
				prevRank = rank;
				rankScore = s[i].total;
			}
			++rank;

		}
	}
	return 0;
}