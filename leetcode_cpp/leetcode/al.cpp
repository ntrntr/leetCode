#include<iostream>
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
class A
{
public:
	virtual void f()
	{
		cout << "A::f()";
	}
	void f() const
	{
		cout << "A::f() const" << endl;
	}
};

class B : public A
{
public:
	void f()
	{
		cout << "B::f()";
	}
	void f() const
	{
		cout << "B::f() const" << endl;
	}
};

void g(const A* a)
{
	a->f();
}
//////////////////////////////////////////////////////////////////////////
//anwser1
vector<double> BatchQueryExecutionTime(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {

	// your code
	vector<double> res(keywords.size());
	//用于cache缓存
	map<string, int> cache;
	map<pair<int, string>, int> cc;
	for (int i = 0; i < keywords.size(); ++i)
	{
		if (cache.find(keywords[i]) != cache.end())
		{
			res[i] = cache[keywords[i]];
			continue;
		}
		int count = 0;
		double time = 0;
		for (int j = 0; j < sqls.size(); ++j)
		{
			if (sqls[j].find(keywords[i]) != string::npos)
			{
				count++;
				time += times[j];
			}
		}
		if (count == 0)
		{
			res[i] = 0.0;
		}
		else
		{
			res[i] = time / count;
		}
		cache[keywords[i]] = res[i];
		
	}
	return res;
}

struct SQL {

	string text; //SQL语句

	int kind;//所属分类

	double time;//执行时间

};



struct Query {

	string keyword;// 查询关键词

	int kind;// 查询分类

	int id;// 查询标示，为传入查询列表的下标

};
pair<double, int> myquery(int kind, string key, const vector<vector<int>>&kindsTree, const vector<SQL>&sqls, map<pair<int, string>, pair<double, int>>& cache)
{
	//查找该分类对于该关键字是否有记录，如果没有计算count和time。
	//	计算该id之类的关于该关键字的记录，如果没有计算count和time。
	//	用map缓存该条记录，下次来直接取出。
	//	记录该值到结果。
	pair<double, int> res;
	pair<int, string> tmp(kind, key);
	if (cache.find(tmp) != cache.end())
	{
		return cache[tmp];
	}
	int count = 0;
	double time = 0;
	for (int j = 0; j < sqls.size(); ++j)
	{
		if (sqls[j].kind == kind)
		{
			if (sqls[j].text.find(key) != string::npos)
			{
				time += sqls[j].time;
				count++;	
			}
		}
	}
	for (int j = 0; j < kindsTree[kind].size(); ++j)
	{
		pair<double, int> ttt = myquery(kindsTree[kind][j], key, kindsTree, sqls, cache);
		time += ttt.first;
		count += ttt.second;
		
	}
	res = cache[tmp] = make_pair(time, count);
	return res;
}
vector<double> BatchQueryExecutionTime(int kindSize, const vector<vector<int>>&kindsTree, const vector<SQL>&sqls, const vector<Query>&queries) {

	// your code
	vector<double> res(queries.size());
	//kind, key              sumtime, count
	map<pair<int, string>, pair<double, int>> cache;
	
	for (int i = 0; i < queries.size(); ++i)
	{
		pair<double, int> tmp = myquery(queries[i].kind, queries[i].keyword, kindsTree, sqls, cache);
		if (tmp.second == 0)
		{
			res[i] = 0;
		}
		else
		{
			res[i] = tmp.first / tmp.second;
		}
		
	}
	return res;
}
int main()
{
	cout << (int)-1.5 << endl;
	/*vector<string> sqls{ "insert into tableA values1",

		"insert into tableB values(2,",

		"select columnA, columnC from tableB"
	};
	vector<double> times{ 2.5, 12.5, 30.0 };
	vector<string> key{ "tableB", "insert", "select", "tableA"
	};
	for (auto i : BatchQueryExecutionTime(sqls, times, key))
	{
		cout << i << endl;
	}
*/

}