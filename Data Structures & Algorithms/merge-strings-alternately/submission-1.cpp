class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0,j=0;
        string res="";
        while(i<n && j<m)
        {
            res+=word1[i++];
            res+=word2[j++];
        }
        res+=word1.substr(i);
        res+=word2.substr(j);
        return res;
    }
};