#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;

vector<vector<int> > cost;      // 记录每条边的花费，为0表示不通
vector<bool> visited;           // 判断是否访问过
vector<int> happiness, path;    // 节点的幸福度，中间路径
map<string, int> cityMap;       // 节点映射，求出城市编号
vector<string> numMap;
vector<int> numOfLeastCostRoute, citiesInRoute; // 最短路径数、路径上的节点数（不包括第一个）
vector<int> totalHappiness, totalCost;          // 节点0到节点i的总幸福度，总费用（最小值）
int N, K; 
string startCity;
void dijkstra()
{
	totalCost[0] = 0;
	numOfLeastCostRoute[0] = 1;
	citiesInRoute[0] = 0;

	int k; // k为每轮中花费最少的城市
	for (int i = 0; i < N; i++) {
		k = -1;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && (k < 0 || totalCost[j] < totalCost[k])) {
				k = j;
			}
		}
		visited[k] = true;
		// 优化
		for (int j = 0; j < N; j++) {
			if (!visited[j] && cost[k][j] > 0) {
				int tempCost = totalCost[k] + cost[k][j];
				if (tempCost < totalCost[j]) {
					totalCost[j] = tempCost;
					numOfLeastCostRoute[j] = numOfLeastCostRoute[k];
					path[j] = k;
					totalHappiness[j] = totalHappiness[k] + happiness[j];
					citiesInRoute[j] = citiesInRoute[k] + 1;
				}
				else if (tempCost == totalCost[j]) {
					numOfLeastCostRoute[j] += numOfLeastCostRoute[k];
					if (totalHappiness[j] < (totalHappiness[k] + happiness[j])
						|| (totalHappiness[j] == totalHappiness[k] + happiness[j]
						&& citiesInRoute[j] > citiesInRoute[k] + 1)) {
						path[j] = k;
						totalHappiness[j] = totalHappiness[k] + happiness[j];
						citiesInRoute[j] = citiesInRoute[k] + 1;
					}
				}
			}
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	// 读入基本数据
	cin >> N >> K >> startCity;
	// 初始化变量
	cost.resize(N, vector<int>(N, 0));
	visited.resize(N, false);
	happiness.resize(N, 0);
	path.resize(N, -1);
	numMap.resize(N);
	numOfLeastCostRoute.resize(N, 0);
	citiesInRoute.resize(N, INT_MAX);
	totalHappiness.resize(N, 0);
	totalCost.resize(N, INT_MAX);
	// 读取幸福度和费用
	numMap[0] = startCity;
	cityMap[startCity] = 0;
	for (int i = 1; i < N; i++) {
		cin >> numMap[i] >> happiness[i];
		cityMap[numMap[i]] = i;
	}
	string srcCity, desCity; int src, des, tempCost;
	for (int i = 0; i < K; i++) {
		cin >> srcCity >> desCity >> tempCost;
		src = cityMap[srcCity];
		des = cityMap[desCity];
		cost[src][des] = tempCost;
		cost[des][src] = tempCost;
	}

	//计算并输出结果
	dijkstra();
	int end = cityMap["ROM"];
	cout << numOfLeastCostRoute[end] << " " << totalCost[end] << \
		" " << totalHappiness[end] << " " << (totalHappiness[end]\
		/ citiesInRoute[end]) << endl;
	vector<string> route;
	while (end != -1) {
		route.push_back(numMap[end]);
		end = path[end];
	}
	for (int i = route.size() - 1; i > 0; i--) {
		cout << route[i] << "->";
	}
	cout << route[0];

	return 0;
}

