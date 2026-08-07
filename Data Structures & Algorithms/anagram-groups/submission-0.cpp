class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
       for(auto &x:strs)
       {
        string temp=x;
        sort(temp.begin(),temp.end());
        res[temp].push_back(x);
       }
       vector<vector<string>> result;
       for(auto &x : res)
       {
        result.push_back(x.second);
       }
       return result;
    }
    
};
