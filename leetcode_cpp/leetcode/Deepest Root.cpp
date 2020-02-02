#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int maxx = 10001;

map<int, vector<int> > tree;
set<int> res;
set<int> tres;
int pre[maxx], cnt, maxn = -1;
int visit[maxx];

void dfs(int p, int step){
	if (step > maxn){
		res.clear();
		res.insert(p);
		maxn = step;
	}
	else if (step == maxn){
		res.insert(p);
	}

	vector<int>::iterator ite = tree[p].begin();
	for (; ite != tree[p].end(); ++ite){
		if (visit[*ite] != 1){
			visit[*ite] = 1;
			dfs(*ite, step + 1);
			visit[*ite] = 0;
		}
	}
}

void init(int n){
	int i;

	for (i = 1; i <= n; ++i){
		pre[i] = i;
		visit[i] = 0;
	}
}

int root(int x){
	if (x != pre[x]){
		pre[x] = root(pre[x]);
	}
	return pre[x];
}

void merge(int x, int y){
	int fa = root(x);
	int fb = root(y);
	if (fa != fb){
		pre[fa] = fb;
		--cnt;
	}
}

int main(){
	int n, i, a, b;
	set<int>::iterator ite;
	scanf("%d", &n);
	cnt = n - 1;

	init(n);

	for (i = 1; i < n; ++i){
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		merge(a, b);
	}

	if (cnt != 0){
		printf("Error: %d components\n", 1 + cnt);
		return 0;
	}

	visit[1] = 1;
	dfs(1, 1);
	visit[1] = 0;//因为已经是树，所以不会再有环了，所以所有dfs后都恢复该点的可访问性很重要

	ite = res.begin();
	for (; ite != res.end(); ++ite){
		tres.insert(*ite);
	}


	int point = (*res.begin());
	visit[point] = 1;
	dfs(point, 1);
	visit[point] = 0;

	ite = res.begin();
	for (; ite != res.end(); ++ite){
		tres.insert(*ite);
	}

	ite = tres.begin();
	for (; ite != tres.end(); ++ite){
		printf("%d\n", *ite);
	}

	return 0;
}