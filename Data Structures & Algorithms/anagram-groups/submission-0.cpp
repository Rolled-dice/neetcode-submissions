class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // Sorted version as key
            mp[key].push_back(s);          // Group original string under the key
        }
        
        vector<vector<string>> ans;
        for (auto& [_, group] : mp) {
            ans.push_back(group);
        }
        
        return ans;
    }
};
