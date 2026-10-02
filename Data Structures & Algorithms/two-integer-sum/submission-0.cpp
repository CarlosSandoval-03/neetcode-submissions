class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rm;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int r = target - a;
            
            if (rm.find(a) != rm.end()) {
                return {rm[a], i};
            }

            rm[r] = i;
        }


        return {-1, -1};
    }
};
