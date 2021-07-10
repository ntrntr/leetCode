class Solution {
public:
    int getTime(string& s)
    {
        return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3, 2));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> res;
        for(auto& s:timePoints)
        {
            res.push_back(getTime(s));
        }
        sort(res.begin(), res.end());
        auto before = -(24 * 60 - res.back());
        int ret = 24 * 60;
        for(auto t:res)
        {
            ret = min(ret, t - before);
            before = t;
        }
        return ret;
    }
};