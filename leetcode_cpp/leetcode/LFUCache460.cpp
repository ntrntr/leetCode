

#include <unordered_map>
#include <map>
#include <iostream>

class ListNode2
{
public:

	ListNode2()
	{
		key = INT_MIN;
		value = -1;
		prev = nullptr;
		next = nullptr;
		level = 0;
	}


	ListNode2(int key, int value, ListNode2* prev = nullptr, ListNode2* next = nullptr, int level = 1)
		: key(key),
		  value(value),
		  prev(prev),
		  next(next),
		  level(level)
	{
	}

	int key;
	int value;
	ListNode2* prev;
	ListNode2* next;
	int level;
};

class LFUCache {
	

public:
	LFUCache(int capacity) {
		_currentSize = 0;
		_capacity = capacity;
	}

	void RemoveFromCurrentLevel(int level, ListNode2* node)
	{
		ListNode2* helperNode = _map[level];
		if (node->next == nullptr)
		{
			helperNode->prev = node->prev;
			node->prev->next = nullptr;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}

	ListNode2* CreateHelper(int level)
	{
		ListNode2* helper = new ListNode2();
		helper->level = level;
		helper->next = nullptr;
		helper->prev = helper;
		return helper;
	}

	void InsertInToLevel(int level, ListNode2* node)
	{
		node->level = level;
		if (_map.find(level) == _map.end())
		{

			_map[level] = CreateHelper(level);
		}
		ListNode2* helper = _map[level];
		ListNode2* lastNode = helper->prev;
		lastNode->next = node;
		node->prev = lastNode;
		node->next = nullptr;
		helper->prev = node;
	}

	void LevelUp(ListNode2* node)
	{
		const int level = node->level;
		RemoveFromCurrentLevel(level, node);
		InsertInToLevel(level + 1, node);
	}

	int get(int key) {
		if (_keyValueMap.find(key) != _keyValueMap.end())
		{
			ListNode2* node = _keyValueMap[key];
			LevelUp(node);
			//Print();
			return _keyValueMap[key]->value;
		}
		//Print();
		return -1;
	}

	ListNode2* GetRemoveNode()
	{
		ListNode2* ret = nullptr;
		for (const auto key_value_map : _map)
		{
			const auto node = key_value_map.second;
			if (node->prev == node)
			{
				continue;
			}
			ret = node->next;
			break;
		}
		return ret;
	}

	void put(int key, int value) {
		if (_capacity == 0)
		{
			return;
		}

		if (_keyValueMap.find(key) != _keyValueMap.end())
		{
			ListNode2* node = _keyValueMap[key];
			node->value = value;
			LevelUp(node);
			return;
		}

		ListNode2* node = CreateNode(key, value, 1);
		if (_currentSize < _capacity)
		{
			_keyValueMap[key] = node;
			InsertInToLevel(1, node);
			_currentSize++;
		}
		else
		{
			ListNode2* removeNode = GetRemoveNode();
			_keyValueMap.erase(removeNode->key);
			RemoveFromCurrentLevel(removeNode->level, removeNode);
			delete removeNode;
			removeNode = nullptr;
			InsertInToLevel(1, node);
			_keyValueMap[key] = node;
		}
		//Print();
	}

	inline ListNode2* CreateNode(int key, int value, int level)
	{
		ListNode2* ret = new ListNode2(key, value, nullptr, nullptr, level);
		return ret;
	}

	void Print()
	{
		return;
		std::cout << "_map:" << std::endl;

		for (const auto key_value_map : _map)
		{
			const auto node = key_value_map.second;
			if (node->prev == node)
			{
				continue;
			}
			auto cur = node->next;
			std::cout << "level:" << node->level << std::endl;
			while (cur != nullptr)
			{
				std::cout << "key:" << cur->key << ", value:" << cur->value << "\t";
				cur = cur->next;

			}
			std::cout << std::endl;
		}
		std::cout << "_keyValueMap:" << std::endl;

		for (auto key_value_map : _keyValueMap)
		{
			std::cout << "key:" << key_value_map.first << "value:" << key_value_map.second->value << "\t";
		}

		std::cout << std::endl << "------" << std::endl;


	}

private:
	int _capacity;
	int _currentSize;
	std::map<int, ListNode2*> _map;
	std::unordered_map<int, ListNode2*> _keyValueMap;
};


void Test1()
{
	LFUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	_ASSERTE(cache.get(1) == 1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	_ASSERTE(cache.get(2) == -1);       // returns -1 (not found)
	_ASSERTE(cache.get(3) == 3);       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	_ASSERTE(cache.get(1) == -1);       // returns -1 (not found)
	_ASSERTE(cache.get(3) == 3);       // returns 3
	_ASSERTE(cache.get(4) == 4);       // returns 4
}

void Test2()
{
	//["LFUCache", "put",	"put",	"get", "put",	"get",	 "get",	 "put",	 "get",		"get",	"get"]
	//[[2],			[1, 1], [2, 2], [1],	[3, 3], [2],	  [3],	[4, 4],		[1],	[3],	 [4]]
	LFUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	_ASSERTE(cache.get(1) == 1);
	cache.put(3, 3);
	_ASSERTE(cache.get(2) == -1);
	_ASSERTE(cache.get(3) == 3);
	cache.put(4, 4);
	_ASSERTE(cache.get(1) == -1);
	_ASSERTE(cache.get(3) == 3);
	_ASSERTE(cache.get(4) == 4);
}

void Test3()
{
	//["LFUCache",	"put",		"put",		"put",		"put",		"get"]
	//[[2],			[3, 1],		[2, 1],		 [2, 2],	[4, 4],		[2]]
	LFUCache cache(2);
	cache.put(3, 1);
	cache.put(2, 1);
	cache.put(2, 2);
	cache.put(4, 4);
	_ASSERTE(cache.get(2) == 2);
}

int main(int argc, char* argv[])
{
	//Test1();
	Test3();

	system("pause");
	return 0;
}
