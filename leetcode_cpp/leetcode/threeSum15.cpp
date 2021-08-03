class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> res;
		map<int, int> _map;
		for (int n : num)
		{
			if (_map.find(n) == _map.end()) {
				_map[n] = 1;
			}
			else
			{
				_map[n] = _map[n] + 1;
			}
		}
		for (auto it = _map.begin(); it != _map.end(); ++it)
		{
			if (it->second >= 2)
			{
				auto target_value = 0 - it->first * 2;
				if (target_value >= it->first && _map.find(target_value) != _map.end())
				{
					if (target_value == it->first)
					{
						if (it->second >= 3)
						{
							res.push_back(vector<int>({ it->first, it->first, target_value }));
						}
					}
					else
					{
						res.push_back(vector<int>({ it->first, it->first, target_value }));
					}
				}
			}
			if (it != _map.end() && next(it) != _map.end())
			{
				for (auto jt = next(it); jt != _map.end(); ++jt)
				{
					int a = it->first;
					int b = jt->first;
					int c = 0 - a - b;
					if (a <= b && b <= c && _map.find(c) != _map.end())
					{
						if (b == c && _map[b] >= 2)
						{
							res.push_back(vector<int>({ a,b,c }));
						}
						else if (b < c)
						{
							res.push_back(vector<int>({ a,b,c }));
						}
					}
				}
			}

		}

		return res;

	}
};