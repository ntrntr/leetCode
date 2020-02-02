#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int LIMIT = 24 * 3600;

struct car	//车结构
{
	int id, time, in_out;	//车的id，动作时间，进出动作
	car(int i = 0, int t = 0, int io = 0) :id(i), time(t), in_out(io){}
};

int to_time(string s);	//将字符串表示的时间转换为时间
bool cm(const car &c1, const car &c2);	//时间排序

int main()
{
	int n, k;
	cin >> n >> k;

	map<string, int> name_to_id;	//车牌到id转换
	vector<string> id_to_name(1, "");	//id到车牌转换
	int id = 0;
	vector<car> data;	//存储的数据
	car tempc;			//临时输入数据
	string sn, st, sf;
	for (int i = 0; i < n; i++)	//输入所有数据
	{
		cin >> sn >> st >> sf;
		if (name_to_id[sn] == 0)
		{
			name_to_id[sn] = ++id;
			id_to_name.push_back(sn);
		}
		tempc.id = name_to_id[sn];
		tempc.time = to_time(st);
		if (sf == "in")
			tempc.in_out = 1;
		else
			tempc.in_out = 0;
		data.push_back(tempc);
	}
	sort(data.begin(), data.end(), cm);	//时间排序

	vector<vector<car>> use(id + 5);	//各个id的车的有效记录
	vector<int> total(id + 5, 0);	//各个id的车的总泊车时间
	for (int i = 0; i < data.size(); i++)	//按id划分，去除不必要数据
	{
		if (data[i].in_out == 1)
		{
			if (!use[data[i].id].empty() && use[data[i].id].back().in_out == 1)
				use[data[i].id].pop_back();
			use[data[i].id].push_back(data[i]);
		}
		else
		{
			if (!use[data[i].id].empty() && use[data[i].id].back().in_out == 1)
			{
				total[data[i].id] += data[i].time - use[data[i].id].back().time;
				use[data[i].id].push_back(data[i]);
			}
		}
	}
	for (int i = 0; i<use.size(); i++)
	{
		if (!use[i].empty() && use[i].back().in_out == 1)
			use[i].pop_back();
	}

	int max = 0;	//最长泊车时间
	vector<string> max_name;	//最长泊车时间的车辆的车牌集合
	for (int i = 1; i <= id; i++)	//统计
	{
		if (!use[i].empty() && total[i] == max)
			max_name.push_back(id_to_name[use[i].front().id]);
		else if (!use[i].empty() && total[i]>max)
		{
			max = total[i];
			max_name.clear();
			max_name.push_back(id_to_name[use[i].front().id]);
		}
	}
	sort(max_name.begin(), max_name.end());

	data.clear();	//清除原数据，重新取所有有效记录，并排序
	for (int i = 1; i <= id; i++)
		for (int j = 0; j < use[i].size(); j++)
			data.push_back(use[i][j]);
	sort(data.begin(), data.end(), cm);

	int pos = 0, count = 0, next;	//取到的位置，当前学校中的车辆数，下个请求时间
	for (int i = 0; i < k; i++)	//统计输出
	{
		cin >> st;
		next = to_time(st);
		while (pos < data.size() && data[pos].time <= next)
		{
			if (data[pos].in_out == 1)
				count++;
			else
				count--;
			pos++;
		}
		printf("%d\n", count);
	}
	for (int i = 0; i < max_name.size(); i++)
		cout << max_name[i] << " ";
	printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);

	return 0;
}

int to_time(string s)
{
	int time = 0;
	time += (s[0] - '0') * 10 * 3600;
	time += (s[1] - '0') * 3600;
	time += (s[3] - '0') * 10 * 60;
	time += (s[4] - '0') * 60;
	time += (s[6] - '0') * 10;
	time += (s[7] - '0');
	return time;
}

bool cm(const car &c1, const car &c2)
{
	return c1.time < c2.time;
}