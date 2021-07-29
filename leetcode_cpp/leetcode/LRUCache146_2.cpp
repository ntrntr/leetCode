class Node
{
public:
	Node(int _key, int _val) :key(_key), val(_val), prev(nullptr), next(nullptr)
	{

	}
	int key;
	int val;
	Node* prev;
	Node* next;
};

class LRUCache {
public:
	unordered_map<int, Node*> _map;
	Node* link_list;
	int _capacity;
	LRUCache(int capacity) {
		_capacity = capacity;
		link_list = new Node(-1, -1);
	}

	int get(int key) {
		if (_map.find(key) != _map.end())
		{
			_move_to_back(_map[key]);
			return _map[key]->val;
		}
		return -1;
	}

	void put(int key, int value) {
		auto size = _map.size();
		if (_map.find(key) != _map.end())
		{
			_move_to_back(_map[key]);
			_map[key]->val = value;
		}
		else
		{
			if (size == _capacity)
			{
				auto* del_node = link_list->prev;
				_map.erase(_map.find(del_node->key));
				_del_node(link_list->prev);
			}
			auto* new_node = new Node(key, value);
			_map[key] = new_node;
			_add_node(new_node);
		}
	}

	void _del_node(Node* p)
	{
		auto* prev_node = p->prev;
		prev_node->next = p->next;
		if (p->next != nullptr)
		{
			auto* next_node = p->next;
			next_node->prev = prev_node;
		}
		if (link_list->prev == p)
		{
			link_list->prev = prev_node;
		}
	}

	void _add_node(Node* p)
	{
		if (link_list->next != nullptr)
		{
			auto* next_node = link_list->next;
			next_node->prev = p;
			p->next = next_node;
			link_list->next = p;
			p->prev = link_list;
		}
		else
		{
			link_list->next = p;
			p->prev = link_list;
			link_list->prev = p;
		}
	}

	void _move_to_back(Node* p)
	{
		_del_node(p);
		_add_node(p);
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */