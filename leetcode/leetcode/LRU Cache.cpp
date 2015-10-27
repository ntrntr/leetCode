#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache{
public:
	struct node
	{
		int key;
		int val;
		node(int k, int v):key(k),val(v){}
	};
	unordered_map<int, list<node>::iterator > map;
	list<node> mylist;
	int size;
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if(map.find(key) == map.end())
			return -1;
		else
		{
			mylist.splice(mylist.begin(), mylist, map[key]);
			map[key] = mylist.begin();
			return map[key]->val;
		}
	}

	void set(int key, int value) {
		if(map.find(key) != map.end())
		{
			mylist.splice(mylist.begin(), mylist, map[key]);
			mylist.front().val = value;
			map[key] = mylist.begin();
		}
		else
		{
			if(mylist.size() >= size)
			{
				map.erase(mylist.back().key);
				mylist.pop_back();
				mylist.push_front(node(key, value));
				map[key] = mylist.begin();
			}
			else
			{
				mylist.push_front(node(key, value));
				map[key] = mylist.begin();
			}
		}
		return;
	}
};
int main()
{
	return 0;
}