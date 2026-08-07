class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++)
{
    int j=0,m=0;
    string final="";
    while(j<strs[i].length() && m<prefix.length())
    {
        if(strs[i][j]==prefix[m])
       { final=final+strs[i][j];
        j++;
        m++;
       }
       else
       break;
    }
    prefix=final;

}
return prefix;
    }
};