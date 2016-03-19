#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <stdio.h>
using namespace std;
bool isswap(char* pszStr, int b, int e)
{
	for (int i = b; i < e; ++i)
	{
		if (pszStr[i] == pszStr[e])
		{
			return false;
		}
	}
	return true;
}
void perm(char* pszStr, int k, int m)
{
	if (k == m)
	{
		static int s_i = 1;
		cout << s_i++ << ": " << pszStr << endl;
	}
	else
	{
		for (int i = k; i <= m; ++i)
		{
			if (isswap(pszStr, k,i))
			{
				swap(*(pszStr + k), *(pszStr + i));
				perm(pszStr, k + 1, m);
				swap(*(pszStr + k), *(pszStr + i));
			}
			
		}
	}
}
void foo(char* str)
{
	perm(str, 0, strlen(str) - 1);
}
char* findmax(char* p, char* q)
{
	char* p1 = p;
	char* q1 = q;
	while (*q1 <= *p1)
	{
		q1--;
	}
	return q1;
}
void perm2(char* s)
{
	char* pend = s + strlen(s) - 1;
	char* p = pend;
	char* q = new char;
	char* pmax = new char;
	while (p != s)
	{
		q = p;
		p--;
		if (*p < *q)
		{
			pmax = findmax(p, pend);
			swap(*p, *pmax);
			reverse(q, pend);
			cout << s << endl;
			p = pend;
		}
		if (s == p)
		{
			break;
		}
	}
}
int main()
{
	char str[50];
	cin >> str;
	//foo(str);
	sort(str, str + strlen(str));
	perm2(str);
	return 0;
}