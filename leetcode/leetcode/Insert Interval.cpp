#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef struct  Interval{
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		const int n = intervals.size();
		if (n < 500)
		{
			vector<Interval>::iterator it = intervals.begin();
			while (it != intervals.end())
			{
				if (newInterval.end < it->start)
				{
					intervals.insert(it, newInterval);
					return intervals;
				}
				else if (it->end < newInterval.start)
				{
					++it;
					continue;
				}
				else
				{
					newInterval.start = min(newInterval.start, it->start);
					newInterval.end = max(newInterval.end, it->end);
					it = intervals.erase(it);
				}

			}
			intervals.insert(intervals.end(), newInterval);

			return intervals;

		}
		else
		{
			vector<Interval> res;
			if (intervals.size() == 0)
			{
				res.push_back(newInterval);
				return res;
			}
			for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end();++it)
			{

				if (newInterval.end < it->start)
				{
					res.push_back(newInterval);
					while (it!= intervals.end())
					{
						res.push_back(Interval(it->start, it->end));
						++it;

					}
					break;
				}
				else if (it->end < newInterval.start)
				{
					res.push_back(Interval(it->start, it->end));
					if (it == intervals.end() - 1)
					{
						res.push_back(newInterval);
						break;
					}
				}
				else if (it->start <= newInterval.end)
				{
					newInterval.start = min(it->start, newInterval.start);
					newInterval.end = max(it->end, newInterval.end);
					if (it == intervals.end() - 1)
					{
						res.push_back(newInterval);
						break;
					}
				}


			}

			return res;
		}
		
    }
};
int main()
{
	Solution s;
	int a[] = {1};
	int b[] = {5};
	vector<Interval> myf;
	for (int i = 0; i < 1; ++i)
	{
		myf.push_back(Interval(a[i],b[i]));
	}
	vector<Interval> res = s.insert(myf,Interval(6,8));
	for (auto i:res)
	{
		cout<<i.start<<" "<<i.end<<endl;
	}
	return 0;
}