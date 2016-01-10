//#include <vector>
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <stack>
//#include <unordered_map>
//#include <limits.h>
//using namespace std;
//int mincost = INT_MAX;
//int maxHappniess = INT_MIN;
//vector<string> resPath;
//int mycount = 0;
//string dst = "ROM";
//struct node
//{
//	node(){};
//	node(string& s, int c) :name(s), cost(c){};
//	string name;
//	int cost;
//};
//void dfs(string& cur, int cost, int happyniess, vector<string>& path, map<string, int>& happyData,map<string, vector<node>>& link, map<string, int>& visit)
//{
//	if (cur == dst)
//	{
//		if (cost < mincost)
//		{
//			mincost = cost;
//			mycount = 1;
//			maxHappniess = happyniess;
//			resPath = path;
//			return;
//		}
//		else if (cost == mincost)
//		{
//			if (happyniess > maxHappniess)
//			{
//				++mycount;
//				maxHappniess = happyniess;
//				resPath = path;
//				return;
//			}
//			else if (happyniess == maxHappniess && resPath.size() > path.size())
//			{
//				++mycount;
//				resPath = path;
//				return;
//			}
//		}
//		return;
//	}
//	if (cost > mincost)
//	{
//		return;
//	}
//	for (auto it = link[cur].begin(); it != link[cur].end(); ++it)
//	{
//		if (!visit[it->name])
//		{
//			visit[it->name] = 1;
//			path.push_back(it->name);
//			dfs(it->name, cost + it->cost, happyniess + happyData[it->name], path, happyData, link, visit);
//			path.pop_back();
//			visit[it->name] = 0;
//		}
//	}
//}
//int main()
//{
//	int N, K;
//	string src;
//	cin >> N >> K >> src;
//	map<string, int> visit;
//	map<string, int> happyData;
//	map<string, vector<node>> link;
//	string tmp, tmp1;
//	int tmpHappy, cost;
//	for (int i = 0; i < N - 1; ++i)
//	{
//		cin >> tmp >> tmpHappy;
//		happyData[tmp] = tmpHappy;
//	}
//	for (int i = 0; i < K; ++i)
//	{
//		cin >> tmp >> tmp1 >> cost;
//		link[tmp].push_back(node(tmp1, cost));
//		link[tmp1].push_back(node(tmp, cost));
//	}
//	for (auto it = link.begin(); it != link.end(); ++it)
//	{
//		visit[it->first] = 0;
//	}
//	vector<string> path;
//	path.push_back(src);
//	visit[src] = 1;
//	dfs(src, 0, 0, path, happyData, link, visit);
//	cout << mycount << " " << mincost << " " << maxHappniess <<" "<< (int)(maxHappniess * 1.0 / (resPath.size() - 1)) << endl;
//	for (auto it = resPath.begin(); it != resPath.end(); ++it)
//	{
//		if (it == resPath.end() - 1)
//		{
//			cout << *it << endl;
//		}
//		else
//			cout << *it << " ";
//	}
//	return 0;
//}