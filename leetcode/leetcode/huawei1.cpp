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
#include <set>
using namespace std;
#define INF 100000000
clock_t m_begin, m_end;
#define CLOCK_START m_begin = clock()
#define CLOCK_END printf("\n%f seconds\n", (double)(clock() - m_begin)/CLOCKS_PER_SEC)
map<pair<int, int>, int> numToLink;
vector<vector<int>> link(600, vector<int>(600, INF));
vector<bool> visited;
vector<int> distanceDij;
vector<int> previous;
vector<int> pass;
int minlen = INF;
int minlen1 = INF;
vector<int> path;
vector<int> finalres;
vector<int> shuffle;
vector<vector<long int>> distanceFord(600, vector<long int>(600, INF));
vector<vector<int>> pathFord(600, vector<int>(600, INF));
int startPoint, endPoint;
void initDij()
{
	visited = vector<bool>(600, false);
	distanceDij = vector<int>(600, INF);
	previous = vector<int>(600, -1);
}
vector<int> getPathDij(int a, int b)
{
	vector<int> myres;
	myres.clear();
	myres.push_back(b);
	int idx = b;
	while (idx != -1 && previous[idx] != a)
	{
		myres.push_back(previous[idx]);
		idx = previous[idx];
	}
	myres.push_back(a);
	reverse(myres.begin(), myres.end());
	return myres;
}
void printDij(vector<int>& res)
{
	bool flag = false;
	for (auto i:res)
	{
		if (!flag)
		{
			flag = !flag;
			cout << i;
		}
		else
			cout << "->" << i;
	}
	//cout << endl;
}
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
		if (i != start && link[start][i] != INF && !visited[i])
		{
			visited[i] = true;
			path.push_back(i);
			dfs(i, end, curlen + link[start][i]);
			path.pop_back();
			visited[i] = false;
		}
	}
}
void Dijkstra()
{

	initDij();
	distanceDij[startPoint] = 0;
	for (int i = 0; i < 600; ++i)
	{
		int u = -1;
		int minLen = INF;
		for (int j = 0; j < 600; ++j)
		{
			if (!visited[j] && distanceDij[j] < minLen)
			{
				minLen = distanceDij[j];
				u = j;
			}
		}
		if (u == endPoint)
		{
			return;
		}
		visited[u] = true;
		for (int v = 0; v < 600; ++v)
		{
			if (!visited[v] && link[u][v]!= INF)
			{
				if (distanceDij[v] > distanceDij[u] + link[u][v])
				{
					previous[v] = u;
					distanceDij[v] = distanceDij[u] + link[u][v];
				}
			}
		}
	}
}
void Dijkstra1()
{
	initDij();
	distanceDij[startPoint] = 0;
	for (int i = 0; i < 600; ++i)
	{
		int u = -1;
		int minLen = INF;
		for (int j = 0; j < 600; ++j)
		{
			if (!visited[j] && distanceDij[j] < minLen)
			{
				minLen = distanceDij[j];
				u = j;
			}
			
		}
		if (u == endPoint)
		{
			return;
		}
		visited[u] = true;
		for (int v = 0; v < 600; ++v)
		{
			if (!visited[v] && link[u][v] != INF)
			{
				if (find(pass.begin(),pass.end(), v)!= pass.end())
				{
					previous[v] = u;
					distanceDij[v] = distanceDij[u] + link[u][v];
				}
				else if (distanceDij[v] > distanceDij[u] + link[u][v])
				{
					previous[v] = u;
					distanceDij[v] = distanceDij[u] + link[u][v];
				}
			}
		}
	}
}
vector<int> Dijkstra2(int startp, int endp)
{
	initDij();
	distanceDij[startp] = 0;
	vector<int> res;
	for (int i = 0; i < 600; ++i)
	{
		int u = -1;
		int minLen = INF;
		for (int j = 0; j < 600; ++j)
		{
			if (!visited[j] && distanceDij[j] < minLen)
			{
				minLen = distanceDij[j];
				u = j;
			}

		}
		if (u == endp)
		{
			return getPathDij(startp, endp);
		}
		visited[u] = true;
		for (int v = 0; v < 600; ++v)
		{
			if (!visited[v] && link[u][v] != INF)
			{
				if (distanceDij[v] > distanceDij[u] + link[u][v])
				{
					previous[v] = u;
					distanceDij[v] = distanceDij[u] + link[u][v];
				}
			}
		}
	}
	return res;
}
vector<int> Dijkstra3(int startp, int endp, set<int>& myvisit)
{
	initDij();
	distanceDij[startp] = 0;
	for (auto i:myvisit)
	{
		visited[i] = true;
	}
	visited[startp] = false;
	vector<int> res;
	for (int i = 0; i < 600; ++i)
	{
		int u = -1;
		int minLen = INF;
		for (int j = 0; j < 600; ++j)
		{
			if (!visited[j] && distanceDij[j] < minLen)
			{
				minLen = distanceDij[j];
				u = j;
			}

		}
		if (u == endp)
		{
			return getPathDij(startp, endp);
		}
		if (u == -1)
		{
			return res;
		}
		visited[u] = true;
		for (int v = 0; v < 600; ++v)
		{
			if (!visited[v] && link[u][v] != INF)
			{
				if (distanceDij[v] > distanceDij[u] + link[u][v])
				{
					previous[v] = u;
					distanceDij[v] = distanceDij[u] + link[u][v];
				}
			}
		}
	}
	return res;
}
void Floyd()
{
	int i, j, k;
	for (i = 0; i < 600; ++i)
	{
		for (j = 0; j < 600; ++j)
		{
				distanceFord[i][j] = link[i][j];
				pathFord[i][j] = -1;
		}
	}
	for (k = 0; k < 600; ++k)
	{
		for (i = 0; i < 600; ++i)
		{
			for (j = 0; j < 600; ++j)
			{
				if ((long int)distanceFord[i][j] > (long int)(distanceFord[i][k] + distanceFord[k][j]))
				{
					distanceFord[i][j] = distanceFord[i][k] + distanceFord[k][j];
					pathFord[i][j] = k;
				}
			}
		}
	}
}
void createFile(int pointsNum, int pa)
{
	FILE *p = NULL;
	int count = 0;
	p = fopen("d:\\topo.csv", "w");
	srand((unsigned int)time(NULL));
	int len = 0;
	set<int> tmp;
	int c;
	for (int i = 0; i <= pointsNum; ++i)
	{
		tmp.clear();
		while (tmp.size() < 8)
		{
			c = i;
			while (c == i)
			{
				c = rand() % (pointsNum + 1);
			}
			tmp.insert(c);
		}
		for (auto j:tmp)
		{
			fprintf(p,"%d,%d,%d,%d\n", count++, i, j, (rand() % 20) + 1);
		}
	}
	fclose(p);
	p = NULL;

	p = fopen("d:\\demand.csv", "w");
	int start = rand() % pointsNum;
	int end = start;
	while (end == start)
	{
		end = rand() % pointsNum;
	}
	fprintf(p, "%d,%d,", start, end);
	tmp.clear();
	while (tmp.size() < pa)
	{
		c = start;
		while (c == start || c == end)
		{
			c = rand() % (pointsNum + 1);
		}
		tmp.insert(c);
	}
	int flag = false;
	for (auto i:tmp)
	{
		if (!flag)
		{
			flag = true;
			fprintf(p, "%d", i);
		}
		else
		{
			fprintf(p, "|%d", i);
		}
	}
	fclose(p);
	p = NULL;
	return;
}
void floydprint(int a, int b)
{
	if (pathFord[a][b] >= 0)
	{
		floydprint(a, pathFord[a][b]);
		floydprint(pathFord[a][b], b);
	}
	else cout << "->" << b;
}
vector<int> getMycount(vector<int>& a)
{
	vector<int> res;
	for (int i = 0; i < a.size(); ++i)
	{
		if (find(pass.begin(),pass.end(),a[i])!= pass.end())
		{
			res.push_back(a[i]);
		}
	}
	return res;
}
void mydijdfs(int prev, int endp,int len ,set<int>& myvisit, vector<int>& mydijpath, int count)
{
	if (len > minlen)
	{
		return;
	}
	if (count-1 == pass.size())
	{
		vector<int> tmp = Dijkstra3(prev, endp, myvisit);
		if (tmp.size() == 0)
		{
			return;
		}
		int finallen = len + distanceDij[endp];
		if (minlen > finallen)
		{
			finalres.clear();
			finalres.assign(mydijpath.begin(), mydijpath.end());
			for (int j = 1; j < tmp.size(); ++j)
			{
				finalres.push_back(tmp[j]);
			}
			minlen = finallen;
			//cout << "///////////////////////////////////////////////////////////////////////"<< endl;
			//cout << minlen << endl;
			//for (auto i : finalres)
			//{
			//	cout << i << "->";
			//}
			//cout << endl;
			//bool flag = false;
			//for (int i = 1; i < finalres.size(); ++i)
			//{
			//	if (!flag)
			//	{
			//		flag = true;
			//		cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//		//fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
			//	}
			//	else
			//	{
			//		cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//		//fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
			//	}

			//}
			//cout << endl<<"//////////////////////////////////////////////////////////////////////////"<< endl;
		}
		return;
	}
	for (int i = 0; i < pass.size(); ++i)
	{
		if (myvisit.find(pass[i])!= myvisit.end())
		{
			continue;
		}
		vector<int> tmp = Dijkstra3(prev, pass[i], myvisit);
		if (tmp.size()==0)
		{
			continue;
		}
		int tmplen = distanceDij[pass[i]];
		set<int> mytmpset = myvisit;
		vector<int> mytmppath = mydijpath;
		int tmpcount = 0;
		for (int j = 1; j < tmp.size(); ++j)
		{
			if (binary_search(pass.begin(), pass.end(), tmp[j]))
			{
				tmpcount++;
			}
			myvisit.insert(tmp[j]);
			
		}
		for (int j = 1; j < tmp.size(); ++j)
		{
			mydijpath.push_back(tmp[j]);
		}
		mydijdfs(pass[i], endp, len + tmplen, myvisit, mydijpath, count + tmpcount);
		myvisit = mytmpset;
		mydijpath = mytmppath;
	}
}
void mydijdfs1(int prev, int endp, int len, set<int>& myvisit, vector<int>& mydijpath, int count)
{
	if (len > minlen)
	{
		return;
	}
	if (count - 1 == pass.size())
	{
		vector<int> tmp = Dijkstra3(prev, endp, myvisit);
		if (tmp.size() == 0)
		{
			return;
		}
		int finallen = len + distanceDij[endp];
		if (minlen > finallen)
		{
			finalres.clear();
			finalres.assign(mydijpath.begin(), mydijpath.end());
			for (int j = 1; j < tmp.size(); ++j)
			{
				finalres.push_back(tmp[j]);
			}
			minlen = finallen;
			//cout << "///////////////////////////////////////////////////////////////////////"<< endl;
			//cout << minlen << endl;
			//for (auto i : finalres)
			//{
			//	cout << i << "->";
			//}
			//cout << endl;
			//bool flag = false;
			//for (int i = 1; i < finalres.size(); ++i)
			//{
			//	if (!flag)
			//	{
			//		flag = true;
			//		cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//		//fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
			//	}
			//	else
			//	{
			//		cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//		//fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
			//	}

			//}
			//cout << endl<<"//////////////////////////////////////////////////////////////////////////"<< endl;
		}
		return;
	}
	for (int i = 0; i < pass.size(); ++i)
	{
		if (myvisit.find(pass[i]) != myvisit.end())
		{
			continue;
		} 
		vector<int> tmp = Dijkstra3(prev, pass[i], myvisit);
		if (tmp.size() == 0)
		{
			continue;
		}
		int tmplen = distanceDij[pass[i]];
		set<int> mytmpset = myvisit;
		vector<int> mytmppath = mydijpath;
		int tmpcount = 0;
		for (int j = 1; j < tmp.size(); ++j)
		{
			if (binary_search(pass.begin(), pass.end(), tmp[j]))
			{
				tmpcount++;
			}
			myvisit.insert(tmp[j]);

		}
		for (int j = 1; j < tmp.size(); ++j)
		{
			mydijpath.push_back(tmp[j]);
		}
		mydijdfs(pass[i], endp, len + tmplen, myvisit, mydijpath, count + tmpcount);
		myvisit = mytmpset;
		mydijpath = mytmppath;
	}
}
void mydij(int startp, int endp)
{
	vector<int> dis(pass.size(), 0);
	vector<vector<int>> tpath;
	int prevPos = startp;
	set<int> myvisit;
	myvisit.insert(startp);
	vector<int> mydijpath;
	mydijpath.push_back(startp);
	mydijdfs(startp, endp, 0, myvisit, mydijpath,1);
	/*for (int i = 0; i < pass.size(); ++i)
	{
	int u = -1;
	int minLen = INF;
	vector<int> tmppath;
	for (int j = 0; j < pass.size(); ++j)
	{
	if (myvisit.find(pass[i]) != myvisit.end())
	{
	continue;
	}
	tpath.push_back(Dijkstra3(prevPos, pass[j], myvisit));
	dis[j] = distanceDij[pass[j]];
	if (minLen > dis[j])
	{
	u = j;
	minLen = dis[j];
	tmppath = tpath[j];
	}
	else if (minLen == dis[j])
	{
	if ((getMycount(tpath[u])).size() < (getMycount(tpath[j])).size())
	{
	u = j;
	minLen = dis[j];
	tmppath = tpath[j];
	}
	}
	}
	if (u == -1)
	{
	Dijkstra3(prevPos, endPoint, myvisit);
	}
	prevPos = u;
	int tmplen = minLen;
	myvisit.insert(tmppath.begin(), tmppath.end());
	for (int v = 0; v < pass.size(); ++v)
	{
	if (myvisit.find(pass[v]) != myvisit.end())
	{
	continue;
	}
	Dijkstra3(prevPos, pass[v], myvisit);
	int tmp = dis[v];
	}

	}*/
	/*for (int j = 0; j < 600; ++j)
	{
		if (!visited[j] && distanceDij[j] < minLen)
		{
			minLen = distanceDij[j];
			u = j;
		}
	}
	if (u == endPoint)
	{
		return;
	}
	visited[u] = true;
	for (int v = 0; v < 600; ++v)
	{
		if (!visited[v] && link[u][v] != INF)
		{
			if (distanceDij[v] > distanceDij[u] + link[u][v])
			{
				previous[v] = u;
				distanceDij[v] = distanceDij[u] + link[u][v];
			}
		}
	}*/
	//for (int i = 0; i < pass.size(); ++i)
	//{
	//	cout << pass[i] << " " << dis[i] << endl;
	//	for (auto j:tpath[i])
	//	{
	//		cout << j << " ";
	//	}
	//	cout << endl;
	//}
	//cout << pass[u];
}
void mydij2(int startp, int endp)
{
	int i, j;
	vector<int> cur(pass.begin(), pass.end());
	vector<vector<int>> tpath;
	int prevPos = startp;
	set<int> myvisit;
	myvisit.insert(startp);
	vector<int> mydijpath;
	
	while (true)
	{
		mydijpath.clear();
		mydijpath.push_back(startp);
		myvisit.clear();
		myvisit.insert(startp);
		int prev = startp;
		int len = 0;
		bool flag = true;
		for (i = 0; i < cur.size(); ++i)
		{
			if (myvisit.find(cur[i]) != myvisit.end())
			{
				continue;
			}
			vector<int> tmp = Dijkstra3(prev, cur[i], myvisit);
			if (tmp.size() == 0)
			{
				flag = false;
				break;
			}
			prev = cur[i];
			len += distanceDij[cur[i]];
			if (len > minlen1)
			{
				flag = false;
				break;
			}
			for (j = 1; j < tmp.size(); ++j)
			{
				myvisit.insert(tmp[j]);
				mydijpath.push_back(tmp[j]);
			}
		}
		if (i == cur.size() && flag)
		{
			vector<int> tmp = Dijkstra3(prev, endp, myvisit);
			if (tmp.size() == 0)
			{
				continue;
			}
			len += distanceDij[endp];
			if (minlen1 > len)
			{
				finalres.clear();
				finalres.assign(mydijpath.begin(), mydijpath.end());
				for (int j = 1; j < tmp.size(); ++j)
				{
					finalres.push_back(tmp[j]);
				}
				minlen1 = len;
				cout << "///////////////////////////////////////////////////////////////////////" << endl;
				cout << minlen << endl;
				for (auto i : finalres)
				{
					cout << i << "->";
				}
				cout << endl;
				bool flag = false;
				for (int i = 1; i < finalres.size(); ++i)
				{
					if (!flag)
					{
						flag = true;
						cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
						//fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
					}
					else
					{
						cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
						//fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
					}

				}
				cout << endl << "//////////////////////////////////////////////////////////////////////////" << endl;
			}
		}
		bool flag2 = next_permutation(cur.begin(), cur.end());
		if (!flag2)
		{
			break;
		}
	}
}
int main()
{
	
	int a, b, c, d;
	int i, j;
	
	createFile(599,4);
	CLOCK_START;
	
	FILE *p = NULL;
	p = fopen("d:\\topo.csv", "r");
	while (!feof(p) && fscanf(p, "%d,%d,%d,%d\n", &a, &b, &c, &d))
	{
		if (link[b][c] > d)
		{
			link[b][c] = min(d, link[b][c]);
			numToLink[make_pair(b, c)] = a;
		}
		
	}
	fclose(p);
	for (int i = 0; i < 600; ++i)
	{
		link[i][i] = 0;
	}
	p = NULL;
	p = fopen("d:\\demand.csv", "r");
	
	char s[200];
	fscanf(p, "%d,%d,%s\n", &startPoint, &endPoint, s);
	cout << "起点:"<<startPoint << "\n终点:" << endPoint << "\n经过点:" << s<<endl;
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

//////////////////////////////////////////////////////////////////////////
	//dfs
	/*visited = vector<bool>(600, false);
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
	p = NULL;*/
	
//////////////////////////////////////////////////////////////////////////
	
	CLOCK_END;
	//////////////////////////////////////////////////////////////////////////
//dij
	CLOCK_START;
	Dijkstra();
	cout << distanceDij[endPoint] << endl;
	vector<int> myres = getPathDij(startPoint, endPoint);
	printDij(myres);
	CLOCK_END;
	//////////////////////////////////////////////////////////////////////////
	CLOCK_START;
	Dijkstra1();
	myres = getPathDij(startPoint, endPoint);
	cout << distanceDij[endPoint] << endl;
	printDij(myres);
	CLOCK_END;
	/*CLOCK_START;
	Floyd();
	cout << distanceFord[startPoint][endPoint]<<endl;
	cout << startPoint;
	floydprint(startPoint, endPoint);
	CLOCK_END;*/
	CLOCK_START;
	mydij(startPoint, endPoint);
	cout << minlen << endl;
	int tmpsum = 0;
	int prevp = (finalres.size() > 0) ? finalres[0]: -1;
	bool tmpflag = false;
	for (auto i : finalres)
	{
		if (!tmpflag)
		{
			tmpflag = !tmpflag;
		}
		else
		{
			tmpsum += link[prevp][i];
			prevp = i;
		}
		cout << i << "->";
	}
	cout << endl;
	cout <<"len = "<< tmpsum << endl;
	bool flag = false;
	for (int i = 1; i < finalres.size(); ++i)
	{
		if (!flag)
		{
			flag = true;
			cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}
		else
		{
			cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}

	}
	CLOCK_END;
	CLOCK_START;
	mydij2(startPoint, endPoint);
	cout << minlen1 << endl;
	tmpsum = 0;
	prevp = (finalres.size() > 0) ? finalres[0]: -1;
	 tmpflag = false;
	for (auto i : finalres)
	{
		if (!tmpflag)
		{
			tmpflag = !tmpflag;
		}
		else
		{
			tmpsum += link[prevp][i];
			prevp = i;
		}
		cout << i << "->";
	}
	cout << endl;
	cout << "len = " << tmpsum << endl;
	flag = false;
	for (int i = 1; i < finalres.size(); ++i)
	{
		if (!flag)
		{
			flag = true;
			cout << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//fprintf(p, "%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}
		else
		{
			cout << "|" << numToLink[make_pair(finalres[i - 1], finalres[i])];
			//fprintf(p, "|%d", numToLink[make_pair(finalres[i - 1], finalres[i])]);
		}

	}

	CLOCK_END;
	return 0;
}