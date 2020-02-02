//#include <vector>
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <stack>
//#include <unordered_map>
//#include <limits.h>
//#include <queue>
//#include <deque>
//using namespace std;
//int n, m, k, q;
//vector<deque<int>> f;
//int findpos()
//{
//	int minpos = -1;
//	int minQueue = m;
//	for (int i = 0; i < f.size(); ++i)
//	{
//		if (f[i].size() < minQueue)
//		{
//			minQueue = f[i].size();
//			minpos = i;
//		}
//	}
//	return minpos;
//}
//int popf()
//{
//	int minTime = f[0].front();
//	for (int i = 1; i < f.size(); ++i)
//	{
//		if (f[i].front() < minTime)
//		{
//			minTime = f[i].front();
//		}
//	}
//	for (int i = 0; i < f.size(); ++i)
//	{
//		f[i].front() -= minTime;
//		if (f[i].front() == 0)
//		{
//			f[i].pop_front();
//		}
//	}
//	return minTime;
//}
//int main()
//{
//	
//	cin >> n >> m >> k >> q;
//	vector<int> customersTime(k+1,0);
//	
//	vector<int> leaveTime(k + 1, -1);
//	f.resize(n);
//	for (int i = 1; i <= k; ++i)
//	{
//		cin >> customersTime[i];
//	}
//	int time = 0;
//	int count = 1;
//	int c;
//	while (count <= k)
//	{
//		if ((c = findpos()) != -1)
//		{
//			int sum = 0;
//			for (int i = 0; i < f[c].size(); ++i)
//			{
//				sum += f[c][i];
//			}
//			f[c].push_back(customersTime[count]);
//			leaveTime[count] = time + customersTime[count] + sum;
//			++count;
//		}
//		else
//		{
//			time += popf();
//		}
//		
//	}
//	for (int i = 0; i < q; ++i)
//	{
//		int c;
//		cin >> c;
//		if (leaveTime[c]>540)
//		{
//			cout << "Sorry" << endl;
//		}
//		else
//		printf("%02d:%02d\n", 8 + leaveTime[c] / 60, leaveTime[c] % 60);
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int N;// (<=20, number of windows)
int M;// (<=10, the maximum capacity of each line inside the yellow line)
int K;// (<=1000, number of customers)
int Q;// (<=1000, number of customer queries)
#define INF 0x6FFFFFFF
typedef struct Customer
{
	int process;
	int leave;
}Customer;

int main()
{
	//input
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	vector<Customer> cus(K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &cus[i].process);
		cus[i].leave = INF;
	}
	//process
	vector<queue<int>> winQueue(N);
	vector<int> timeBase(N, 0);
	int p;
	for (p = 0; p < N*M && p < K; ++p)
	{
		cus[p].leave = timeBase[p%N] + cus[p].process;
		timeBase[p%N] = cus[p].leave;
		winQueue[p%N].push(p);
	}
	//for somebody out of the normal queue
	for (; p < K; ++p)
	{
		int mmin = INF;
		int index = -1;
		for (int j = 0; j < N; ++j)
		{
			int top = winQueue[j].front();
			if (mmin > cus[top].leave)
			{
				index = j;
				mmin = cus[top].leave;
			}
		}
		//then pop 
		cus[p].leave = timeBase[index] + cus[p].process;
		timeBase[index] = cus[p].leave;
		winQueue[index].pop();
		winQueue[index].push(p);
	}

	//query 
	for (int i = 0; i < Q; ++i)
	{
		int q;
		scanf("%d", &q);
		q--;
		if (cus[q].leave - cus[q].process >= 540)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", 8 + cus[q].leave / 60, cus[q].leave % 60);
	}
	return 0;
}