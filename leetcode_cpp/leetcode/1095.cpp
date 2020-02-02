#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct node
{
	int time;
	char car[10];
	char state[5];
	node(){}
	node(int t, char * a, char * b):time(t){
		strcpy(car,  a);
		strcpy(state, b);
	}
	bool operator < (const node & b) const
	{
		if (strcmp(car, b.car) == 0)
		{
			return time < b.time;
		}
		else
			return strcmp(car, b.car) == -1;
	}
};

int main()
{
	vector<string> res;
	int maxlen = 0;
	int n,k;
	cin>>n>>k;
	int a,b,c;
	char car[10],state[5];
	vector<node> data;
	map<string, int> mydata;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d:%d:%d %s",car, &a, &b, &c, state);
		data.push_back(node(a * 60 * 60 + b * 60 + c, car, state));
	}
	
	sort(data.begin(), data.end());
	//qsort(data.begin(), data.size(), sizeof(data[0]), com);
	vector<int> carNum(24 * 60 * 60 + 1, 0);
	char curcar[10],curstate[5];
	int curtime = 0;
	int flag = 0;
	//cout<<"-----------------------"<<endl;
	//for (auto it:data)
	//{
	//	cout<<it.car<<" "<<(it.time/3600)<<":"<<(it.time%3600/60)<<":"<<(it.time %3600 % 60)<<" "<<it.state<<endl;
	//}
	//cout<<"-----------------------"<<endl;
	for (int i = 0; i < n; ++i)
	{
		//car change
		if (strcmp(curcar, data[i].car) != 0)
		{
			if (strcmp("in",data[i].state) != 0)
			{
				continue;
			}
			else
			{
				strcpy(curcar,  data[i].car);
				strcpy(curstate, data[i].state);
				curtime = data[i].time;
			}
			
		}
		else
		{
			//car not change
			if (strcmp("out",data[i].state) != 0)
			{
				strcpy(curcar,  data[i].car);
				strcpy(curstate, data[i].state);
				curtime = data[i].time;
			}
			else
			{
				//make pair
				for (int k = curtime; k < data[i].time; ++k)
				{
					++carNum[k];
				}
				if (mydata.find(curcar) != mydata.end())
				{
					mydata[curcar] += data[i].time - curtime;
				}
				else
				{
					mydata.insert(make_pair(curcar, data[i].time - curtime));
				}
				if (mydata[curcar] > maxlen)
				{
					maxlen = mydata[curcar];
					res.clear();
					res.push_back(curcar);
				}
				else if (mydata[curcar] == maxlen)
				{
					res.push_back(curcar);
				}
				strcpy(curcar, "*******");
			}
		}
	}

	for (int i = 0; i < k; ++i)
	{
		scanf("%d:%d:%d",&a, &b, &c);
		cout<<carNum[a * 60 * 60 + b * 60 + c]<<endl;
	}
	sort(res.begin(), res.end());
	for (auto it:res)
	{
		cout<<it<<" ";
	}
	a = maxlen / 3600;
	b = maxlen % 3600;
	c = b % 60;
	b = b / 60;
	printf("%02d:%02d:%02d\n", a, b, c);
	return 0;
}