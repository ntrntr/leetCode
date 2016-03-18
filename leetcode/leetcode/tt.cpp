//1026. Table Tennis (30)

//题意：
//	1.当前无vip用户时，普通用户按照空余桌子的号码依次就坐。
//	2.当前有vip用户，没有空余的vip桌子时，vip当做普通用户进入队列排序；
//	                 有空余的vip桌子时，应该先就做vip座位；
//
//基本算法：
//	类似于mergeSort的方法，将vip用户和扑通用户区分，然后分别sort，接下来计算merge看每个用户进入队列的时间。
//	排队题的基本思考方法是考虑当前用户何时进入排队队列中。
//
//注意：
//	计算等待时间，是需要四舍五入。
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

typedef struct Player
{
	int ArriveTime;
	int ServeTime;
	int P;
}Player;

int N, K, M;
bool VipTableNum[105] = { false };
vector<Player> Ordinary;
vector<Player> Vip;

vector<int> NumOfServeTable;

bool cmp(Player p1, Player p2)
{
	return (p1.ArriveTime < p2.ArriveTime);
}

void OutPutTime(int tmp)
{
	int hh, mm, ss;
	ss = tmp % 60;
	mm = tmp / 60 % 60;
	hh = tmp / 3600;
	printf("%02d:%02d:%02d ", hh, mm, ss);
}

void OutPut(Player p)
{
	OutPutTime(p.ArriveTime);
	OutPutTime(p.ServeTime);
	cout << (p.ServeTime - p.ArriveTime + 30) / 60 << endl;
}

int main(void)
{
#ifdef ONLINE_JUDGE
#else
	freopen("D:\\1.txt", "r", stdin);
#endif

	scanf("%d", &N);
	Player tmp;
	int i, j;
	int hh, mm, ss;
	int flag;
	for (i = 0; i < N; i++)
	{
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tmp.P, &flag);

		if (hh >= 21)
		{
			continue;
		}

		if (tmp.P > 120)
		{
			tmp.P = 120;
		}

		tmp.ArriveTime = hh * 3600 + mm * 60 + ss;
		if (flag == 0)
		{
			Ordinary.push_back(tmp);
		}
		else
			Vip.push_back(tmp);
	}

	scanf("%d %d", &K, &M);
	for (i = 0; i < M; i++)
	{
		cin >> hh;
		VipTableNum[hh] = true;
	}

	NumOfServeTable.resize(K + 1);
	fill(NumOfServeTable.begin(), NumOfServeTable.end(), 0);

	sort(Ordinary.begin(), Ordinary.end(), cmp);
	sort(Vip.begin(), Vip.end(), cmp);

	i = 0;
	j = 0;
	int CurrTime[105];
	fill(CurrTime, CurrTime + K + 1, 8 * 3600);

	int ordtime, viptime;

	int MinTime = 21 * 3600;
	int MinTimeIndex = -1;

	int i1;
	while (i + j < Ordinary.size() + Vip.size())
	{
		MinTime = 21 * 3600;
		ordtime = 21 * 3600;
		viptime = 21 * 3600;

		for (i1 = 1; i1 <= K; i1++)
		{
			if (CurrTime[i1] < MinTime)
			{
				MinTime = CurrTime[i1];
				MinTimeIndex = i1;
			}
		}

		if (i < Ordinary.size())
		{
			ordtime = Ordinary[i].ArriveTime;
			if (ordtime < MinTime)
			{
				ordtime = MinTime;
			}
		}

		if (j < Vip.size())
		{
			viptime = Vip[j].ArriveTime;
			if (viptime < MinTime)
			{
				viptime = MinTime;
			}
		}

		bool serveVip = true;
		if (ordtime < viptime && ordtime < 21 * 3600)// serve ordinary player
		{
			serveVip = false;
		}
		else if (ordtime > viptime && viptime < 21 * 3600) //vip
		{
			serveVip = true;
		}
		else if (ordtime == viptime && viptime < 21 * 3600)
		{
			if (VipTableNum[MinTimeIndex] ||
				(!VipTableNum[MinTimeIndex] && Vip[j].ArriveTime < Ordinary[i].ArriveTime))
			{
				//vip
				serveVip = true;
			}
			else
			{
				//ordinary
				serveVip = false;
			}
		}
		else if (ordtime == 21 * 3600 && viptime == 21 * 3600)
		{
			break;
		}

		if (serveVip)
		{
			//判断当前时间是否有空余的vip窗口
			if (VipTableNum[MinTimeIndex] == false)
			{
				for (i1 = 1; i1 <= K; i1++)
				{
					if (VipTableNum[i1] && CurrTime[i1] == MinTime)
					{
						MinTimeIndex = i1;
					}
				}
			}

			Vip[j].ServeTime = viptime;
			CurrTime[MinTimeIndex] = viptime + Vip[j].P * 60;
			OutPut(Vip[j]);
			NumOfServeTable[MinTimeIndex]++;
			j++;
		}
		else
		{
			Ordinary[i].ServeTime = ordtime;
			CurrTime[MinTimeIndex] = ordtime + Ordinary[i].P * 60;
			OutPut(Ordinary[i]);
			NumOfServeTable[MinTimeIndex]++;
			i++;
		}
	}

	cout << NumOfServeTable[1];
	for (i = 2; i <= K; i++)
	{
		cout << " " << NumOfServeTable[i];
	}
	return 0;
}