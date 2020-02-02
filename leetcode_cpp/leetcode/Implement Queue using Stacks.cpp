#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <deque>
#include <queue>
using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		data.push_back(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		data.pop_front();
	}

	// Get the front element.
	int peek(void) {
		return data.front();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return data.empty();
	}
	deque<int> data;
};

int main()
{
	return 0;
}