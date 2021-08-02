class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> res;
		map<int, int> _map;
		for (int n : nums)
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
					if (target_value == it->first and it->second >= 3)
					{
						res.push_back(vector<int>({ it->first, it->first, target_value }));
					}
				}
			}
			if (it != _map.end())
			{
				for (auto jt = it + 1; jt != _map.end(); ++jt)
				{

				}
			}

		}

		return res;

	}
};