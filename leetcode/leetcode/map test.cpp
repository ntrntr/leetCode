#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>

#include<map>  
#include<string>  
#include<iostream>  
using namespace std;
typedef pair<string, int> PAIR;  

ostream& operator<<(ostream& out, const PAIR& p) {  
	return out << p.first << "\t" << p.second;  
}  
struct CmpByKeyLength {  
	bool operator()(const string& k1, const string& k2) {  
		return k1.length() < k2.length();  
	}  
};  

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  
	return lhs.second < rhs.second;  
}  

struct CmpByValue {  
	bool operator()(const PAIR& lhs, const PAIR& rhs) {  
		return lhs.second < rhs.second;  
	}  
};  
int main()
{
	map<string, int > name_score_map;  
	name_score_map["LiMin"] = 90;   
	name_score_map["ZiLinMi"] = 79;   
	name_score_map["BoB"] = 92;   
	name_score_map.insert(make_pair("Bing",99));  
	name_score_map.insert(make_pair("Albert",86));  
	for (map<string, int>::iterator iter = name_score_map.begin();  
		iter != name_score_map.end();  
		++iter) {  
			cout << *iter << endl;  
	}  
	//把map中元素转存到vector中   
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());  
	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());  
	// sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);  
	for (int i = 0; i != name_score_vec.size(); ++i) {  
		cout << name_score_vec[i] << endl;  
	}   
	return 0;
}