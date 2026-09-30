class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> counter_map;

        for (int i = 0; i < nums.size(); i++) {
            if (counter_map.find(nums[i]) != counter_map.end())
                return true;
            counter_map[nums[i]] = 1;
        }
        return false;
    }
};