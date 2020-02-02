#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		const int n = str.size();
		long long int res = 0;
		int i = 0;
		int flag = 0;
		while (str[i] == ' ' && i < n)
		{
			i++;
		}
		if (str[i] == '+')
		{
			i++;
		}
		else if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		for (; i < n; ++i)
		{
			if (str[i]<'0' || str[i]>'9')
			break;

			if (res > INT_MAX / 10 || (res == INT_MAX / 10  && str[i] - '0' > INT_MAX % 10))
			{
				return flag == 1 ? INT_MIN : INT_MAX; 
			}
			else
			{
				res = res * 10 + str[i] - '0';
			}
		}
		return res;
		/*int flag = 0;
		int first = 0;
		int dataInit = 0;
		for(int i = 0; i < n; ++i)
		{
			if(first >= 2)
				return 0;
			if(str[i] == ' ' && !dataInit)
				continue;
			else if(str[i] == ' ' && dataInit)
			{
				if (flag)
					res = -res;

				if(res>= INT_MIN && res <=INT_MAX)
				{
					return res;
				}
				else if(res < INT_MIN)
				{
					return INT_MIN;
				}
				else
					return INT_MAX;
			}
			if(str[i] == '+')
			{
				flag = 0;
				first++;
				dataInit = 1;
			}
			else if(str[i] == '-')
			{
				flag = 1;
				first++;
				dataInit = 1;
			}
			else if(str[i] >= '0' && str[i]<= '9')
			{
				res = res * 10 + str[i] - '0';
				dataInit = 1;
				if (flag == 0 && res > INT_MAX)
				{
					return INT_MAX;
				}
				else if (flag == 1 && (-res) < INT_MIN)
				{
					return INT_MIN;
				}
			}
			else
			{
				if (flag)
					res = -res;

				if(res>= INT_MIN && res <=INT_MAX)
				{
					return res;
				}
				else if(res < INT_MIN)
				{
					return INT_MIN;
				}
				else
					return INT_MAX;
			}
		}
		if (flag)
			res = -res;

		if(res>= INT_MIN && res <=INT_MAX)
		{
			return res;
		}
		else if(res < INT_MIN)
		{
			return INT_MIN;
		}
		else
			return INT_MAX;*/
	}
};

int main()
{
	Solution s;
	cout<<s.myAtoi("+-2")<<endl;
	return 0;
}