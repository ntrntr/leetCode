
#include <cstdlib>
#include <unordered_map>
#include <iostream>



class ListNode2
{
public:

	void Reset()
	{
		key = INT_MIN;
		value = -1;
		prev = nullptr;
		next = nullptr;
	}

	ListNode2()
	{
		Reset();
	}

	ListNode2* Init(int key, int value, ListNode2* prev = nullptr, ListNode2* next = nullptr)
	{
		this->key = key;
		this->value = value;
		this->prev = prev;
		this->next = next;
		return this;
	}


	ListNode2(int key, int value, ListNode2* prev = nullptr, ListNode2* next = nullptr)
		: key(key),
		value(value),
		prev(prev),
		next(next)
	{
	}

	int key;
	int value;
	ListNode2* prev;
	ListNode2* next;
};

class NodePool
{
public:
	NodePool(int initSize)
	{
		for (int i = 0; i < initSize; ++i)
		{
			nodeList.push_back(new ListNode2());
		}
	}

	ListNode2* AccquireNode()
	{
		if (nodeList.size() == 0)
		{
			nodeList.push_back(new ListNode2());
		}
		auto ret = nodeList.back();
		nodeList.pop_back();
		return ret;
	}

	bool ReleaseNode(ListNode2* node)
	{
		node->Reset();
		nodeList.push_back(node);
		return true;
	}
private:
	std::vector<ListNode2*> nodeList;
};

class LRUCache {
public:
	LRUCache(int capacity)
	{
		_nodePool = new NodePool(4);
		_capacity = capacity;
		_currentSize = 0;
		helperNode = _nodePool->AccquireNode()->Init(-1,-1);
		helperNode->prev = helperNode;
	}

	int get(int key) {
		if (_fastMap.find(key) != _fastMap.end())
		{
			ListNode2* node = _fastMap[key];
			UpdateNode(node);
			Print();

			return node->value;
		}
		Print();

		return -1;
	}

	void UpdateNode(ListNode2* node)
	{
		RemoveNode(node);
		AddNode(node);
	}

	void AddNode(ListNode2* node)
	{
		ListNode2* helper = helperNode;
		ListNode2* lastNode = helper->prev;
		lastNode->next = node;
		node->prev = lastNode;
		node->next = nullptr;
		helper->prev = node;
	}

	void RemoveNode(ListNode2* node)
	{
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

	void put(int key, int value) {
		if (_capacity == 0)
		{
			Print();
			return;
		}
		if (_fastMap.find(key) != _fastMap.end())
		{
			ListNode2* node = _fastMap[key];
			node->value = value;
			UpdateNode(node);
			Print();
			return;
		}
		auto node = _nodePool->AccquireNode()->Init(key,value);
		if (_currentSize < _capacity)
		{
			AddNode(node);
			_currentSize++;
			_fastMap[key] = node;
			Print();

		}
		else
		{
			auto nodeToRemove = helperNode->next;
			RemoveNode(nodeToRemove);
			_fastMap.erase(nodeToRemove->key);
			delete nodeToRemove;
			AddNode(node);
			_fastMap[node->key] = node;
			Print();
		}
		Print();

	}

	void Print()
	{
		return;
		for (const auto key_value_map : _fastMap)
		{
			std::cout << "key:" << key_value_map.first<< ", value:" << key_value_map.second->value << "\t";
			std::cout << std::endl;
		}

		std::cout << std::endl << "------" << std::endl;


	}
private:
	int _currentSize;
	int _capacity;
	ListNode2 * helperNode;
	std::unordered_map<int, ListNode2*> _fastMap;
	NodePool* _nodePool;
};

int main(int argc, char* argv[])
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	_ASSERTE(cache.get(1) == 1);
	cache.put(3, 3);
	_ASSERTE(cache.get(2) == -1);
	cache.put(4, 4);
	_ASSERTE(cache.get(1) == -1);
	_ASSERTE(cache.get(3) == 3);
	_ASSERTE(cache.get(4) == 4);


	system("pause");
	return 0;
}
