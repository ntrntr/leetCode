#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
struct Point
{
	int x;
	int y;
	Point():x(0), y(0){}
	Point(int a, int b):x(a), y(b){}
};
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int res = 0;
		const int n = points.size();
		if(n <= 2)
		{
			return n;
		}
		unordered_map<long int, int> myHash;
		double tmp;
		for (int i = 0; i < n; ++i)
		{
			myHash.clear();
			int offset = 0;
			for (int j = 0; j < n; ++j)
			{
				if (j == i)
				{
					continue;
				}
				if (points[i].x == points[j].x && points[i].y != points[j].y)
				{
					++myHash[INT_MAX];
					res = max(res, myHash[INT_MAX] + offset);

				}
				else if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					++offset;
					res = max(res, offset);
				}
				else
				{
					long int tmp = (long int)(1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x) * 10000);
					++myHash[tmp];
					res = max(res, myHash[tmp] + offset);
				}
			}
		}
		return res + 1;
	}
};
int main()
{
	 
	Solution s;
	
	Point sss[] = {Point(84,250), Point(0,0), Point(1,0), Point(0,-70), Point(0,-70), Point(1,-1), Point(21,10), Point(42,90), Point(-42,-230)};
	vector<Point> ss(sss, sss + 9);
	cout<<s.maxPoints(ss)<<endl;
	//ss.push_back();
	return 0;
}