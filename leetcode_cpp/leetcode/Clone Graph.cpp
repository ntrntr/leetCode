#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<int , UndirectedGraphNode *> myMap;
		if(node == nullptr)
			return nullptr;

		dfs(node, myMap);
		return myMap[node->label];
	}
	void dfs(UndirectedGraphNode* node, unordered_map<int , UndirectedGraphNode *>& myMap)
	{
		if(myMap.find(node->label) == myMap.end())
		{
			UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label); 
			myMap[node->label] = tmp;
		}
		for(auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
		{
			if((*it)->label == node->label)
			{
				return;
			}
	
			if(myMap.find((*it)->label) == myMap.end())
			{
				UndirectedGraphNode* tmp = new UndirectedGraphNode((*it)->label); 
				myMap[(*it)->label] = tmp;
				//myMap[node->label].neighbors.push_back(tmp);
				myMap[node->label]->neighbors.push_back(tmp);
				dfs(*it, myMap);
			}
			else if(myMap.find((*it)->label) != myMap.end())
			{
				//myMap[node->label].neighbors.push_back(myMap[(*it)->label]);
				myMap[node->label]->neighbors.push_back(myMap[(*it)->label]);
				dfs(*it, myMap);
			}
		}
	}
};
int main()
{
	Solution s;
	return 0;
}