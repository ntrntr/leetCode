#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <set>
using namespace std;
struct book
{
	string id;
	string title;
	string author;
	set<string> keyword;
	string publisher;
	string year;
	book(){};
	book(string _id, string& _title, string& _author, string& _keyword, string& _publisher, string& _year) :id(_id), title(_title), author(_author), publisher(_publisher), year(_year)
	{
		string tmp = "";
		for (int i = 0; i < _keyword.size(); ++i)
		{
			if (_keyword[i] == ' ')
			{
				keyword.insert(tmp);
				tmp.clear();
			}
			else
			{
				tmp += _keyword[i];
			}
		}
		keyword.insert(tmp);
	};
};
int main()
{
	int n,m;
	cin >> n;
	getchar();
	string id;
	string title;
	string author;
	string keyword;
	string publisher;
	string year;
	vector<book> data;
	for (int i = 0; i < n; ++i)
	{

		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keyword);
		getline(cin, publisher);
		getline(cin, year);
		data.push_back(book(id, title, author, keyword, publisher, year));
	}
	sort(data.begin(), data.end(), [](book& a, book& b)	{	return a.id < b.id;	});
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int c;
		string str;
		int flag = false;
		scanf("%d: ", &c);
		getline(cin, str);
		cout << c << ": " << str << endl;
		if (c == 1)
		{
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].title == str)
				{
					cout << data[j].id << endl;
					flag = true;
				}
			}

		}
		if (c == 2)
		{
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].author == str)
				{
					cout << data[j].id << endl;
					flag = true;
				}
			}

		}
		if (c == 3)
		{
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].keyword.find(str) != data[j].keyword.end())
				{
					cout << data[j].id << endl;
					flag = true;
				}
			}

		}
		if (c == 4)
		{
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].publisher == str)
				{
					cout << data[j].id << endl;
					flag = true;
				}
			}

		}
		if (c == 5)
		{
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].year == str)
				{
					cout << data[j].id << endl;
					flag = true;
				}
			}

		}
		if (!flag)
		{
			cout << "Not Found" << endl;
		}
	}
	return 0;
}