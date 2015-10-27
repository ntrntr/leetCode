#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef struct  Interval{
public:
	long long int start;
	long long int end;
	Interval() : start(0), end(0) {}
	Interval(long long int s,long long int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		const int n = intervals.size();
		//if (n < 500)
		//{

			vector<Interval>::iterator it = intervals.begin();
			while (it != intervals.end())
			{
				if (newInterval.end < it->start)
				{
					intervals.insert(it, newInterval);
					cout<<newInterval.end<<endl;
					return intervals;
				}
				else if (it->end < newInterval.start)
				{
					++it;
					continue;
				}
				else
				{
					long long int tmp = newInterval.end - newInterval.start + 1 + it->end - it->start + 1;
					newInterval.start = min(newInterval.start, it->start);
					newInterval.end = max(newInterval.end, it->end);
					newInterval.end += tmp - (newInterval.end - newInterval.start + 1);
					it = intervals.erase(it);
				}

			}
			intervals.insert(intervals.end(), newInterval);
			cout<<newInterval.end<<endl;
			return intervals;
	}
};

int main()
{
	int n;
	int a,b;
	cin>>n;
	vector<Interval> intervals;
	Solution s;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		s.insert(intervals, Interval(a, a + b - 1));

	}
	return 0;
}