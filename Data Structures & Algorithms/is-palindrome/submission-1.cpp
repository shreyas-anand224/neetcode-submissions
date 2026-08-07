class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string newi="";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            newi+=s[i];
        }
        int m=newi.size();
        int l=0,r=m-1;
        while(l<r)
        {
            if(tolower(newi[l])!=tolower(newi[r]))
            return false;
            l++;r--;
        }

        return true;
    }
};
