class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index=0;
        for(int i=0;i<t.length();i++)
        {
            if(s[index]==t[i] && index<s.length())
            {
                index++;
                

            }
        }
        return index==s.length();
    }
};