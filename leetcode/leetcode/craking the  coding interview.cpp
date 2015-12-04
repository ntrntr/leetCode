#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <sstream>
#include <stack>
using namespace std;
void reverse(char* s)
{
	if (s == NULL)
	{
		return;
	}
	char* begin = s;
	char* end = s;
	while (*(++begin) != '\0')
	{
		end = begin;
	}
	begin = s;
	while (begin != end && (begin) != (end-1))
	{
		swap(*begin++, *end--);
	}
	return;
}
void replacestr(string& s, string repl)
{
	//string res;
	//int begin = 0;
	//string::size_type it = s.find(' ', begin);
	//while (it != string::npos)
	//{
	//	res.append(s.begin() + begin , s.begin() + it);
	//	res.append(repl);
	//	begin = it + 1;
	//	it = s.find(' ', begin);
	//}
	//return res;
	//replace(s.begin(), s.end(), " ", repl);
	string::size_type it = s.find(' ', 0);
	while (it != string::npos)
	{
		s.replace(it, 1, repl);
		it = s.find(' ', 0);
	}
	//s.replace(s.begin(), s.end(), )
}
string myitoa(int num)
{
	stringstream ss;
	ss<<num;
	string res;
	ss>>res;
	return res;
}
string zipString(string& s)
{
	string res;
	int count = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (count == 0)
		{
			res.push_back(s[i]);
			count++;
		}
		else
		{
			if (s[i] != res.back())
			{
				string tmp(myitoa(count));
				
				res.append(tmp.begin(), tmp.end());
				res.push_back(s[i]);
				count = 1;
			}
			else
				count++;
		}
	}
	if (count > 1)
	{
		string tmp(myitoa(count));

		res.append(tmp.begin(), tmp.end());
	}
	return res.size() < s.size()? res:s;
}
void nntansform(vector<vector<int>>& data)
{
	const int n = data.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			swap(data[i][j], data[j][i]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n/2; ++j)
		{
			swap(data[i][j], data[i][n - j - 1]);
		}
	}
}
void clearnm(vector<vector<int>>& data)
{
	const int n = data.size();
	const int m = data.front().size();
	set<int> rows,cols;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (data[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	vector<int> tmp(m, 0);
	for (auto it = rows.begin(); it != rows.end(); ++it)
	{
		data[*it].assign(tmp.begin(), tmp.end());
	}
	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		for (int i = 0; i < n; ++i)
		{
			data[i][*it] = 0;
		}
	}
}
template<typename T>
void myprintf(vector<vector<T>>& data)
{
	for (auto i:data)
	{
		for (auto j:i)
		{
			cout<<j<<" ";

		}
		cout<<endl;
	}
}
bool isSubstring()
{
	return true;
}
bool checkDifferent(string iniString) {
	// write code here
	sort(iniString.begin(), iniString.end());
	for(int i = 0; i < iniString.size()-1; ++i)
	{
		if(iniString[i] == iniString[i + 1])
			return false;
	}
	return true;
}
string strrotate(string& s, int n)
{
	string res(prev(s.end(), n ), s.end());
	res.append(s.begin(), prev(s.end(), n ));
	return res;

}
bool checkReverseEqual(string s1, string s2) {
	// write code here
	if (s1.size() != s2.size())
	{
		return false;
	}
	char c = s1.back();
	string::size_type it = s2.find(c, 0);
	while (it != string::npos)
	{
		if (strrotate(s1, it + 1) == s2)
		{
			return true;
		}
		it = s2.find(c, it + 1);

	}
	return false;
}
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* pHead, int x) {
	// write code here
	/*ListNode* small = new ListNode(-1);
	ListNode* large = new ListNode(-1);
	ListNode* p = small;
	ListNode* q = large;
	int flag1 = 0, flag2 = 0;
	while (pHead != NULL)
	{
		if (pHead->val < x)
		{
			p->next = pHead;
			p = p->next;
			flag1 = 1;
		}
		else
		{
			q->next = pHead;
			q = q->next;
			flag2 = 1;
		}
		pHead = pHead->next;
	}
	q->next = NULL;
	if (flag1 && flag2)
	{
		p->next = large->next;
	}
	else if (flag1 && !flag2)
	{
		
	}
	else if (!flag1 && flag2)
	{
		p->next = large->next;
	}
	else
	{
		return nullptr;
	}
	ListNode* res = small->next;
	delete small;
	delete large;
	return res;*/
	vector<int> smalldata;
	vector<int> largedata;
	ListNode* p = pHead;
	while (p != NULL)
	{
		if (p->val < x)
		{
			smalldata.push_back(p->val);
		}
		else
		{
			largedata.push_back(p->val);
		}
		p = p->next;
	}
	transform(largedata.begin(), largedata.end(), back_inserter(smalldata),[](const int& x){return x;});
	p = pHead;
	int count = 0;
	while (p)
	{
		p->val = smalldata[count++];
		p = p->next;
	}
	return pHead;
	//sort(data.begin(), data.end(), )
}
template<typename T>
void myprintfone(vector<T>& data)
{
	for (auto i:data)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

ListNode* plusAB(ListNode* a, ListNode* b) {
	// write code here
	ListNode dummy =  ListNode(-1);
	ListNode* p = &dummy;
	int jinwei = 0;
	int left,right;
	while (a!= NULL|| b != NULL)
	{
		if (a == NULL)
		{
			left = 0;
		}
		else
		{
			left = a->val;
			a = a->next;
		}
		if (b == NULL)
		{
			right = 0;
		}
		else
		{
			right = b->val;
			b = b->next;
		}
		p->next = new ListNode((left + right + jinwei) % 10);
		jinwei = (left + right + jinwei)/10;
		p = p->next;
	}
	if (jinwei != 0)
	{
		p->next = new ListNode(jinwei);
	}
	return dummy.next;
}
vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
	// write code here
	vector<vector<int>> res;
	stack<int> stk;
	
	return res;
}
int main()
{
	/*vector<vector<int>> f;
	vector<int> tmp;
	for (int i = 0; i < 16; ++i)
	{
		tmp.push_back(i);
		if (tmp.size() == 4)
		{
			f.push_back(tmp);
			tmp.clear();
		}
	}
	f[3][2] = 0;
	f[3][1] = 0;*/
	//myprintf(f);
	
	//clearnm(f);
	//myprintf(f);
	vector<int> f;
	vector<int> g;
	for (int i = 0; i < 10; i++)
	{
		f.push_back(rand() % 10);
		g.push_back(1);
	}
	myprintfone(f);
	transform(f.begin(), f.end(), back_inserter(g), [](const int & x){return x;});
	myprintfone(f);
	myprintfone(g);
	return 0;
}