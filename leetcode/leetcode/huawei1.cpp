#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <fstream>
#include <time.h>
using namespace std;
clock_t m_begin, m_end;
#define CLOCK_START m_begin = clock()
#define CLOCK_END printf("\n%f seconds\n", (double)(clock() - m_begin)/CLOCKS_PER_SEC)
vector<vector<int>> link(600, vector<int>(600, INT_MAX));
vector<bool> visited(600, false);
vector<int> pass;
int minlen = INT_MAX;
vector<int> path;
vector<int> finalres;
vector<int> shuffle;
void dfs(int start, int end, int curlen)
{
	if (curlen > minlen)
	{
		return;
	}
	if (start == end)
	{
		vector<int> tmp(path);
		sort(tmp.begin(), tmp.end());
		if (minlen > curlen && includes(tmp.begin(), tmp.end(), pass.begin(), pass.end()))
		{
			minlen = curlen;
			finalres = path;
		}
		return;
	}
	for (int i = 0; i < 600; ++i)
	{
		if (i != start && link[start][i] != INT_MAX && !visited[i])
		{
			visited[i] = true;
			path.push_back(i);
			dfs(i, end, curlen + link[start][i]);
			path.pop_back();
			visited[i] = false;
		}
	}
}
void createFile(int pointsNum, int lineNum)
{
	FILE *p = NULL;
	int count = 0;
	p = fopen("d:\\data2.csv", "w");
	srand((unsigned int)time(NULL));
	int len = 0;
	for (int i = 0; i < pointsNum; ++i)
	{
		for (int j = i + 1; j < pointsNum; ++j)
		{
			if (rand()%2 == 0)
			{
				fprintf(p, "%d,%d,%d,%d\n", count++, i, j, rand() % 20 + 1);
				fprintf(p, "%d,%d,%d,%d\n", count++, j, i, rand() % 20 + 1);
			}
		}
	}
	fclose(p);
	p = NULL;
	return;
}
int main()
{
	map<pair<int, int>, int> numToLink;
	int a, b, c, d;
	int i, j;
	
	createFile(30, 50);
	CLOCK_START;
	
	FILE *p = NULL;
	p = fopen("d:\\data2.csv", "r");
	while (!feof(p) && fscanf(p, "%d,%d,%d,%d\n", &a, &b, &c, &d))
	{
		//cout << a << " " << b << " " << c << " " << d << endl;
		link[b][c] = min(d, link[b][c]);
		if (link[b][c] < d)
		{
			numToLink[make_pair(b, c)] = a;
		}
	}
	fclose(p);
	p = NULL;
	p = fopen("d:\\res.txt", "r");
	int startPoint, endPoint;
	char s[200];
	fscanf(p, "%d,%d,%s\n", &startPoint, &endPoint, s);
	//cout << startPoint << " " << endPoint << " " << s<<endl;
	fclose(p);
	p = NULL;
	i = 0;
	int res = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|')
		{
			pass.push_back(res);
			res = 0;
		}
		else
		{
			res = res * 10 + s[i] - '0';
		}
		i++;
	}
	pass.push_back(res);
	sort(pass.begin(), pass.end());
	visited[startPoint] = true;
	path.push_back(startPoint);
	dfs(startPoint, endPoint, 0);
	p = fopen("d:\\myres.txt", "w");
	if (finalres.size() == 0)
	{
		cout << "NA" << endl;
		fprintf(p, "%s", "NA");
		fclose(p);
		p = NULL;
		return 0;
	}
	bool flag = false;
	for (auto i:finalres)
	{
		if (!flag)
		{
			flag = true;
			cout << i;
		}
		else
		{
			cout << "->" << i;
		}
	}
	cout << endl << "minlen = " << minlen << endl;
	flag = false;
	for (int i = 1; i < finalres.size(); ++i)
	{
		if (!flag)
		{
			flag = true;
			cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
			fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}
		else
		{
			cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
			fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}
		
	}
	fclose(p);
	p = NULL;
	CLOCK_END;
	return 0;
}