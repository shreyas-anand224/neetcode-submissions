class Solution {
public:
    bool validPalindrome(string s) {
        int count=0;
        int r=s.size()-1;
        int l=0;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return ispali(s,l+1,r) || ispali(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;

    }
private:
bool ispali(const string&s,int l, int r)
{
    while(l<r)
    {
        if(s[l]!=s[r])
        return false;
        l++;r--;
    }
    return true;
}
};