#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring1(string s, vector<string>& words) {
		int n = words.size();
		int wordLen = words[0].size();
		int m = s.size();
		vector<int> res;
		unordered_map<string, int> myMap;
		for (auto i:words)
		{
			++myMap[i];
		}
		for (int i  = 0; i <= (m - n * wordLen); ++i)
		{
			unordered_map<string, int> tmp(myMap);
			for (int j = 0; j < n; ++j)
			{
				auto pos = tmp.find(s.substr(i + j * wordLen, wordLen));
				if (pos == tmp.end() || pos->second == 0)
				{
					break;
				}
				if (--pos->second == 0)
				{
					tmp.erase(pos);
				}
			}
			if (tmp.size() == 0)
			{
				res.push_back(i);
			}
		}
		return res;
	}

	vector<int> findSubstring(string s, vector<string>& dict) {
		size_t wordLength = dict.front().length();
		size_t catLength = wordLength * dict.size();
		vector<int> result;
		if (s.length() < catLength) return result;
		unordered_map<string, int> wordCount;
		for (auto const& word : dict) ++wordCount[word];
		for (auto i = begin(s); i <= prev(end(s), catLength); ++i) {
			unordered_map<string, int> unused(wordCount);
			for (auto j = i; j != next(i, catLength); j += wordLength) {
				auto pos = unused.find(string(j, next(j, wordLength)));
				if (pos == unused.end() || pos->second == 0) break;
				if (--pos->second == 0) unused.erase(pos);
			}
			if (unused.size() == 0) result.push_back(distance(begin(s), i));
		}
		return result;
	}
};

int main()
{
	Solution s;
	string tmp[] = { "foo", "bar" };
	vector<string> words(tmp, tmp + 2);
	vector<int> res = s.findSubstring("barfoothefoobarman", words);
	for (auto i:res)
	{
		cout<<i<<" ";
	}
	return 0;
}