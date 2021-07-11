class Solution {
public:
    bool canPut(const vector<int>& flowerbed, int index, int size)
    {
        if(flowerbed[index] == 1)
        {
            return false;
        }
        if (index -1 >= 0 && flowerbed[index-1] == 1)
        {
            return false;
        }
        if (index + 1 < size && flowerbed[index+1] == 1)
        {
            return false;
        }
        return true;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto flower_size = flowerbed.size();
        for (auto i=0; i < flower_size;)
        {
            if (canPut(flowerbed, i, flower_size))
            {
                n = n - 1;
                flowerbed[i] = 1;
                i += 1;
            }
            i = i + 1;
            if (n <= 0)
            {
                return true;
            }
        }
        return false;
    }
};