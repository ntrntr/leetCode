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
	string intToRoman(int num) {

		string res;
		const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string symbom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"} ;
		for (int i = 0; num > 0; ++i)
		{
			int count = num / radix[i];
			num = num % radix[i];
			for (int j = 0; j < count; ++j)
			{
				res += symbom[i];
			}
		}
		return res;
		//myMap.insert(make_pair(1000, 'M'));
		//myMap.insert(make_pair(500, 'D'));
		//myMap.insert(make_pair(100, 'C'));
		//myMap.insert(make_pair(50, 'L'));
		//myMap.insert(make_pair(10, 'X'));
		//myMap.insert(make_pair(5, 'V'));
		//myMap.insert(make_pair(1, 'I'));
		//string res;
		//int tmp[7] = {1000, 500, 100, 50, 10, 5, 1};
		//int k = 0;
		////for (int i = 0; i < 7; ++i)
		////{
		////	k = num / tmp[i];
		////	if (k == 0)
		////	{
		////		if (i >= 1 && i != 3 &&  num >tmp[i-1] - tmp[i] )
		////		{

		////		}
		////	}
		////	else
		////	{

		////	}
		////}
		//
		//if (num >= 1000)
		//{
		//	k = num / 1000;
		//	string s(k, myMap[1000]);
		//	res += s;
		//	num = num % 1000;
		//}
		//if (num >= 900)
		//{
		//	res += "CM";
		//	num = num - 900;
		//}
		//if (num >= 500)
		//{
		//	k = num / 500;
		//	string s(k, myMap[500]);
		//	res += s;
		//	num = num % 500;
		//}
		//if (num >= 400)
		//{
		//	res += "CD";
		//	num = num - 400;
		//}
		//if (num >= 100)
		//{
		//	k = num / 100;
		//	string s(k, myMap[100]);
		//	res += s;
		//	num = num % 100;
		//}
		//if (num >= 90)
		//{
		//	res += "XC";
		//	num = num - 90;
		//}
		//if (num >= 50)
		//{
		//	k = num / 50;
		//	string s(k, myMap[50]);
		//	res += s;
		//	num = num % 50;
		//}
		//if (num >= 40)
		//{
		//	res += "XL";
		//	num = num - 40;
		//}
		//if (num >= 10)
		//{
		//	k = num / 10;
		//	string s(k, myMap[10]);
		//	res += s;
		//	num = num % 10;
		//}
		//if (num >= 9)
		//{
		//	res += "IX";
		//	num = num - 9;
		//}
		//if (num >= 5)
		//{
		//	k = num / 5;
		//	string s(k, myMap[5]);
		//	res += s;
		//	num = num % 5;
		//}
		//if (num >= 4)
		//{
		//	res += "IV";
		//	num = num - 4;
		//}
		//if (num >= 1)
		//{
		//	k = num / 1;
		//	string s(k, myMap[1]);
		//	res += s;
		//	num = 0;
		//}
		//return res;
	}
};
int main()
{
	Solution s;

	for (int i = 1; i < 101; ++i)
	{
		cout<<s.intToRoman(i)<<",";
		//cout<<mytest[i]<<",";
	}
	return 0;
}