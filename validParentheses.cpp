class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else if (!st.empty())
            {
                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};
