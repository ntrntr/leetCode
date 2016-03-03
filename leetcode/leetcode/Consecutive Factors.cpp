//#include <vector>
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <stack>
//#include <unordered_map>
//#include <limits.h>
//#include <math.h>
//using namespace std;
//void getRes(int n)
//{
//	int min_start = n;
//	int max = 1;
//	int sqrtn = sqrt(n);
//	int i = 2;
//	for (; i < sqrtn; ++i)
//	{
//		if (n % i == 0)
//		{
//			int len = 1;
//			int tmpn = n/i;
//			while (tmpn%(++i) == 0)
//			{
//				++len;
//				tmpn /= i;
//			}
//			if (len > max)
//			{
//				max = len;
//				i = i - len;
//				min_start = i;
//			}
//			else if (len == max && i < min_start)
//			{
//				i = i - len;
//				min_start = i;
//			}
//		}
//	}
//	cout << max << endl;
//	for (int i = 0; i < max; ++i)
//	{
//		if (i == max - 1)
//		{
//			cout << min_start << endl;
//		}
//		else
//			cout << min_start++ << "*";
//	}
//	
//}
//int main()
//{
//	int n;
//	cin >> n;
//	getRes(n);
//	return 0;
//}

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	while (cin >> N)
	{
		int i, j, time;
		int start, imax = 1;
		int n = (int)sqrt(N) + 2;
		bool flag = false;
		for (i = 2; i <= n; ++i)
		{
			long long res = 1;
			j = i;
			for (time = 1; time <= 31; ++time)
			{
				res = res * j;
				j++;
				if (res > N || N % res != 0)
				{
					break;
				}
				if (N % res == 0)
				{
					if (!flag || time > imax)
					{
						imax = time;
						start = i;
						flag = true;
					}
				}
			}
		}
		if (!flag)
		{
			cout << "1" << endl << N;
			return 0;
		}
		cout << imax << endl;

		for (int i = 0; i < imax; ++i)
		{
			if (i == 0)
			{
				cout << start;
			}
			else
				cout << "*" << start + i;
		}

	}
	return 0;
}