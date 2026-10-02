class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // string -> [0, 0, 1, 2, ..., 0], -> represents that the string have 1 'c' y 2 'd'
        unordered_map<string, vector<int>> smap;
        map<string, int> dupe_map;

        set<vector<int>> groups;
        for (const auto& str : strs) {
            vector<int> lcount(26, 0);  // 26 english letters
            for (const auto& c : str) {
                int i = c - 'a';  // Get number in alpabeth using ascii
                lcount[i] += 1;   // Count presence of char using 26-size array
            }

            // Check duplicated
            if (smap.find(str) != smap.end()) {
                dupe_map[str] += 1;
            }

            smap[str] = lcount;
            groups.insert(lcount);
        }

        // Assign index to each group
        int i = 0;
        map<vector<int>, int> inverse_map;
        vector<vector<string>> ans;
        for (const auto& g : groups) {
            inverse_map[g] = i;
            ans.push_back({});  // Create vector for group
            i++;
        }

        for (const auto& [s, a] : smap) {
            int index = inverse_map[a];
            ans[index].push_back(s);

            // Add dupe strs
            if (dupe_map.find(s) != dupe_map.end()) {
                for (int _ = 0; _ < dupe_map[s]; _++) {
                    ans[index].push_back(s);
                }
            }
        }
        return ans;
    }
};
