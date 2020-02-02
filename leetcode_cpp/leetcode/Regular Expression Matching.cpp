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
	bool isMatch(string s, string p) {
		char* a = new char[s.length() + 1];
		char* b = new char[p.length() + 1];
		char* tmpa = a;
		char* tmpb = b;
		
		strcpy(a, s.c_str());
		strcpy(b, p.c_str());
		bool res = isMatch2(a, b);
		delete []tmpa;
		delete []tmpb; 
		return res;
	}
	bool regular(char * a, char * b)
	{
		if (*b == '\0')
		{
			return *a == '\0';
		}

		//next char is not *
		if (*(b + 1) != '*')
		{
			if ( *b == *a || (*b == '.' && *a != '\0'))
			{
				return regular(a + 1, b + 1);
			}
			else
				return false;
		}
		//next char is *
		else
		{
			while ( *b = *a || (*b == '.' && *a != '\0'))
			{
				if (regular(a, b + 2))
				{
					return true;
				}
				++a;
			}
			return regular(a, b + 2);
		}
	}
	bool myFuc(char* a, char* b)
	{
		
		if (*b == '\0')
		{
			return *a == '\0';
		}
		if (*a == '\0')
		{
			return *b == '\0';
		}
		if (*a == *b)
		{
			return myFuc(a + 1, b + 1);
		}
		if (*b == '.')
		{
			return myFuc(a + 1, b + 1);
		}
		if (*b == '*')
		{
			return myFuc(a, b + 1) || myFuc(a + 1, b + 1) || myFuc(a + 1, b);
		}
		return false;

	}
	bool isMatch2(const char *s, const char *p) {
		if (*p == '*') {
			while (*p == '*') ++p; //skip continuous '*'
			if (*p == '\0') return true;
			while (*s != '\0' && !isMatch(s, p)) ++s;
			return *s != '\0';
		}
		else if (*p == '\0' || *s == '\0') return *p == *s;
		else if (*p == *s || *p == '?') return isMatch(++s, ++p);
		else return false;
	}
};
int main()
{
	Solution s;
	cout<<s.isMatch("abcd","d*")<<endl;
	return 0;
}