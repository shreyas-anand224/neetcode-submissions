class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1,m2;
        if(s.length()!=t.length())
        return false;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        bool flag=true;;
        for(auto &it :m1)
        {
            if(m1[it.first] != m2[it.first])
            flag=false;
        }
        return flag;
    }
};
