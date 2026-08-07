class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0,j=0;
        bool flag=true;
        string res="";
        while(i<n || j<m)
        {
            if(i<n && j<m)
            {
                if (flag==true)
                {
                    res+=word1[i];
                    i++;
                    flag=false;
                }
                else
                {
                    res+=word2[j];
                        j++;
                    flag=true;
                }
            }
            else if (i<n && j>=m)
            {
                res+=word1[i];
                i++;
            }
            else if (i>=n && j<m)
            {
                res+=word2[j];
                j++;
            }
            
        }
        return res;
    }
};