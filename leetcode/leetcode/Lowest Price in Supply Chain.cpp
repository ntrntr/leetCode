#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}
struct people
{
	int id;
	int increment;
	int type;
	int father;
	int confirm;
	people() :increment(0), type(0),father(-1),confirm(0){};
};
void mydp(int i, vector<people>& f)
{
	if (f[i].confirm == 0)
	{
		mydp(f[i].father, f);
		f[i].increment = f[f[i].father].increment + 1;
		f[i].confirm = 1;
	}
}
//void myprintf(vector<people>& f)
//{
//	for (auto i:f)
//	{
//		cout << "id = " << i.id << ", increment = " << i.increment << ", type = " << i.type << ", father = " << i.father << ", confirm = " << i.confirm << endl;
//	}
//}
int main()
{
	Solution s;
	int N;
	double P, r;
	cin >> N >> P >> r;
	vector<people> f(N);
	for (int i = 0; i < N; ++i)
	{
		f[i].id = i;
	}
	f[0].confirm = 1;
	int tmp;
	int tmp1;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			f[i].type = 1;
		}
		else
		{
			for (int j = 0; j < tmp; ++j)
			{
				cin >> tmp1;
				f[tmp1].increment = f[i].increment + 1;
				f[tmp1].father = i;
				f[tmp1].confirm = f[i].confirm;
				
				
			}
		}
		//cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		//cout << "father = " << i << endl;
		//myprintf(f);
		//cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	}
	
	for (int i = 1; i < N; ++i)
	{
		if (f[i].confirm == 0)
		{
			mydp(i, f);
		}
	}
	sort(f.begin(), f.end(), [](people& p, people& q){
		if (p.type != q.type )
		{
			return p.type > q.type;
		}
		else
		{
			return p.increment < q.increment;
		}
	});
	int num = 1;
	for (int i = 1; i < N; ++i)
	{
		if (f[0].increment == f[i].increment)
		{
			++num;
		}
		else
			break;
	}
	printf("%.4f %d\n", P * pow((1 + r / 100), f[0].increment), num);
	return 0;
}
