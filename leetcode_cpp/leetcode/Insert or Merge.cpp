#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> f(n), g(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> f[i];
//	}
//	vector<int> tmp(f);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> g[i];
//	}
//	int pos = n - 1;
//	do
//	{
//		int i;
//		for (int i = 1; i < n; ++i)
//		{
//			sort(tmp.begin(), tmp.begin() + i);
//			if (tmp == g)
//			{
//				cout << "Insertion Sort" << endl;
//				sort(tmp.begin(), tmp.begin() + i + 1);
//				for (int c = 0; c < n; ++c)
//				{
//					if (c == 0)
//					{
//						cout << tmp[c];
//					}
//					else
//						cout << " " << tmp[c];
//				}
//				return 0;
//			}
//		}
//		
//
//	} while (0);
//	cout << "Merge Sort" << endl;
//	int step = 1;
//	int count = 0;
//	
//	while (step < n)
//	{
//		int flag = 0;
//		if (f == g)
//		{
//			flag = true;
//		}
//		step = step * 2;
//		int ib = 0;
//		while (ib + step <= n)
//		{
//			sort(f.begin() + ib, f.begin() + ib + step);
//			ib = ib + step;
//		}
//		if (ib != n)
//		{
//			sort(f.begin() + ib, f.end());
//		}
//		
//		if (flag)
//		{
//			for (int c = 0; c < n; ++c)
//			{
//				if (c == 0)
//				{
//					cout << f[c];
//				}
//				else
//					cout << " " << f[c];
//			}
//			return 0;
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> src(n), dest(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> src[i];
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> dest[i];
//	}
//	vector<int> tmp(src);
//	bool isInsertSort = false;
//	for (int i = 1; i < n; ++i)
//	{
//		isInsertSort = 
//	}
//}

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXN 105  
using namespace std; 
int original[MAXN],temp[MAXN],ans[MAXN];
int n;  
bool isEqual(int a[],int b[])
{ 
	for(int i=0;i<n;i++)
	{ 
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}  
void output(int a[])
{ 
	printf("%d",a[0]);
	for(int i=1;i<n;i++)
		printf(" %d",a[i]);
	printf("\n"); 
}  
bool isInsert(){
	int flag=0; 
	for(int i=2;i<=n;i++)
	{ 
		if(flag&&!isEqual(ans,temp))
		{ 
			printf("Insertion Sort\n"); 
			output(ans); 
			return true; 
		} 
		sort(ans,ans+i);
		if(isEqual(ans,temp))
			flag=1; 
	} 
	return false; 
}  
bool isMerge()
{ 
	int flag=0; 
	int i=0,j=0;
	for(i=2;i<=n;i=i*2)
	{ 
		for(j=0;j+i<=n;j=j+i)
		{
			if(isEqual(original,temp))
				flag=1; 
			sort(original+j,original+j+i);
		} 
		sort(original+j,original+n);
//remaining sublist which has less than i elements 

		if (isEqual(original, temp))
			flag = 1;
		if (flag&&!isEqual(original, temp))
		{ 
			printf("Merge Sort\n"); 
			output(original); 
			return true; 
		} 
	} 
	return false;
}  
int main(int argc, char *argv[])
{ 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{ 
		scanf("%d", &original[i]);
		ans[i] = original[i];
	} 
	for (int i = 0; i < n; i++) 
		scanf("%d", &temp[i]); 
	if (!isInsert()) 
		isMerge(); 
	return 0; 
}