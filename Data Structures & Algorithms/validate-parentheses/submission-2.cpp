class Solution {
public:
    bool isValid(string s) {
        stack<char> a;

        for(char x : s)
        {
            if(x == '(' || x == '{' || x == '[')
            {
                a.push(x);
            }
            else
            {
                if(a.empty())
                    return false;

                if(x == ')' && a.top() != '(')
                    return false;

                if(x == ']' && a.top() != '[')
                    return false;

                if(x == '}' && a.top() != '{')
                    return false;

                a.pop();
            }
        }

        return a.empty();
    }
};