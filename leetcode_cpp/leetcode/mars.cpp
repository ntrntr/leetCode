#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int LIMIT = 24 * 3600;

struct car	//���ṹ
{
	int id, time, in_out;	//����id������ʱ�䣬��������
	car(int i = 0, int t = 0, int io = 0) :id(i), time(t), in_out(io){}
};

int to_time(string s);	//���ַ�����ʾ��ʱ��ת��Ϊʱ��
bool cm(const car &c1, const car &c2);	//ʱ������

int main()
{
	int n, k;
	cin >> n >> k;

	map<string, int> name_to_id;	//���Ƶ�idת��
	vector<string> id_to_name(1, "");	//id������ת��
	int id = 0;
	vector<car> data;	//�洢������
	car tempc;			//��ʱ��������
	string sn, st, sf;
	for (int i = 0; i < n; i++)	//������������
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
	sort(data.begin(), data.end(), cm);	//ʱ������

	vector<vector<car>> use(id + 5);	//����id�ĳ�����Ч��¼
	vector<int> total(id + 5, 0);	//����id�ĳ����ܲ���ʱ��
	for (int i = 0; i < data.size(); i++)	//��id���֣�ȥ������Ҫ����
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

	int max = 0;	//�����ʱ��
	vector<string> max_name;	//�����ʱ��ĳ����ĳ��Ƽ���
	for (int i = 1; i <= id; i++)	//ͳ��
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

	data.clear();	//���ԭ���ݣ�����ȡ������Ч��¼��������
	for (int i = 1; i <= id; i++)
		for (int j = 0; j < use[i].size(); j++)
			data.push_back(use[i][j]);
	sort(data.begin(), data.end(), cm);

	int pos = 0, count = 0, next;	//ȡ����λ�ã���ǰѧУ�еĳ��������¸�����ʱ��
	for (int i = 0; i < k; i++)	//ͳ�����
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